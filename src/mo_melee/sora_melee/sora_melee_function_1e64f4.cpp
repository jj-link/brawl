#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad[0x18];
    s32 count;
};

extern "C" void* fn_27_1E64F4(Obj* p, s32 idx) {
    s32 t = p->count >> 30;
    s32 n = t + idx;
    if (n >= 1) {
        n--;
    }
    return (u8*)p + n * 12 + 0x1c;
}
