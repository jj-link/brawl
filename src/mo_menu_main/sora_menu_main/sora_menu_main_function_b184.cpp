#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_common.h>
#pragma force_active on
#pragma fp_contract off
struct Vec3 { float x; float y; float z; };
struct Vec2 { float x; float z; };
struct Matrix { float m[3][4]; };
struct Flags { unsigned char active : 1; unsigned char rest : 7; };
extern "C" {
extern const float lbl_2_rodata_218[];
Matrix fn_2_A618(void*, s32);
void fn_8003E6DC(const Matrix*, Vec3*);
void* fn_8018EED0(void*, s32);
s32 fn_8018EF78(void*, void*);
void fn_801926D8(void*, void*, void*, void*);
void fn_80192744(void*, void*, void*);
}
static inline float outside(float sx, float ex, float sz, float ez, const Vec2& pos, Vec2& d, Vec2& o) {
 float dz = ez - sz;
 float px = pos.x - sx;
    d.z = dz;
 o.x = -(pos.z - sz);
 d.x = ex - sx;
 o.z = px;
 return d.x * (float)(double)o.x + dz * px;
}
static inline float outsideMid(float sx, float ex, float sz, float ez, const Vec2& pos, Vec2& d, Vec2& o) {
 float dz = ez - sz;
 float px = pos.x - sx;
 d.z = dz;
 sx = ex - sx;
 d.x = sx;
 sz = -(pos.z - sz);
 o.x = sz;
 o.z = px;
 return d.x * (float)(double)o.x + dz * px;
}
#define CHECK_SEGMENT(s, e, d, o, q) \
{ \
 d.z = e->z - s->z; \
 d.x = e->x - s->x; \
 float squared = d.x * d.x + d.z * d.z; \
 float len_; \
 if ((float)(double)nw4r::ut::Abs(squared) <= k[0x150 / 4]) len_ = k[0x88 / 4]; \
 else len_ = squared * rsqrtf(squared); \
 if (len_ > k[0x88 / 4]) { \
  d.x = d.x * (k[0x138 / 4] / len_); \
  d.z = d.z * (k[0x138 / 4] / len_); \
  float offZ = pos.z - s->z; \
  o.x = pos.x - s->x; o.z = offZ; \
  float t_ = d.x * o.x + d.z * o.z; \
  if (t_ >= k[0x88 / 4] && t_ <= len_) { \
   d.x = d.x * t_; d.z = d.z * t_; \
   q.x = o.x - d.x; q.z = o.z - d.z; \
   if (q.x * q.x + q.z * q.z < r2) break; \
  } \
 } \
}
extern "C" f32 fn_2_B184(void* arg0, s32 arg1, f32 farg0, f32 farg1) {
 const float* k = lbl_2_rodata_218;
 void* handle = 0;
 void* list = 0;
 s32 o14, o10;
 Vec3* seg;
 u8 o9 = 0;
 u8 o8;
 u32 i;
 s32 count, n;
 float r2;
 float best = k[0x15C / 4];
 Vec2 dd, oo;
 Vec2 pos;
 Vec2 cp, df;
 Vec2 q1, q2, q3;
 pos.x = farg0;
 pos.z = farg1;
 char* a0 = *(char**)((char*)arg0 + ((*(s32*)((char*)arg0 + 0x2BC)) + 2) * 4 + 0xE8);
 char* b0 = *(char**)(a0 + 0x10);
 handle = *(void**)(b0 + 0xE8);
 count = fn_8018EF78(&handle, b0);
 if (count == 0) return k[0x88 / 4];
 r2 = k[0x88 / 4];
 for (i = 0; i < (u32)count; i++) {
  list = fn_8018EED0(&handle, (s32)i);
  fn_801926D8(&list, &o14, &o10, &o9);
  fn_80192744(&list, &seg, &o8);
  Vec3* b;
  Vec3* a = (Vec3*)seg;
  char* shape;
  if (!(best >= a->y)) {
   b = a + 1;
   shape = (char*)list;
   seg = b;
   s32 kk = 1;
   while (kk < *(u16*)(shape + 0x1E) - 1) {
    Vec3* c = b + 1;
    if (!(outside(a->x, b->x, a->z, b->z, pos, dd, oo) > r2 || outsideMid(b->x, c->x, b->z, c->z, pos, dd, oo) > r2 || outside(c->x, a->x, c->z, a->z, pos, dd, oo) > r2)) break;
    seg = c; b = c; kk++;
   }
   if (kk < ((u16*)shape)[15] - 1) best = b->y;
  }
 }
 Matrix matrix = fn_2_A618(arg0, arg1);
 Vec3 scale;
 fn_8003E6DC(&matrix, &scale);
 char* entry = (char*)arg0 + arg1 * 0x14;
 char* entries = *(char**)(*(char**)((char*)arg0 + 0xD8));
 s32 sel = ((Flags*)(entry + 0x4C))->active ? *(s32*)(entry + 0x50) : -1;
 float width = *(float*)(entries + sel * 0x60 + 0x38);
 float step = k[0x154 / 4] * (width * scale.x);
 r2 = step * step;
 for (i = 0; i < (u32)count; i++) {
  list = fn_8018EED0(&handle, (s32)i);
  fn_80192744(&list, &seg, &o8);
  Vec3* p = (Vec3*)seg;
  if (!(best >= p->y)) {
   s32 m = 0;
   while (m < *(u16*)((char*)list + 0x1E)) {
    cp.z = p->z; cp.x = p->x;
    df.x = pos.x - cp.x;
    df.z = pos.z - cp.z;
    if (df.x * df.x + df.z * df.z < r2) break;
    p++; seg = p; m++;
   }
   if (m < *(u16*)((char*)list + 0x1E)) best = ((Vec3*)seg)->y;
  }
 }
 Vec3* a;
 for (u32 j = 0; j < (u32)count; j++) {
  list = fn_8018EED0(&handle, (s32)j);
  fn_80192744(&list, &seg, &o8);
  a = (Vec3*)seg;
  if (!(best >= a->y)) {
   Vec3* b = a + 1;
   s32 kk = 1;
   seg = b;
   while (kk < *(u16*)((char*)list + 0x1E) - 1) {
    Vec3* c = b + 1;
    CHECK_SEGMENT(a, b, dd, oo, q1)
    CHECK_SEGMENT(seg, c, dd, oo, q2)
    CHECK_SEGMENT(c, a, dd, oo, q3)
    seg = c; b = c; kk++;
   }
   if (kk < *(u16*)((char*)list + 0x1E) - 1) best = ((Vec3*)seg)->y;
  }
 }
 if (k[0x15C / 4] == best) best = k[0x88 / 4];
 if (((u8*)arg0)[0x259] == 0) best -= k[0x178 / 4];
 return best;
}
