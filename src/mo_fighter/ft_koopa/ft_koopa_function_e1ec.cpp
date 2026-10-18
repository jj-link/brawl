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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(unsigned int);
    virtual void v18();
    virtual void v19(unsigned int);
    virtual void v20();
    virtual void v21();
    virtual void v22(int);
};

extern "C" {
void fn_102_E1EC(void* a, char* b) {
    Obj* p = *(Obj**)(b + 0xd8);
    Obj* obj = *(Obj**)((char*)p + 0x64);
    if (obj->v17(0x1200003d)) {
        obj->v22(2);
        obj->v19(0x22000011);
        obj->v19(0x1200003d);
    }
}
}
