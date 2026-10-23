#pragma force_active on

typedef unsigned short u16;

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(u16 id);
};

struct Outer {
    virtual void f2(int arg);
    virtual void f1();
    virtual void f0();
    char pad0[4];
    Inner* m_inner;
    char pad1[0x10];
    u16 m_ids[8];
};

extern "C" void fn_802BD9F8(Outer* self) {
    char* p = (char*)self;
    for (int i = 0; i < 8; i++) {
        u16 id = *(u16*)(p + 0x1c);
        if (id != 0xffff) {
            self->m_inner->f4(id);
        }
        p += 2;
    }
    if (self != 0) {
        self->f2(1);
    }
}
