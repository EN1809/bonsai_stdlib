#define BONSAI_FAST_MATH__INVSQRT (1)
#define BONSAI_FAST_MATH__SQRT (1)
#define BONSAI_FAST_MATH__ARCCOS (1)
#define BONSAI_FAST_MATH__COS (1)
#define BONSAI_FAST_MATH__FLOORF (1)
#define BONSAI_FAST_MATH__CEILF (1)

link_inline f32 Cos(f32 x);

poof(vector_interpolation_functions(f32))
#include <generated/gen_lerp_f32.h>

inline u64
Abs(s64 Int)
{
  u64 Result = (u64)(Int < 0 ? -Int : Int);
  return Result;
}

inline u32
Abs(s32 Int)
{
  u32 Result = (u32)(Int < 0 ? -Int : Int);
  return Result;
}

inline r64
Abs(r64 F)
{
  r64 Result = F;
  Result = Result < 0 ? -Result : Result;
  return Result;
}

inline r32
Abs(r32 F)
{
  r32 Result = F;
  Result = Result < 0 ? -Result : Result;
  return Result;
}


// TODO(Jesse): Can we do this without converting to integer to avoid overflow?
// And/or do we care?
link_internal r32
Truncate(r32 Input)
{
  s32 Truncated = s32(Input);
  r32 Result = r32(Truncated);
  return Result;
}

link_internal f32
Mod(f32 Dividend, f32 Divisor)
{
  return Dividend - Truncate(Dividend / Divisor) * Divisor;
}

link_internal umm
SafeDecrement(umm *N)
{
  umm Result = *N;
  if (Result > 0)
  {
    Result -= 1;
  }
  return Result;
}

inline u64
SaturatingAdd(u64 N)
{
  if (N < u64_MAX) { N = N+1; }
  return N;
}

inline u64
Desaturate(u64 Target, u64 SubValue)
{
  if (Target >= SubValue ) { Target = Target-SubValue; } else { Target = 0; }
  return Target;
}

inline u64
SaturatingSub(u64 N)
{
  if (N) { N = N-1; }
  return N;
}

inline umm
RoundUp(umm N, umm Thresh)
{
  umm Result = N;

  umm Mod = N % Thresh;
  if (Mod) { Result += (Thresh-Mod); }

  return Result;
}

f32 Fract(f32 v)
{
  f32 Result = v - Truncate(v);
  return Result;
}

inline r32
Round(r32 N)
{
  r32 Result;

  // TODO(Jesse): Make sure this is more-or-less correct
  NotImplemented;

  f32 NFract = Fract(N);
  if (NFract > 0.5f)
  {
    Result = N + (1.f-NFract);
  }
  else
  {
    Result = N - NFract;
  }
  return Result;
}

inline r32
ModToThresh(r32 N, s32 Thresh)
{
  s32 Ni = s32(N);
  f32 Result = f32( Ni % Thresh );
  return Result;
}

inline r32
Pow(r32 N, int Exp)
{
  r32 Result = N;
  RangeIterator(i, Exp)
  {
    Result *= N;
  }
  return Result;
}


// https://github.com/AZHenley/cosine/blob/master/cosine.c
link_inline f32
Cos(f32 x)
{
#if BONSAI_FAST_MATH__COS

#if 0
  return _mm_cvtss_f32(_mm_cos_ps(_mm_set_ps1(x)));
#endif

#if 1
  f32 xAbs = Abs(x);
  f32 xMod = Mod(xAbs, 2.f*PI32);
  f32 i = xMod * 1000.f;
  s32 index = s32(i);
  r32 Result = Lerp(i - index,
                    costable_0_001[index],
                    costable_0_001[index + 1] );
#endif

#else  // BONSAI_FAST_MATH__COS
  r32 Result = (r32)cos(double(x));
#endif // BONSAI_FAST_MATH__COS

  return Result;
}

// TODO(Jesse): Is this accurate enough?  Probably..
inline r32
Sin(r32 Theta)
{
  r32 Result = Cos(Theta-(PI32/2.f));
  return Result;
}

inline r64
SafeDivide0(u64 Dividend, u64 Divisor)
{
  r64 Result = 0.0;
  if (Divisor != 0)
    Result = (r64)Dividend/(r64)Divisor;
  return Result;
}

inline r64
SafeDivide0(r64 Dividend, r64 Divisor)
{
  r64 Result = 0.0;
  if (Divisor != 0.0)
    Result = Dividend/Divisor;
  return Result;
}

inline r32
SafeDivide0(r32 Dividend, r32 Divisor)
{
  r32 Result = 0.0f;

  if (Divisor != 0.0f)
    Result = Dividend/Divisor;

  return Result;
}

inline r64
Min(r64 A, r64 B)
{
  r64 Result = A < B ? A : B;
  return Result;
}

inline r32
Min(r32 A, r32 B)
{
  r32 Result = A < B ? A : B;
  return Result;
}

inline u64
Min(u64 A, u64 B)
{
  u64 Result = A < B ? A : B;
  return Result;
}

inline u32
Min(u32 A, u32 B)
{
  u32 Result = A < B ? A : B;
  return Result;
}

inline s32
Min(s32 A, s32 B)
{
  s32 Result = A < B ? A : B;
  return Result;
}

inline r64
Max(r64 A, r64 B)
{
  r64 Result = A > B ? A : B;
  return Result;
}

inline r32
Max(r32 A, r32 B)
{
  r32 Result = A > B ? A : B;
  return Result;
}

inline u32
Max(u32 A, u32 B)
{
  u32 Result = A > B ? A : B;
  return Result;
}

inline u64
Max(u64 A, u64 B)
{
  u64 Result = A > B ? A : B;
  return Result;
}

inline s32
Max(s32 A, s32 B)
{
  s32 Result = A > B ? A : B;
  return Result;
}

int
Pow2(int p)
{
  int Result = 1 << p;
  return Result;
}

inline float
ClampMinus1toInfinity( float f )
{
  float Result = f;

  if (Result < -1 )
  {
    Result = -1;
  }

  return Result;
}

inline r32
ClampMin(r32 Value, r32 Min)
{
  if (Value < Min) { Value = Min; }
  return Value;
}

inline r32
ClampMax(r32 Value, r32 Max)
{
  if (Value > Max) { Value = Max; }
  return Value;
}

inline r32
ClampBetween(r32 Min, r32 Value, r32 Max)
{
  if (Value > Max) { Value = Max; }
  if (Value < Min) { Value = Min; }
  return Value;
}

poof(
  func scalar_math_fuctions(type_poof_symbol scalar_types)
  {
    scalar_types.map(scalar)
    {
      inline scalar.name
      Clamp( scalar.name Min, scalar.name Value, scalar.name Max )
      {
        if (Value > Max) { Value = Max; }
        if (Value < Min) { Value = Min; }
        return Value;
      }
    }
  }
)

poof(scalar_math_fuctions({r32 r64 u32 u64 s32 s64}))
#include <generated/scalar_math_fuctions_451039071.h>

inline r32
ClampBilateral(r32 F)
{
  r32 Result = ClampBetween(-1.0f, F, 1.0f);
  return Result;
}

inline r32
Clamp01(r32 Value)
{
  Value = ClampBetween(0.f, Value, 1.f);
  return Value;
}

s32
clamp0(s32 i)
{
  if (i < 0)
    i = 0;

  return i;
}

s32
Floori(r32 f)
{
  s32 Result;
  Result = (s32)(f);
  return Result;
}

u32
Floorfu(r32 f)
{
  if (f < 0) { f -= 1.f; }
  u32 Result = u32(f);
  return Result;
}

r32
Floorf(r32 f)
{
#if BONSAI_FAST_MATH__FLOORF
  f32 Result;
  if (f < 0.f)
  {
    Result = Truncate(f) -1.f;
  }
  else
  {
    Result = Truncate(f);
  }

  return Result;
#else
  f32 Result = f32(floor(double(f)));
  return Result;
#endif
}

r32
Ceilf(r32 f)
{
#if BONSAI_FAST_MATH__CEILF

  f32 Result;
  if (f < 0.f)
  {
    Result = Truncate(f);
  }
  else
  {
    Result = Truncate(f) + 1.f;
  }


  return Result;
#else
  r32 Result = (r32)ceil(double(f));
  return Result;
#endif
}

s32
Ceil(r32 F)
{
  s32 Result = (s32)Ceilf(F);
  return Result;
}

inline u32
Square( u32 f )
{
  u32 Result = f*f;
  return Result;
}

inline s32
Square( s32 f )
{
  s32 Result = f*f;
  return Result;
}

inline r32
Square( r32 f )
{
  r32 Result = f*f;
  return Result;
}

link_inline  f32
InverseSquareRoot(f32 x)
{
#if BONSAI_FAST_MATH__INVSQRT 
  return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ps1(x)));
#else
  NotImplemented;
#endif
}

link_inline r32
SquareRoot(r32 F)
{
#if BONSAI_FAST_MATH__SQRT 
  r32 Result = InverseSquareRoot(F) * F;
  return Result;
#else
  NotImplemented;
#endif
}

inline r32
ArcCos(r32 x)
{
#if BONSAI_FAST_MATH__ARCCOS

#if 0
   return (-0.69813170079773212f * x * x - 0.87266462599716477f) * x + 1.5707963267948966f;
#endif

#if 1
  float negate = float(x < 0);
  x = abs(x);
  float ret = -0.0187293f;
  ret = ret * x;
  ret = ret + 0.0742610f;
  ret = ret * x;
  ret = ret - 0.2121144f;
  ret = ret * x;
  ret = ret + 1.5707288f;
  ret = ret * SquareRoot(1.f-x);
  ret = ret - 2.f * negate * ret;
  return negate * PI32 + ret;
#endif

#if 0
  return _mm_cvtss_f32(_mm_acos_ps(_mm_set_ps1(x)));
#endif

#else
  r32 Theta = (r32)acos((double)x);
  return Theta;
#endif
}


enum sign { Negative = -1, Zero = 0, Positive = 1 };

inline sign
Bilateral( s32 f )
{
  sign Result = Positive;
  if ( f < 0 ) { Result = Negative; }
  return Result;
}

inline sign
Bilateral( r32 f )
{
  sign Result = Positive;
  if ( f < 0.f ) { Result = Negative; }
  return Result;
}

inline sign
GetSign( s32 f )
{
  sign Result = Zero;

  if ( f > 0 )
  {
    Result = Positive;
  }
  else if ( f < 0 )
  {
    Result = Negative;
  }

  return Result;
}

inline sign
GetSign( r32 f )
{
  sign Result = Zero;

  if ( f > 0.0f )
  {
    Result = Positive;
  }
  else if ( f < 0.0f )
  {
    Result = Negative;
  }

  return Result;
}
