#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(unsigned short id);
};

struct Self {
    virtual void f0(int arg);
    unsigned int pad;
    Inner* inner;
    unsigned short ids[3];
};

extern "C" void fn_802AC5A4(Self* self) {
    char* p = (char*)self;
    for (int i = 0; i < 3; i++) {
        unsigned short id = *(unsigned short*)(p + 0xC);
        if (id != (unsigned short)-1) {
            self->inner->f4(id);
        }
        p += 2;
    }
    if (self) {
        self->f0(1);
    }
}
