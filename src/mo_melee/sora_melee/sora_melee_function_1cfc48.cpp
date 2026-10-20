#pragma force_active on
typedef int s32;

struct Obj {
    char pad[8];
    s32 field8;
};

extern "C" void* fn_27_1CFC48(Obj* self, s32 idx) {
    s32 sh = self->field8 >> 27;
    s32 n = sh + idx;
    if (n >= 11) {
        n -= 11;
    }
    return (char*)self + n * 12 + 12;
}
