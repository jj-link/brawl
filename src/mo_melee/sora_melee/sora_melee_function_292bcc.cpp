#pragma force_active on
typedef int s32;

struct Obj {
    char pad[0x18];
    s32 field;
};

extern "C" void* fn_27_292BCC(Obj* self, s32 idx) {
    s32 n = (self->field >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (char*)self + 0x1c + n * 12;
}
