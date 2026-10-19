#pragma force_active on
extern "C" char lbl_118_data_600[];
extern "C" char lbl_118_data_2250[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

struct fn_118_8E70_Iface {
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v22(int, int);
};

extern "C" void fn_118_8E70(void* obj, int arg) {
    void* p = __dynamic_cast(*(void**)((unsigned char*)obj + 0x8), 0x3c, lbl_118_data_600, lbl_118_data_2250, 1);
    fn_118_8E70_Iface* x = (fn_118_8E70_Iface*)*(void**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)p + 0x60) + 0xD8) + 0x64);
    x->v22(arg, 0x1200003F);
}
