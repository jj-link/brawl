#pragma force_active on
typedef unsigned int u32;

extern "C" void* getInstance__9emManagerFv();
extern "C" u32 fn_41_D044(void*, u32);
extern "C" int fn_41_D0A8(void*, void*);
extern "C" void* fn_41_CECC(void*, void*);

struct emVirtObj {
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
    virtual void v16();
    virtual int v17(u32);
};

extern "C" bool fn_41_B34C(void* p) {
    void* task = (void*)fn_41_D044(getInstance__9emManagerFv(), *(u32*)((char*)p + 0xB0));
    if (fn_41_D0A8(getInstance__9emManagerFv(), task) == 0) {
        return true;
    }
    void* node = fn_41_CECC(getInstance__9emManagerFv(), task);
    emVirtObj* obj = *(emVirtObj**)((char*)*(void**)((char*)*(void**)((char*)node + 0x60) + 0xD8) + 0x64);
    int r = obj->v17(0x12000000);
    return r == 1;
}
