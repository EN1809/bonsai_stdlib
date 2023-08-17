
struct untextured_3d_geometry_buffer
{
  v3 *Verts;
  v4 *Colors;
  v3 *Normals;

  // TODO(Jesse): The fuck are these doing as 32bit?!
  u32 End;
  u32 At;

  u64 Timestamp;
};


untextured_3d_geometry_buffer
ReserveBufferSpace(untextured_3d_geometry_buffer* Reservation, u32 ElementsToReserve)
{
  /* TIMED_FUNCTION(); */
  Assert(ElementsToReserve);

  untextured_3d_geometry_buffer Result = {};

  for (;;)
  {
    umm ReservationAt = Reservation->At;
    umm ReservationRequest = ReservationAt + ElementsToReserve;
    if (ReservationRequest < Reservation->End)
    {
      if ( AtomicCompareExchange(&Reservation->At, (u32)ReservationRequest, (u32)ReservationAt) )
      {
        Result.Verts = Reservation->Verts + ReservationAt;
        Result.Colors = Reservation->Colors + ReservationAt;
        Result.Normals = Reservation->Normals + ReservationAt;
        Result.End = ElementsToReserve;

        break;
      }
    }
    else
    {
      Warn("Failed to reserve buffer space");
      break;
    }
  }

  return Result;
}

link_internal void
DeepCopy(untextured_3d_geometry_buffer *Src, untextured_3d_geometry_buffer *Dest)
{
  umm Count = Src->At;
  Assert(Dest->End >= Count);

  CopyMemory((u8*)Src->Verts,   (u8*)Dest->Verts,   Count*sizeof(v3));
  CopyMemory((u8*)Src->Colors,  (u8*)Dest->Colors,  Count*sizeof(v4));
  CopyMemory((u8*)Src->Normals, (u8*)Dest->Normals, Count*sizeof(v3));

  Dest->At = u32(Count);
  Dest->Timestamp = Src->Timestamp;
}