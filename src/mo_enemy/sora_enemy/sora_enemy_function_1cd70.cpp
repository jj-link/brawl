#include <types.h>
#pragma force_active on
struct Bits { unsigned char flag : 1; };
class Object_vptr_0 { public: virtual void slot0(); virtual void* slot1(u32); };
extern "C" void fn_41_1CC18(void*);
extern "C" void fn_41_1BEE0(void*, const void*);
extern "C" void fn_41_534C(void*, const void*);
extern "C" void fn_41_1BEA8(void*, const void*);
extern "C" void fn_41_1CD70(void* arg0, const void* arg1) {
 u8* dst=(u8*)arg0; const u8* src=(const u8*)arg1;
 fn_41_1CC18(arg0); fn_41_1BEE0(dst+8,src+8);
 dst[0x48]=src[0x48];
 *(float*)(dst+0x4C)=*(const float*)(src+0x4C); *(float*)(dst+0x50)=*(const float*)(src+0x50);
 *(float*)(dst+0x54)=*(const float*)(src+0x54); *(float*)(dst+0x5C)=*(const float*)(src+0x5C);
 *(float*)(dst+0x60)=*(const float*)(src+0x60); dst[0x64]=src[0x64];
 *(float*)(dst+0x68)=*(const float*)(src+0x68); *(float*)(dst+0x6C)=*(const float*)(src+0x6C);
 *(u32*)(dst+0x70)=*(const u32*)(src+0x70); *(u32*)(dst+0x74)=*(const u32*)(src+0x74);
 *(float*)(dst+0x78)=*(const float*)(src+0x78); *(float*)(dst+0x7C)=*(const float*)(src+0x7C);
 *(u32*)(dst+0x80)=*(const u32*)(src+0x80); *(float*)(dst+0x84)=*(const float*)(src+0x84);
 *(float*)(dst+0x88)=*(const float*)(src+0x88); *(u32*)(dst+0x8C)=*(const u32*)(src+0x8C);
 *(u32*)(dst+0x90)=*(const u32*)(src+0x90);
 fn_41_534C(dst+0x94,src+0x94); fn_41_534C(dst+0xA0,src+0xA0);
 *(float*)(dst+0xAC)=*(const float*)(src+0xAC); dst[0xB0]=src[0xB0];
 fn_41_1BEA8(dst+0xB4,src+0xB4); fn_41_534C(dst+0xBC,src+0xBC);
 u32 c = ((u32)(u8)(src[5] & 0x80)) >> 7;
 u32 flag = c != 0;
 if (flag == 1)
  dst[5] |= 0x80;
 else
  ((Bits*)(dst+5))->flag = 0;
 for (u32 i=0;i<2;++i) {
  void* a=(*(Object_vptr_0**)(src+0xC8))->slot1(i);
  void* b=(*(Object_vptr_0**)(dst+0xC8))->slot1(i);
  *(u32*)b=*(u32*)a;
 }
}