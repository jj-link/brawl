#pragma force_active on
extern "C" void setIdentity__6MatrixFv(void*);
extern "C" void* fn_52_35D0(void* self, const char* name);
extern "C" char lbl_52_data_44B8[];

struct Obj {
    char pad1[0x3c];
    void* f3c;
    char pad2[0x90];
    void* fD0;
    char pad3[0x8c];
    void* f160;
    void* f164;
    char f168[0x30];
    unsigned char f198;
    unsigned char f199;
    unsigned char f19a;
    unsigned char f19b;
    unsigned int f19c;
};

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void method(int, int);

    unsigned int* flags;
    unsigned int x;
};

extern "C" void* fn_52_12654(void* self, const char* name) {
    Obj* obj = (Obj*)self;
    fn_52_35D0(obj, name);
    obj->f160 = 0;
    obj->f3c = &lbl_52_data_44B8;
    obj->f164 = 0;
    setIdentity__6MatrixFv(&obj->f168);
    obj->f198 = 3;
    obj->f199 = 7;
    obj->f19a = 0;
    obj->f19b = 0;
    obj->f19c = 0;
    Sub* sub = (Sub*)((char*)self + 0xD0);
    if (sub == 0) {
        return obj;
    }
    sub->x = 1;
    sub->method(0, 15);
    sub->flags[1] |= 8;
    return obj;
}
