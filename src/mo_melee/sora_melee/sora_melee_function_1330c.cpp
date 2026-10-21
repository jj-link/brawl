#pragma force_active on

extern "C" void fn_80098578(int, int);
extern const float lbl_27_rodata_338;

struct Pad {
    int a;
    int b;
};

class Obj : public Pad {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20(float);
    virtual void v21(int);
};

class Inner {
public:
    virtual void v0();
    virtual int* v1(int);
    virtual void v2();
    virtual int v3();
};

extern "C" void fn_27_1330C(Obj* self) {
    float f = lbl_27_rodata_338;
    self->v20(f);
    self->v21(0);

    char* s = (char*)self;
    if (*(int*)(s + 0x30) != 0) {
        for (int i = 0; i < ((Inner*)*(char**)(s + 0x34))->v3(); i++) {
            int* p = ((Inner*)*(char**)(s + 0x34))->v1(i);
            fn_80098578(*(int*)(s + 0x30), *p);
        }
    }
}
