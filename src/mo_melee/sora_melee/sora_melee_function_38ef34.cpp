#pragma force_active on
struct fn_27_38EF34_Data {
    char pad[0x18];
    int m18;
    char pad2[0x60 - 0x1C];
    void* m60[1];
};

extern "C" void* fn_27_38EF34(fn_27_38EF34_Data* self, int unused, int idx) {
    return self->m60[idx - self->m18];
}
