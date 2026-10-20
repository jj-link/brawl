#pragma force_active on
class Sub {
public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
};

extern "C" void fn_27_18F568(void* unused, char* r4) {
    Sub* a = *(Sub**)(*(char**)(r4 + 0xd8) + 0x54);
    if (a->v23() == 0) {
        Sub* b = *(Sub**)(*(char**)(r4 + 0xd8) + 0x44);
        b->v5();
        Sub* c = *(Sub**)(*(char**)(r4 + 0xd8) + 0x44);
        c->v7();
    }
}
