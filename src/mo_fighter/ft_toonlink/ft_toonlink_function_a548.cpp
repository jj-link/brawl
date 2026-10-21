#pragma force_active on

extern "C" {
void fn_121_13A84(void*, float, float, int);
float fn_121_A600(void*);
}

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
    virtual float v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(unsigned int);
    virtual void v18(unsigned int);
};

extern "C" int fn_121_A548(void* arg0, void* arg1) {
    int res;
    void* d8 = *(void**)((unsigned char*)arg1 + 0xd8);
    Obj* c = *(Obj**)((unsigned char*)d8 + 0xc);
    Obj* r3 = *(Obj**)((unsigned char*)d8 + 0x64);
    res = r3->v17(0x22000011);
    float f31 = fn_121_A600(arg1);
    fn_121_13A84(arg0, c->v9(), f31, res);
    Obj* o = *(Obj**)((unsigned char*)*(void**)((unsigned char*)arg1 + 0xd8) + 0x64);
    o->v18(0x1200003d);
    return 1;
}
