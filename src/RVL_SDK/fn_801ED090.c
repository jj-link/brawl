#include <revolution/MTX.h>

#define PSVECAdd my_PSVECAdd
#define PSVECScale my_PSVECScale
#define PSVECNormalize my_PSVECNormalize
#define PSVECMag my_PSVECMag
#define PSVECDotProduct fn_801ED090
#define PSVECCrossProduct my_PSVECCrossProduct
#define C_VECHalfAngle my_C_VECHalfAngle
#define PSVECSquareDistance my_PSVECSquareDistance

static void my_PSVECAdd(const Vec* a, const Vec* b, Vec* sum);
static void my_PSVECScale(const Vec* in, Vec* out, f32 scale);
static void my_PSVECNormalize(const Vec* in, Vec* out);
static f32 my_PSVECMag(const Vec* v);
f32 fn_801ED090(const Vec* a, const Vec* b);
static void my_PSVECCrossProduct(const Vec* a, const Vec* b, Vec* prod);
static void my_C_VECHalfAngle(const Vec* a, const Vec* b, Vec* half);
static f32 my_PSVECSquareDistance(const Vec* a, const Vec* b);

#include "../src/revolution/MTX/vec.c"
#pragma force_active on
