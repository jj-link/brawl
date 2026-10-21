#pragma force_active on
struct KirbyObj {
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
    virtual void v16(int, void*, int);
    virtual int v17(unsigned int);
    virtual void v18(unsigned int);
};

extern "C" void fn_96_28E78(void* object, int value);

extern "C" void fn_96_28E98(void* unused, void* ft) {
    char local[32];
    KirbyObj* m = *(KirbyObj**)((char*)ft + 0xd8);
    KirbyObj* obj = *(KirbyObj**)((char*)m + 0x64);
    int r = obj->v17(0x22000000);
    if (r == 0) {
        fn_96_28E78(local, 0x1a);
        KirbyObj* m2 = *(KirbyObj**)((char*)ft + 0xd8);
        KirbyObj* obj2 = *(KirbyObj**)((char*)m2 + 0x54);
        obj2->v16(0, local, 0);
        KirbyObj* m3 = *(KirbyObj**)((char*)ft + 0xd8);
        KirbyObj* obj3 = *(KirbyObj**)((char*)m3 + 0x64);
        obj3->v18(0x22000000);
    }
}
