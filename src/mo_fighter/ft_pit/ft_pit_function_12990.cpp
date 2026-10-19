#pragma force_active on
struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void target();
};

extern "C" void fn_112_12990(void* unused, unsigned char* self, unsigned char* other) {
    unsigned char local[8];
    VObj* p = *(VObj**)(other + 0xd8);
    p = *(VObj**)((unsigned char*)p + 0x7c);
    p->target();
    *(unsigned char*)local = 0;
    self[0xb9] = self[0xb9] | 0x80;
}
