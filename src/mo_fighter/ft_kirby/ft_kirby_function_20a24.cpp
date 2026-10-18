#pragma force_active on
extern "C" void fn_96_20AC0(void* fighter, int result);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(unsigned int);
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
    virtual void v16();
    virtual unsigned int v17(unsigned int);
};

extern "C" void fn_96_20A24(void* fighter) {
    void* mod = *(void**)((char*)fighter + 0x8);
    void* sub = *(void**)((char*)mod + 0xD8);
    VObj* obj = *(VObj**)((char*)sub + 0x64);
    unsigned int result = obj->v17(0x12000042);
    if (result == 1) {
        mod = *(void**)((char*)fighter + 0x8);
        sub = *(void**)((char*)mod + 0xD8);
        obj = *(VObj**)((char*)sub + 0x64);
        void* r = obj->v4(0x10000048);
        fn_96_20AC0(fighter, (int)r);
    } else {
        ((VObj*)fighter)->v10();
    }
}
