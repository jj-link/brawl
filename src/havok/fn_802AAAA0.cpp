#pragma force_active on

typedef unsigned short u16;

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(u16 id);
};

struct Self {
    virtual void f0(int arg);
    int m_pad;
    Inner* m_inner;
    u16 m_flags[3];
};

extern "C" void fn_802AAAA0(Self* self) {
    char* p = (char*)self;
    for (int i = 0; i < 3; i++) {
        u16 id = *(u16*)(p + 0xC);
        if (id != 0xFFFF) {
            self->m_inner->f4(id);
        }
        p += 2;
    }
    if (self != 0) {
        self->f0(1);
    }
}
