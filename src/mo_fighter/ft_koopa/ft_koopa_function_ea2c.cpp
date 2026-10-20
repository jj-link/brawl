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
    virtual unsigned int v9(int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned int v13();
};

extern "C" unsigned int fn_102_EA2C(void* unused, void* ft) {
    VObj* obj = *(VObj**)((char*)*(void**)((char*)ft + 0xd8) + 0x54);
    if (obj->v9(0) == 1) {
        VObj* obj2 = *(VObj**)((char*)*(void**)((char*)ft + 0xd8) + 0x3c);
        return obj2->v13();
    }
    return 0;
}
