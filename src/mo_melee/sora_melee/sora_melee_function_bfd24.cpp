#include <types.h>
#pragma force_active on
extern "C" void fn_27_C137C(void*, const float*, u32, float);
struct Color { u8 r,g,b,a; };
struct Vec {
 float x,y,z,w;
 Vec(const Color& c) : x(c.r), y(c.g), z(c.b), w(c.a) {}
};
inline Vec convert(Color c) { return Vec(c); }
extern "C" void fn_27_BFD24(void* arg0, const Color* arg1, u32 arg2, float unused) {
 const Color c = *arg1;
 Vec vals = convert(c);
 void* p;
 if(arg2 == 1) p = (u8*)arg0 + 0xB8;
 else p = (u8*)arg0 + 0x30;
 fn_27_C137C((u8*)p + 0x3C, &vals.x, arg2, unused);
}