#pragma force_active on
extern "C" {
typedef signed int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

char* fn_27_1B0804(Obj* self, s32 idx) {
    s32 n = (self->unk8 >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (char*)self + n + 10;
}
}
