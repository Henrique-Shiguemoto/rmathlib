#pragma once

// Type definitions
typedef char i8;
typedef short i16;
typedef int i32;
typedef long int i64;
typedef float f32;
typedef double f64;
typedef _Bool b8;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct v2 {
    f32 x;
    f32 y;
} v2;

typedef struct v3 {
    f32 x;
    f32 y;
    f32 z;
} v3;

typedef struct v4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} v4;

typedef struct mat2x2 {
    f32 elem[4];
} mat2x2;

typedef struct mat3x3 {
    f32 elem[9];
} mat3x3;

typedef struct mat4x4 {
    f32 elem[16];
} mat4x4;

typedef v2 point2D;
typedef v3 point3D;
typedef v4 quaternion;

typedef struct lineSegment2D {
    point2D start;
    point2D end;
} lineSegment2D;

typedef struct line2D {
    v2 direction;
    point2D arbitraryPoint;
} line2D;

typedef struct triangle2D {
    point2D a;
    point2D b;
    point2D c;
} triangle2D;

// It's important to be consistent with the order of the vertices. The user can only use either 
//      clockwise or anticlockwise ordering for vertices. Some of the functions used for this struct
//      can give you different results if you don't use these orders.
// Same thing applies to quad3D.
typedef struct quad2D {
    point2D a;
    point2D b;
    point2D c;
    point2D d;
} quad2D;


/**
 * 
 * Functions with this structure as parameter assumes the following
 *      (These assumptions are also analogous to AABB3D):
 * 
 * For y-is-up scenarios:
 *                              ^  (max4)
 *                              |            (max3)
 *                              |
 *                              |
 *        (min4)                |  (min3)
 *                              |
 *                              |        (max2)
 *        --------------------- 0 --------------------->
 *                     (max1)   |
 *                              |    (min2)
 *                              |
 *                 (min1)       |
 *                              |
 *                              |
 * - min.x and min.y are below and to the left of max.x and max.y
 * - min.x != max.x and min.y != max.y (so that AABBs don't determine a line segment)
 * 
 * 
 * For y-is-down scenarios:
 *                              |
 *                              |
 *                              |
 *                              |
 *        (min1)                |  (min2)
 *                              |
 *                              |        (max2)
 *        --------------------- 0 --------------------->
 *                   (min3)     |
 *                              |    (min4)
 *                              |
 *                              |               (max4)
 *                              |  (max1)
 *                       (max3) |
 *                              v
 * 
 * - min.x and min.y are up and to the left of max.x and max.y
 * - min.x != max.x and min.y != max.y (so that AABBs don't determine a line segment)
 * 
 * */ 
typedef struct AABB2D {
    point2D min;
    point2D max;
} AABB2D;

// REFACTOR: rename function (just call it a circle)
typedef struct sphere2D {
    point2D center;
    f32 radius;
} sphere2D;

typedef struct lineSegment3D {
    point3D start;
    point3D end;
} lineSegment3D;

typedef struct line3D {
    v3 direction;
    point3D arbitraryPoint;
} line3D;

typedef struct triangle3D {
    point3D a;
    point3D b;
    point3D c;
} triangle3D;

typedef struct quad3D {
    point3D a;
    point3D b;
    point3D c;
    point3D d;
} quad3D;

typedef struct plane {
    v3 normal;
    point3D arbitraryPoint;
} plane;

typedef struct AABB3D {
    point3D min;
    point3D max;
} AABB3D;

typedef struct sphere3D {
    point3D center;
    f32 radius;
} sphere3D;

#define MTHLIB_INFINITY ((f32)(1e+300)*(1e+300))
#define MTHLIB_NAN (((f32)(1e+300)*(1e+300))*(0.0f))
#define MTHLIB_U32_MAX 4294967295
#define MTHLIB_PI 3.141592653589793
#define MTHLIB_DEGREE_IN_RAD (MTHLIB_PI/180)
#define MTHLIB_SQRT_2 1.414213562373095
#define MTHLIB_SQRT_3 1.732050807568877
#define MTHLIB_LOW_PRECISION 0.00001
#define MTHLIB_HIGH_PRECISION 0.0000000001
#define MTHLIB_BIAS32 127
#define MTHLIB_BIAS64 1023
#define MTHLIB_TRUE 1
#define MTHLIB_FALSE 0
#define MTHLIB_INVALID_V2 (v2) {MTHLIB_NAN, MTHLIB_NAN}
#define MTHLIB_INVALID_V3 (v3) {MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN}
#define MTHLIB_INVALID_V4 (v4) {MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN}
#define MTHLIB_INVALID_2X2MATRIX (mat2x2) \
                                {.elem = \
                                {MTHLIB_NAN, MTHLIB_NAN, \
                                 MTHLIB_NAN, MTHLIB_NAN}}
#define MTHLIB_INVALID_3X3MATRIX (mat3x3) \
                                {.elem = \
                                {MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, \
                                 MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, \
                                 MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN}}
#define MTHLIB_INVALID_4X4MATRIX (mat4x4) \
                                {.elem = \
                                {MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, \
                                 MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, \
                                 MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, \
                                 MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN, MTHLIB_NAN}}

f64 GetPlatformTime();

// Vector Operations

v2 AddV2(v2 u, v2 v);
v2 SubtractV2(v2 u, v2 v);
v2 ScaleV2(v2 u, f32 scalar);
f64 DotV2(v2 u, v2 v);
f64 NormV2(v2 u);
v2 UnitV2(v2 u);
b8 CompareV2(v2 u, v2 v, f32 errorMargin);

v3 AddV3(v3 u, v3 v);
v3 SubtractV3(v3 u, v3 v);
v3 ScaleV3(v3 u, f32 scalar);
f64 DotV3(v3 u, v3 v);
v3 CrossV3(v3 u, v3 v);
f64 NormV3(v3 u);
v3 UnitV3(v3 u);
b8 CompareV3(v3 u, v3 v, f32 errorMargin);
v2 ConvertV3ToV2(v3 u);
f64 ScalarTripleProduct(v3 a, v3 b, v3 c);

v4 AddV4(v4 u, v4 v);
v4 SubtractV4(v4 u, v4 v);
v4 ScaleV4(v4 u, f32 scalar);
f64 DotV4(v4 u, v4 v);
f64 NormV4(v4 u);
v4 UnitV4(v4 u);
b8 CompareV4(v4 u, v4 v, f32 errorMargin);
v3 ConvertV4ToV3(v4 u);

//Matrix Operations

mat2x2 AddMatrix2x2(mat2x2 m1, mat2x2 m2);
mat2x2 SubMatrix2x2(mat2x2 m1, mat2x2 m2);
mat2x2 ScalarMultMatrix2x2(f64 scalar, mat2x2 m1);
mat2x2 MultMatrix2x2(mat2x2 m1, mat2x2 m2);
f32 DetMatrix2x2(mat2x2 m1);
mat2x2 TransposeMatrix2x2(mat2x2 m1);
mat2x2 InverseMatrix2x2(mat2x2 m1);
v2 MultV2ByMatrix2x2(v2 u, mat2x2 m1);
mat2x2 CreateIdentity2x2();
b8 CompareMat2x2(mat2x2 m1, mat2x2 m2, f32 errorMargin);

mat3x3 AddMatrix3x3(mat3x3 m1, mat3x3 m2);
mat3x3 SubMatrix3x3(mat3x3 m1, mat3x3 m2);
mat3x3 ScalarMultMatrix3x3(f64 scalar, mat3x3 m1);
mat3x3 MultMatrix3x3(mat3x3 m1, mat3x3 m2);
f32 DetMatrix3x3(mat3x3 m1);
mat3x3 TransposeMatrix3x3(mat3x3 m1);
mat3x3 InverseMatrix3x3(mat3x3 m1);
v3 MultV3ByMatrix3x3(v3 u, mat3x3 m1);
mat3x3 CreateIdentity3x3();
b8 CompareMat3x3(mat3x3 m1, mat3x3 m2, f32 errorMargin);

mat4x4 AddMatrix4x4(mat4x4 m1, mat4x4 m2);
mat4x4 SubMatrix4x4(mat4x4 m1, mat4x4 m2);
mat4x4 ScalarMultMatrix4x4(f64 scalar, mat4x4 m1);
mat4x4 MultMatrix4x4(mat4x4 m1, mat4x4 m2);
f32 DetMatrix4x4(mat4x4 m1);
mat4x4 TransposeMatrix4x4(mat4x4 m1);
mat4x4 InverseMatrix4x4(mat4x4 m1);
v4 MultV4ByMatrix4x4(v4 u, mat4x4 m1);
mat4x4 CreateIdentity4x4();
b8 CompareMat4x4(mat4x4 m1, mat4x4 m2, f32 errorMargin);

//Trig Functions

f32 Sin32(f32 angleInRadians);
f32 Cos32(f32 angleInRadians);
f32 Tg32(f32 angleInRadians);
f32 Cosec32(f32 angleInRadians);
f32 Sec32(f32 angleInRadians);
f32 Cotg32(f32 angleInRadians);
f64 Sin64(f64 angleInRadians);
f64 Cos64(f64 angleInRadians);
f64 Tg64(f64 angleInRadians);
f64 Cosec64(f64 angleInRadians);
f64 Sec64(f64 angleInRadians);
f64 Cotg64(f64 angleInRadians);

//Other convenient functions

b8 Compare32(f32 x, f32 y, f32 errorMargin);
f32 DegreesToRadians32(f32 degrees);
f32 RadiansToDegrees32(f32 radians);
f32 Sqrt32(f32 x);
f32	Abs32(f32 x);
f32 Clamp32(f32 min, f32 max, f32 value);
f32	Max32(f32 a, f32 b);
f32	Min32(f32 a, f32 b);

/**
 * 
 * RETURNS THE REMAINDER OF f1 WHEN DIVIDED BY f2 WITH 32 BIT FLOAT RETURN
 * 		IF positiveResult = TRUE, THEN THE RETURN VALUE WILL ALWAYS BE POSITIVE OR 0
 * 		OTHERWISE THE RETURN VALUES COULD BE NEGATIVE
 * 
 * */

f32 Mod32(f32 f1, f64 f2, u8 positiveResult);
i32 Ceil32(f32 x);
i32 Floor32(f32 x);
i32 Round32(f32 x);

b8 Compare64(f64 x, f64 y, f64 errorMargin);
f64 DegreesToRadians64(f64 degrees);
f64 RadiansToDegrees64(f64 radians);
f64	Sqrt64(f64 x);
f64	Abs64(f64 x);
f64 Clamp64(f64 min, f64 max, f64 value);
f64	Max64(f64 a, f64 b);
f64	Min64(f64 a, f64 b);

/**
 * 
 * RETURNS THE REMAINDER OF f1 WHEN DIVIDED BY f2 WITH 64 BIT FLOAT RETURN
 * 		IF positiveResult = TRUE, THEN THE RETURN VALUE WILL ALWAYS BE POSITIVE OR 0
 * 		OTHERWISE THE RETURN VALUES COULD BE NEGATIVE
 * 
 * */

f64 Mod64(f64 f1, f64 f2, u8 positiveResult);
i64 Ceil64(f64 x);
i64 Floor64(f64 x);
i64 Round64(f64 x);
i8 Sign(f64 x);

//RANDOM FUNCTIONS

u32 RandomU32(void);
u32 RandomU32InInterval(u32 min, u32 max);
b8 RandomBool(void);
i8 RandomSign(void);
f32 Random32(void);                 // returns f32 from 0.0f to 1.0f
v2 RandomV2(void);                  // elements are from 0.0f to 1.0f
v3 RandomV3(void);                  // elements are from 0.0f to 1.0f
v4 RandomV4(void);                  // elements are from 0.0f to 1.0f
mat2x2 RandomMat2x2(void);          // elements are from 0.0f to 1.0f
mat3x3 RandomMat3x3(void);          // elements are from 0.0f to 1.0f
mat4x4 RandomMat4x4(void);          // elements are from 0.0f to 1.0f

//GRAPHICS FUNCTIONS

mat3x3 CreateTranslationMatrix2D(v2 posDelta);
mat3x3 CreateScaleMatrixWithSetOrigin2D(v2 scale, v2 origin);
mat3x3 CreateScaleMatrix2D(v2 scale);
mat3x3 CreateRotationAroundPointMatrix2D(f32 angleInRadians, v2 pos);
mat3x3 CreateRotationMatrix2D(f32 angleInRadians);

mat4x4 CreateTranslationMatrix3D(v3 posDelta);
mat4x4 CreateScaleMatrix3D(v3 scale);
mat4x4 CreateEulerRotationInXMatrix3D(f32 angleInRadians);
mat4x4 CreateEulerRotationInYMatrix3D(f32 angleInRadians);
mat4x4 CreateEulerRotationInZMatrix3D(f32 angleInRadians);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH ROTATES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN ALL THE AXIS
 *      (AXIS HIERARCHY IS X => Y => Z, Z IS THE MOST SIGNIFICANT)
 * 
 * */
mat4x4 CreateEulerRotationInXYZMatrix3D(v3 anglesInRadians);
mat4x4 CreateParallelProjectionMatrix3D(f32 l, f32 r, f32 t, f32 b, f32 f, f32 n);
mat4x4 CreatePerspectiveProjectionMatrix3D(f32 fovY, f32 aspectRatio, f32 f, f32 n);

// GEOMETRY FUNCTIONS

f32 DistanceBetweenPoints2D(point2D p, point2D q);
f32 DistanceBetweenPoints3D(point3D p, point3D q);
f32 DistanceBetweenPointAndLine2D(point2D p, line2D line);
f32 DistanceBetweenLines2D(line2D line1, line2D line2);
f32 DistanceBetweenPointAndLine3D(point3D p, line3D line);
f32 DistanceBetweenLines3D(line3D line1, line3D line2);
f32 DistanceBetweenPointAndPlane(point3D p, plane pl);
f32 DistanceBetweenLineAndPlane(line3D line, plane pl);
f32 DistanceBetweenPlanes(plane pl1, plane pl2);

b8 ParallelLines2D(line2D l1, line2D l2);
b8 ParallelLines3D(line3D l1, line3D l2);
b8 IntersectingLines2D(line2D l1, line2D l2);
b8 IntersectingLines3D(line3D l1, line3D l2);
b8 SkewLines(line3D l1, line3D l2);

b8 CollisionAABB2D(AABB2D r1, AABB2D r2);
b8 CollisionPointAndAABB2D(point2D p, AABB2D r);
b8 CollisionPointAndSphere2D(point2D p, sphere2D s);
b8 CollisionSphere2D(sphere2D s1, sphere2D s2);
b8 CollisionAABB3D(AABB3D r1, AABB3D r2);
b8 CollisionPointAndAABB3D(point3D p, AABB3D r);
b8 CollisionPointAndSphere3D(point3D p, sphere3D s);
b8 CollisionSphere3D(sphere3D s1, sphere3D s2);

f32 AreaTriangle2D(triangle2D triangle);
f32 AreaSphere2D(sphere2D sphere);
f32 AreaAABB2D(AABB2D aabb);
f32 AreaQuad2D(quad2D quad);
f32 PerimeterSphere2D(sphere2D sphere);
f32 PerimeterAABB2D(AABB2D aabb);
f32 PerimeterQuad2D(quad2D quad);
f32 PerimeterTriangle2D(triangle2D triangle);
f32 AreaTriangle3D(triangle3D triangle);
f32 AreaQuad3D(quad3D quad);
f32 VolumeSphere3D(sphere3D sphere);
f32 VolumeAABB3D(AABB3D aabb);
f32 PerimeterTriangle3D(triangle3D triangle);
f32 SurfaceAreaSphere3D(sphere3D sphere);
f32 SurfaceAreaAABB3D(AABB3D aabb);

// ------------------------------------------------------------------

lineSegment2D AddLineSegment2D(lineSegment2D l1, lineSegment2D l2);
lineSegment2D SubtractLineSegment2D(lineSegment2D l1, lineSegment2D l2);
b8 LineSegment2DIsNull(lineSegment2D l);
b8 LineSegments2DAreOpposite(lineSegment2D l1, lineSegment2D l2);
b8 LineSegments2DHaveEqualLength(lineSegment2D l1, lineSegment2D l2);
b8 LineSegments2DAreParallel(lineSegment2D l1, lineSegment2D l2);
b8 LineSegments2DHaveOppositeDirection(lineSegment2D l1, lineSegment2D l2);

lineSegment3D AddLineSegment3D(lineSegment3D l1, lineSegment3D l2);
lineSegment3D SubtractLineSegment3D(lineSegment3D l1, lineSegment3D l2);
b8 LineSegment3DIsNull(lineSegment3D l);
b8 LineSegments3DAreOpposite(lineSegment3D l1, lineSegment3D l2);
b8 LineSegments3DHaveEqualLength(lineSegment3D l1, lineSegment3D l2);
b8 LineSegments3DAreParallel(lineSegment3D l1, lineSegment3D l2);
b8 LineSegments3DHaveOppositeDirection(lineSegment3D l1, lineSegment3D l2);