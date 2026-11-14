#include <types.h>
#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void* getInstance__16CameraControllerFv();
extern "C" void fn_800A41E4(void*, const void*);
extern "C" const char lbl_40_data_1590[];
extern "C" const char lbl_40_data_15D8[];
extern "C" const float lbl_40_rodata_44[];
struct Vec3f { f32 x; f32 y; f32 z; };
struct Vec2f { f32 x; f32 y; };
struct Words3 { s32 a; s32 b; s32 c; };
extern "C" void fn_40_5D44(char* self) {
    Vec3f pos;
    Vec3f v18;
    Vec2f tmp;
    f32 val;
    char* cc;
    char* pc;
    void* v90;
    int mode;
    cc = (char*)getInstance__16CameraControllerFv();
    *(Words3*)&pos = *(Words3*)(self + 0x560);
    tmp.x = pos.x;
    tmp.y = pos.y;
    pc = *(char**)(cc + 0x48);
    mode = *(int*)((char*)getInstance__16CameraControllerFv() + 0x40);
    switch (mode) {
        case 3:
        case 4:
            pc = (char*)__dynamic_cast(pc, 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
            fn_800A41E4(&v18, pc);
            pos = v18;
            if (*(void**)(self + 0x1C0) != 0) {
                val = *(f32*)(*(char**)(self + 0x1C0) + 4);
            } else {
                val = lbl_40_rodata_44[0];
            }
            *(f32*)(pc + 0xDC) = val;
            break;
    }
    v90 = *(void**)(self + 0x90);
    if (v90 != 0) {
        u8 c = *(u8*)(*(char**)(self + 0x524) + 0x604);
        if (c == 0 || c == 4) {
            *(f32*)((char*)v90 + 0x14) = pos.x;
            *(f32*)((char*)v90 + 0x18) = pos.y;
            *(f32*)((char*)v90 + 0x1C) = pos.z;
            *(u8*)(*(char**)(self + 0x90) + 0x62) = (*(u8*)(self + 0x550) >> 6) & 1;
        }
    }
}