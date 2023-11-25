union Quaternion
{
  float E[4];

  struct { r32 x; r32 y; r32 z; r32 w; };
  struct { v3 xyz; r32 _ignored; };

  Quaternion(void)
  {
    Clear(this);
  }

  Quaternion( v3 Vec, r32 W )
  {
    this->x = Vec.x;
    this->y = Vec.y;
    this->z = Vec.z;
    this->w = W;
  }

  Quaternion( r32 X, r32 Y, r32 Z, r32 W )
  {
    this->x = X;
    this->y = Y;
    this->z = Z;
    this->w = W;
  }
};

Quaternion
operator*(Quaternion A, Quaternion B)
{
  Quaternion Result = {};

  Result.w = A.w*B.w - A.x*B.x - A.y*B.y - A.z*B.z;
  Result.x = A.w*B.x + A.x*B.w + A.y*B.z - A.z*B.y;
  Result.y = A.w*B.y + A.y*B.w + A.z*B.x - A.x*B.z;
  Result.z = A.w*B.z + A.z*B.w + A.x*B.y - A.y*B.x;

  return Result;
}

inline r32
GetTheta(v3 P1, v3 P2)
{
  r32 DotP1P2 = Dot(P1,P2);

  r32 LP1 = Length(P1);
  r32 LP2 = Length(P2);


  r32 Theta = 0.f;
  if (LP1 == 0.f || LP2 == 0.f)
  {
    // Fundamentally, if either point is 0, getting a theta mesurement between
    // that and another point is undefined, so we just return 0
  }
  else
  {
    Assert(LP1 != 0.0f);
    Assert(LP2 != 0.0f);
    r32 cosTheta = ClampBilateral(DotP1P2 / (LP1*LP2));
    Theta = (r32)ArcCos( cosTheta );
  }

  return Theta;
}

// NOTE(Jesse): Euler angles in radians
// https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
link_internal Quaternion
FromEuler(v3 Euler)
{
  Quaternion Result;

  f32 cr = Cos(Euler.x * 0.5f);
  f32 sr = Sin(Euler.x * 0.5f);
  f32 cp = Cos(Euler.y * 0.5f);
  f32 sp = Sin(Euler.y * 0.5f);
  f32 cy = Cos(Euler.z * 0.5f);
  f32 sy = Sin(Euler.z * 0.5f);

  Result.w = cr * cp * cy + sr * sp * sy;
  Result.x = sr * cp * cy - cr * sp * sy;
  Result.y = cr * sp * cy + sr * cp * sy;
  Result.z = cr * cp * sy - sr * sp * cy;

  return Result;
}

inline Quaternion
RotatePoint(v3 P1, v3 P2)
{
  P1 = Normalize(P1);
  P2 = Normalize(P2);
  v3 Axis = Normalize(Cross(P1, P2));

  r32 Theta = GetTheta(P1, P2);

  Quaternion Result = Quaternion((Axis*(r32)Sin(Theta/2.0f)), (r32)Cos(Theta/2.0f));

  if (Length(Result.xyz) == 0)  // The resulting rotation was inconsequential
    Result = Quaternion();

  return Result;
}

inline Quaternion
Conjugate( Quaternion q )
{
  Quaternion Result = {-q.x, -q.y, -q.z, q.w};
  return Result;
}


inline v3
Rotate(v3 P, Quaternion Rotation)
{
  v3 Result = ((Rotation * Quaternion(P,0)) * Conjugate(Rotation)).xyz;
  return Result;
}

inline line
Rotate(line Line, Quaternion Rotation)
{
  line Result;

  Result.MinP = Rotate(Line.MinP, Rotation);
  Result.MaxP = Rotate(Line.MaxP, Rotation);

  return Result;
}

inline v3
RandomRotation(random_series *Entropy)
{
  v3 Result = RandomV3(Entropy);
  return Result;
}

inline Quaternion
RandomQuaternion(random_series *Entropy)
{
  v3 RotP = {};
  RotP.x = Sin(RandomUnilateral(Entropy));
  RotP.y = Sin(RandomUnilateral(Entropy));
  RotP.z = Sin(RandomUnilateral(Entropy));

  Quaternion Result = RotatePoint(V3(0.f, -1.f, 0.f), RotP);
  return Result;
}

