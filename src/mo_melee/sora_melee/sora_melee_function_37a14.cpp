#pragma force_active on
extern "C" void fn_8015BF9C(void*, int);

class fnInner {
public:
    virtual void v0();
    virtual fnInner* v1();
};

class fnOuter {
public:
    unsigned char pad0[0x8];
    fnInner* m_inner;
    unsigned char pad1[0x12 - 0xC];
    unsigned char m_flag;
};

extern "C" void fn_27_37A14(fnOuter* self) {
    fn_8015BF9C(reinterpret_cast<char*>(self->m_inner->v1()) + 0x40, 0x10);
    self->m_flag = 0;
}
