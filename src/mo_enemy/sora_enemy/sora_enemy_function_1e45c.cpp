#pragma force_active on
struct Vec { unsigned int x, y, z; };
struct Unk {
    char pad0[8];
    int kind;
    char padC[0x3c];
    unsigned char flag;
    char pad49[0x73];
    Vec vec;
};
extern "C" void* __memcpy(void*, const void*, unsigned long);
extern "C" const float lbl_41_rodata_C9C;
extern "C" unsigned int fn_41_1AE7C(Unk*);
extern "C" unsigned int fn_41_1C9C4(Unk*);
extern "C" int fn_41_1AE30(int);
extern "C" Vec* fn_41_5AC4(Vec*, float, float, float);
extern "C" void fn_41_1E45C(Vec* out, Unk* self) {
    if (fn_41_1AE7C(self) == 1) {
        fn_41_5AC4(out, lbl_41_rodata_C9C, lbl_41_rodata_C9C, lbl_41_rodata_C9C);
        return;
    }
    if (fn_41_1C9C4(self) == 1) {
        fn_41_5AC4(out, lbl_41_rodata_C9C, lbl_41_rodata_C9C, lbl_41_rodata_C9C);
        return;
    }
    if (self->flag == 1) {
        fn_41_5AC4(out, lbl_41_rodata_C9C, lbl_41_rodata_C9C, lbl_41_rodata_C9C);
        return;
    }
    if (fn_41_1AE30(self->kind) == 1) {
        __memcpy(out, &self->vec, sizeof(Vec));
        return;
    }
    int kind = self->kind;
    if (kind != 0 && kind != 1 && kind != 0x17 && kind != 0x18 &&
        kind != 0x15 && kind != 0x16 && fn_41_1AE30(kind) == 0) {
        __memcpy(out, &self->vec, sizeof(Vec));
        return;
    }
    fn_41_5AC4(out, lbl_41_rodata_C9C, lbl_41_rodata_C9C, lbl_41_rodata_C9C);
}
