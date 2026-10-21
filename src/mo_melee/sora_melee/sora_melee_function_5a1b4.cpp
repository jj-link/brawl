#pragma force_active on

struct Obj {
    unsigned char pad0[0x50];
    unsigned int m50;
    unsigned char pad54[4];
    unsigned char values[34];
};

extern "C" void fn_27_5A1B4(Obj* self) {
    self->m50 = 0;
    for (int i = 0; i < 34; ++i)
        self->values[i] = 0xFE;
}
