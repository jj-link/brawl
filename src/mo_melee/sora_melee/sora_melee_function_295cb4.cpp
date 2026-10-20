#pragma force_active on
struct Fn27Obj {
    char pad[8];
    int field8;
};

extern "C" char* fn_27_295CB4(Fn27Obj* self, int idx)
{
    int i = (self->field8 >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (char*)self + i * 0x38 + 0xc;
}
