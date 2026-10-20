#pragma force_active on
typedef unsigned char u8;

extern "C" void* memset(void* p, int c, unsigned long n);

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct Work {
    u8 pad0[0x54];
    Obj* m_54;
    u8 pad1[0x78 - 0x58];
    int m_78;
    u8 m_7c[0x10];
    u8 m_8c[0x10];
};

extern "C" void fn_27_248478(Work* self);

extern "C" {
void fn_27_248010(Work* self) {
    self->m_78 = 0;
    memset(self->m_7c, 0, 0x10);
    memset(self->m_8c, 0, 0x10);
    fn_27_248478(self);
    if (self->m_54 != 0) {
        self->m_54->f2();
    }
}
}
