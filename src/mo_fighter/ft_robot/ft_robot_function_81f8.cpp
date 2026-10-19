#pragma force_active on
extern "C" void fn_120_DF74(void*, void*);
extern "C" int lbl_120_bss_2B4;

class VObj {
public:
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
    virtual void v17();
    virtual int v18();
};

extern "C" void fn_120_81F8(void* a, void* b, char* self) {
    VObj* obj = *(VObj**)(*(char**)(self + 0xd8) + 0x70);
    int r = obj->v16();
    if (r == 0x113) {
        fn_120_DF74(&lbl_120_bss_2B4, self);
    }
}
