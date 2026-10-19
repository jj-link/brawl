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
    virtual unsigned int v9(int x);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual void v14();
    virtual void v15();
};

extern "C" int fn_102_17FA0(void* self, void* accesser) {
    char* acc = (char*)accesser;
    VObj* obj = *(VObj**)(*(char**)(acc + 0xd8) + 0x54);
    unsigned int status = obj->v9(0);
    if (status == 1) {
        VObj* obj2 = *(VObj**)(*(char**)(acc + 0xd8) + 0x3c);
        return obj2->v13();
    }
    return 0;
}
