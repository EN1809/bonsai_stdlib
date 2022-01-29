bonsai_function b32
CloseFile(native_file* File)
{
  b32 Result = False;
  if (File->Handle)
  {
    Result = fclose(File->Handle) == 0 ? True : False;
    File->Handle = 0;
  }
  else
  {
    Error("Attempted to close %S, which was not open.", File->Path);
  }

  if (!Result)
  {
    Error("Closing file %S", File->Path);
  }

  Assert(File->Handle == 0);
  return Result;
}

global_variable random_series TempFileEntropy = {3215432};

bonsai_function b32
Rename(counted_string CurrentFilePath, counted_string NewFilePath)
{
  counted_string TmpFilename = {};
  if (FileExists(NewFilePath))
  {
    TmpFilename = GetTmpFilename(&TempFileEntropy, TranArena);
    Rename(NewFilePath, TmpFilename);
  }


  const char* Old = GetNullTerminated(CurrentFilePath);
  const char* New = GetNullTerminated(NewFilePath);
  b32 Result = (rename(Old, New) == 0);

  if (Result)
  {
    if (TmpFilename.Count)
    {
      Remove(TmpFilename);
    }
  }
  else
  {
    Info("Error renaming %S -> %S , errno(%d)", CurrentFilePath, NewFilePath, errno);
    if (TmpFilename.Count)
    {
      Rename(TmpFilename, NewFilePath);
    }
  }

  return Result;
}

bonsai_function b32
Remove(counted_string Filepath)
{
  const char* NullTerminated = GetNullTerminated(Filepath);
  b32 Result = (remove(NullTerminated) == 0) ? True : False;
  return Result;
}

bonsai_function native_file
OpenFile(const char* FilePath, const char* Permissions)
{
  native_file Result = {
    .Path = CS(FilePath)
  };

  errno = 0;
  fopen_s(&Result.Handle, FilePath, Permissions);

  if (!Result.Handle)
  {
    switch(errno)
    {
      case EINVAL:
      {
        Error("Invalid Permissions string (%s) provided to OpenFile.", Permissions);
      } break;

      default:
      {
        /* Error("Error opening File %s. (Errno==(%d))", FilePath, errno); */
      } break;
    }

    errno = 0;
  }

  Assert(errno == 0);

  return Result;
}

bonsai_function native_file
OpenFile(counted_string FilePath, const char* Permissions)
{
  const char* NullTerminatedFilePath = GetNullTerminated(FilePath);
  native_file Result = OpenFile(NullTerminatedFilePath, Permissions);
  return Result;
}

bonsai_function counted_string
GetRandomString(u32 Length, random_series* Entropy, memory_arena* Memory)
{
  counted_string Filename = {
    .Count = Length,
    .Start = Allocate(char, Memory, Length),
  };

  for (u32 CharIndex = 0;
      CharIndex < Length;
      ++CharIndex)
  {
    s8 Try = (s8)RandomBetween(48, Entropy, 122);
    while (!IsAlphaNumeric(Try))
    {
      Try = (s8)RandomBetween(48, Entropy, 122);
    }
    ((char*)Filename.Start)[CharIndex] = Try;
  }

  return Filename;
}

bonsai_function counted_string
GetRandomString(u32 Length, umm EntropySeed, memory_arena* Memory)
{
  random_series Entropy = { .Seed = EntropySeed };
  counted_string Result = GetRandomString(Length, &Entropy, Memory);
  return Result;
}

bonsai_function counted_string
GetTmpFilename(random_series* Entropy, memory_arena* Memory)
{
  counted_string Filename = GetRandomString(32, Entropy, Memory);
  Filename = Concat(CS("tmp/"), Filename, Memory);
  return Filename;
}

bonsai_function native_file
GetTempFile(random_series* Entropy, memory_arena* Memory)
{
  counted_string Filename = GetTmpFilename(Entropy, Memory);
  native_file Result = OpenFile(Filename, "w+b");
  if (!Result.Handle)
    { Error("Opening File %S, errno: %d", Filename, errno); }
  return Result;
}

bonsai_function inline b32
WriteToFile(native_file* File, counted_string Str)
{
  b32 Result = False;
  umm BytesWriten = fwrite(Str.Start, 1, Str.Count, File->Handle);
  if (BytesWriten == Str.Count)
  {
    Result = True;
  }
  else
  {
    Error("Writing to file %.*s", (s32)File->Path.Count, File->Path.Start);
  }
  return Result;
}

bonsai_function inline b32
WriteToFile(native_file* File, ansi_stream *Str)
{
  b32 Result = WriteToFile(File, CountedString(Str));
  return Result;
}

bonsai_function void
ReadBytesIntoBuffer(FILE *Src, u64 BytesToRead, u8* Dest)
{
  Assert(BytesToRead);
  u64 BytesRead = fread(Dest, 1, BytesToRead, Src);
  Assert(BytesRead != 0);
  return;
}

bonsai_function b32
FileExists(const char* Path)
{
  b32 Result = False;

  native_file File = OpenFile(Path, "r");
  if (File.Handle)
  {
    Result = True;
    if (!CloseFile(&File))
    {
      Error("Opened %s, but could not close it.", Path);
      Result = False;
    }
  }

  return Result;
}

bonsai_function b32
FileExists(counted_string Path)
{
  const char* NullTerminatedFilePath = GetNullTerminated(Path);
  b32 Result = FileExists(NullTerminatedFilePath);
  return Result;
}

bonsai_function void
PrintToStdout(counted_string Output)
{
  if (!WriteToFile(&Stdout, Output))
  {
    Error("Writing to Stdout");
  }

#if BONSAI_WIN32
  OutputDebugString(GetNullTerminated(Output));
#endif

}

