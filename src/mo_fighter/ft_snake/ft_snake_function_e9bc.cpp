#pragma force_active on
extern "C" {
extern signed char lbl_122_bss_164;
extern char lbl_122_bss_168[8];
extern char lbl_122_bss_150[12];
void fn_27_3BAEF0(void*);
void fn_27_3BAF00(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_3BB0B4(void*, void*, void*, int, void*);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];
}

struct FtModuleProxy {
    unsigned int pad[2];
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void* getObj();
};

struct FtObjProxy {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual unsigned int query();
};

extern "C" void fn_122_E9BC(void* a, void* b) {
    if (lbl_122_bss_164 == 0) {
        fn_27_3BAEF0(lbl_122_bss_168);
        __register_global_object(lbl_122_bss_168, (void*)fn_27_3BAF00, lbl_122_bss_150);
        lbl_122_bss_164 = 1;
    }

    void* holder = *(void**)((char*)b + 0xD8);
    FtModuleProxy* mod = *(FtModuleProxy**)holder;
    void* data = getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x2E);
    FtObjProxy* obj = static_cast<FtObjProxy*>(mod->getObj());
    fn_27_3BB0B4(lbl_122_bss_168, a, b, obj->query(), *(void**)((char*)data + 0xC8));
}
