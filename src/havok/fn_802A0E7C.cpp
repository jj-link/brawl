#pragma force_active on
struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned short id);
};

struct Self {
    virtual void v0(int arg);
    char pad0[4];
    Handler* handler;
    char pad1[37];
    unsigned char count;
};

extern "C" void fn_802A0E7C(Self* self) {
    char* p = (char*)self;
    for (int i = 0; i < self->count; ++i) {
        unsigned short id = *(unsigned short*)(p + 0x12);
        self->handler->v4(id);
        p += 4;
    }
    if (self) {
        self->v0(1);
    }
}
