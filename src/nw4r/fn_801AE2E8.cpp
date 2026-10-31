#pragma force_active on
struct Self {
    unsigned char _padding[0xCC];
    unsigned m_flags;
};

struct VObj {
    virtual void method1();
    virtual int method2(Self* self, int b1, int b2);
};

extern "C" int fn_801AE2E8(Self* self, void* unused, VObj* obj) {
    unsigned flags = self->m_flags;
    int b1 = !(flags & 0x20000000);
    int b2 = !(flags & 0x40000000);
    return obj->method2(self, b1, b2);
}
