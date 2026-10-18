#pragma force_active on
extern "C" void fn_92_6DC4(void* self, int flag);
extern "C" char lbl_92_data_18B0[];

struct DonkeyWork {
    void* vtSecondary;   // +0x00
    void* vtPrimary;     // +0x04 (unused here)
    void* vtPrimaryAlt;  // +0x08
    void* p0c;           // +0x0C
    void* p10;           // +0x10
    void* p14;           // +0x14
    void* p18;           // +0x18
    void* p1c;           // +0x1C
    void* p20;           // +0x20
};

extern "C" DonkeyWork* fn_92_7FAC(DonkeyWork* self, void* a, void* b, void* c, void* d, void* e, void* f) {
    fn_92_6DC4(self, 0);
    self->vtPrimaryAlt = lbl_92_data_18B0;
    self->vtSecondary = lbl_92_data_18B0 + 8;
    self->p0c = a;
    self->p10 = b;
    self->p14 = c;
    self->p18 = d;
    self->p1c = e;
    self->p20 = f;
    return self;
}
