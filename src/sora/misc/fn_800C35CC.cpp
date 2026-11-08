#include <types.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
class Object50 { char pad[0x50]; public: virtual ~Object50(); };
inline void cleanup(void* &buffer, Object50* &object) {
 if (object) { delete object; object = 0; }
 if (buffer) gfHeapManager::free(buffer);
 buffer = 0;
}
extern "C" {
extern char lbl_80456FF0[];
extern char lbl_80457030[];
extern char lbl_8059E148;
void fn_800C1B3C(void*, s32, nw4r::g3d::ResFile, nw4r::g3d::ResFile, s32, s32, s32, s32, s32, u8, u8, char*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_80038984(void*, s32);
char* strcat(char*, const char*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_800C37B0(void*);
void fn_800C37CC(void*);
}
extern "C" void* fn_800C35CC(void* self, s32 mode, nw4r::g3d::ResFile arg2, nw4r::g3d::ResFile arg3,
 s32 a, s32 b, s32 c, s32 d, s32 arg_sp8, u8 arg_spC, u8 arg_sp10) {
 char* p = (char*)self;
 s32 mappedMode;
 switch (mode) {
 case 1: mappedMode = 2; break;
 case 2: mappedMode = 3; break;
 case 3: mappedMode = 4; break;
 default: mappedMode = 0; break;
 }
 fn_800C1B3C(self, mappedMode, arg2, arg3, a,b,c,d,arg_sp8,arg_spC,arg_sp10,lbl_80456FF0);
 *(char**)(p + 0x3C) = lbl_80457030;
 void* child = __nw__FUlQ25Heaps8HeapType(0x194, *(s32*)(p + 0x44));
 if (child != 0) child = fn_80038984(child, *(s32*)(p + 0x44));
 *(void**)(p + 0x110) = child;
 *(u8*)(p + 0x114) = 0;
 *(s32*)(p + 0x118) = mode;
 *(u8*)(p + 0x11C) = 0;
 strcat(p + 0x11C, &lbl_8059E148);
 *(u8*)(p + 0x15D) = 0;
 strcat(p + 0x15D, &lbl_8059E148);
 *(s32*)(p + 0x1A0) = 0;
 *(s32*)(p + 0x1A4) = 0;
 *(u8*)(p + 0x1A8) = 0;
 strcat(p + 0x1A8, &lbl_8059E148);
 *(s32*)(p + 0x1EC) = 0;
 *(s32*)(p + 0x1F8) = 0;
 cleanup(*(void**)(p + 0x1EC), *(Object50**)(p + 0x1F8));
 *(s32*)(p + 0x1FC) = 0;
 *(s32*)(p + 0x200) = 0;
 *(u8*)(p + 0x204) = 0;
 strcat(p + 0x204, &lbl_8059E148);
 *(s32*)(p + 0x248) = 0;
 *(void**)(p + 0x34C) = p + 0x24C;
 *(s32*)(p + 0x350) = 0;
 *(s32*)(p + 0x354) = 2;
 __construct_array(p + 0x358, fn_800C37B0, fn_800C37CC, 0x14, 2);
 *(u8*)(p + 0x2C) &= ~2;
 return self;
}