#pragma force_active on
typedef int s32;

struct Obj {
    char pad[0x18];
    s32 field18;
};

extern "C" void* fn_27_1C0E84(Obj* self, s32 idx)
{
    s32 n = (self->field18 >> 27) + idx;
    if (n >= 10) {
        n -= 10;
    }
    return (char*)self + n * 12 + 0x1c;
}
