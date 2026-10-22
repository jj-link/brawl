#pragma force_active on

struct Obj {
    int unk0;
    char pad4[0x31 - 4];
    char unk31;
    char unk32[0x35 - 0x32];
    unsigned char unk35;
    char pad36[0xDC - 0x36];
    void* unkDC;
};

extern "C" void fn_801D1630(void* p, int v);

extern "C" void fn_801BE2D4(Obj* self) {
    if (self->unk0 != 3) {
        void* temp = self->unkDC;
        if (temp != 0 && self->unk35 == 0) {
            fn_801D1630(temp, 1);
        }
        self->unk0 = 3;
    }
    self->unk31 = 0;
}
