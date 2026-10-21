#pragma force_active on

extern "C" {
void* fn_120_8044();
unsigned int fn_27_5BE80(void);
int* fn_120_7F08(void);
void fn_27_3A2D10(void*, void*);
void fn_120_8AB4(void*, void*);
void fn_27_12DCA8(void*);
}

class VCall {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(unsigned int);
};

struct Base {
    int a;
    int b;
};

class Other : public Base {
public:
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
    virtual int v14();
};

extern "C" void fn_120_7F78(char* obj) {
    char* sub = *(char**)(obj + 0x60);
    fn_120_8044();

    if (fn_27_5BE80() == 1U) {
        VCall* b = *(VCall**)(*(char**)(sub + 0xD8) + 0x44);
        if (b->v9() == 0) {
            Other* c = *(Other**)(*(char**)(sub + 0xD8) + 0xB8);
            if (c->v14() == 0) {
                VCall* d = *(VCall**)(*(char**)(sub + 0xD8) + 0x64);
                if (d->v17(0x12000042) == 0) {
                    fn_27_3A2D10(fn_120_7F08(), sub);
                }
                fn_120_8AB4(obj, sub);
            }
        }
    }

    fn_27_12DCA8(obj);
}
