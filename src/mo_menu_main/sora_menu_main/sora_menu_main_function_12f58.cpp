#pragma force_active on
struct Obj {
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
    virtual void vfn(void*, void*);
};

extern "C" void fn_2_12F58(void* self) {
    char* s = (char*)self;
    void* a = *(void**)(s + 0x7b4);
    void** p = (void**)((char*)*(void**)(s + 0x7bc) + 0x64);
    Obj* obj = *(Obj**)((char*)a + 0x48);
    for (int i = 0; i < 3; i++) {
        obj->vfn(*(void**)((char*)obj + 0xe4), *(void**)((char*)*p + 0x10));
        p++;
    }
}
