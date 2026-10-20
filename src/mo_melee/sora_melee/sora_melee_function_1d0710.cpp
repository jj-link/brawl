#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

typedef struct Elem {
    s32 a;
    s32 b;
    s32 c;
} Elem;

typedef struct Obj {
    u8 pad[8];
    s32 f8;
    Elem arr[4];
} Obj;

extern "C" void* fn_27_1D0710(Obj* p, s32 idx) {
    s32 t = (p->f8 >> 28) + idx;
    if (t >= 4) {
        t -= 4;
    }
    return (char*)p + 12 + t * 12;
}
