#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern "C" void fn_80112218(char* arg0) {
    u16 i;
    char* p;
    f32 v;
    for (i = 0; i < *(u16*)(arg0 + 2); i++) {
        p = *(char**)(arg0 + 0x10) + ((u32)i << 4 & 0xFFFF0);
        v = *(f32*)p;
        *(f32*)(p + 8) = v;
        *(f32*)(p + 12) = *(f32*)(p + 4);
    }
}
