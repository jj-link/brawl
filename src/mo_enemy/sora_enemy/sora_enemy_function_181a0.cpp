#pragma force_active on
extern float lbl_41_rodata_C3C;

extern "C" {
int fn_41_15FD4(int a, int b);
float fn_41_1F3B0(void* self);
}

extern "C" float fn_41_181A0(void* self, int id) {
    if (id == -1) {
        return lbl_41_rodata_C3C;
    }
    return fn_41_1F3B0((void*)fn_41_15FD4((int)self, id));
}
