#pragma force_active on
struct FnObj27 {
    unsigned char pad0[0x49];
    unsigned char m49;
    unsigned char m4A;
    unsigned char pad1[0x10];
    void* m5C;
};

extern "C" void fn_27_2553A0(FnObj27* self, void* arg) {
    if (self->m49 == 0) {
        return;
    }
    if (self->m4A != 0) {
        return;
    }
    self->m5C = arg;
    self->m4A = 1;
}
