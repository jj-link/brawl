#pragma force_active on
extern "C" int fn_800B63B8(void*);

struct VBase {
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
    virtual void v12();
    virtual void v13(void* a);
};

extern "C" int fn_800DEDC8(void* self) {
    int r0;
    int r3;
    void* obj = *(void**)((unsigned char*)self + 0x58);
    if (fn_800B63B8(obj) == 0) {
        r0 = 0;
    } else {
        VBase* p8 = *(VBase**)((unsigned char*)self + 0x8);
        p8->v13(*(void**)((unsigned char*)obj + 0x10));
        r0 = 1;
    }
    if (r0 == 0) {
        return 7;
    }
    r3 = 0;
    int t = *(unsigned char*)((unsigned char*)self + 0x174) + 1;
    unsigned char c = (unsigned char)t;
    *(unsigned char*)((unsigned char*)self + 0x174) = t;
    if (c < 2) {
        r3 = 7;
    }
    return r3;
}
