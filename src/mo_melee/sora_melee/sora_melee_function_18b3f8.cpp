#pragma force_active on
extern "C" {
void fn_27_16C2FC(void* a, void* b, unsigned int c);
}

class VtA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(unsigned int arg);
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
    virtual void v20();
    virtual void v21();
    virtual void v22(void* p, int x, int y);
};

extern "C" void fn_27_18B3F8(void* a, void* b, unsigned int c) {
    char* pb = (char*)b;
    VtA* o1 = *(VtA**)(*(char**)(pb + 0xd8) + 0x64);
    void* r = o1->v4(0x20000001);

    VtA* o2 = *(VtA**)(*(char**)(pb + 0xd8) + 0x88);
    o2->v22(r, 1, 1);

    fn_27_16C2FC(a, b, c);
}
