#pragma force_active on
typedef signed int s32;

struct Fn27Obj {
    unsigned char pad[0x18];
    s32 field18;
};

extern "C" {
unsigned char* fn_27_1BB5A8(Fn27Obj* p, s32 idx)
{
    s32 n = (p->field18 >> 29) + idx;
    if (n >= 2) {
        n = n - 2;
    }
    return (unsigned char*)p + n * 12 + 0x1c;
}
}
