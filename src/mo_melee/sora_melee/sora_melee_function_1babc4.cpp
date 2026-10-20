#pragma force_active on
struct Fn27Obj {
    char pad[0x18];
    int field18;
};

extern "C" {
char* fn_27_1BABC4(Fn27Obj* self, int idx)
{
    int i = (self->field18 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)self + i * 12 + 0x1c;
}
}
