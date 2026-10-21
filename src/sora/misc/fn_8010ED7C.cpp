#pragma force_active on
typedef unsigned int u32;

struct GfObj {
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
};

extern void* g_gfSceneRoot;

extern "C" void fn_8010ED7C(void* p) {
    void* r4 = *(void**)((char*)p + 4);
    u32 a = *(u32*)((char*)r4 + 4);
    GfObj* obj = *(GfObj**)((char*)g_gfSceneRoot + 0x450);
    if (a != (u32)obj) {
        return;
    }
    obj->v13();
}
