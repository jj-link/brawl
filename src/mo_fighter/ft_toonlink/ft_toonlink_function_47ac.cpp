#pragma force_active on
extern "C" void fn_121_1AC4(void* self, int val);
extern "C" char lbl_121_data_328C[];

struct ToonLinkWork {
    void* vtSecondary;  // +0x00
    void* pad04;        // +0x04
    void* vtPrimary;    // +0x08
    void* a;            // +0x0C
    void* b;            // +0x10
    void* c;            // +0x14
    void* d;            // +0x18
    void* e;            // +0x1C
    void* f;            // +0x20
};

extern "C" ToonLinkWork* fn_121_47AC(ToonLinkWork* self, void* a, void* b, void* c, void* d, void* e, void* f) {
    fn_121_1AC4(self, 0);
    self->vtPrimary = lbl_121_data_328C;
    self->vtSecondary = lbl_121_data_328C + 8;
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->e = e;
    self->f = f;
    return self;
}
