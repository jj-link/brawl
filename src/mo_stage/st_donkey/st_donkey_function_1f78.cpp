#pragma force_active on
typedef unsigned int u32;

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);

    void* p4;
    int f8;
};

struct Base { char pad[0x3c]; };

struct Obj : Base {
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();

    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x150 - 0xdc];
    unsigned char b150;
    char pad151[3];
    float f154;
    float f158;
    float f15c;
    float f160;
};

extern "C" void __ct__10grYakumonoFPCc(Obj*, const char*);
extern "C" const float lbl_50_rodata_58;
extern "C" void* lbl_50_data_828;

extern "C" Obj* fn_50_1F78(Obj* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = &lbl_50_data_828;
    self->b150 = 0;
    const float f = lbl_50_rodata_58;
    self->f154 = f;
    self->f158 = f;
    self->f15c = f;
    self->f160 = f;
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    s->v4(0, 0xf);
    void* p4 = s->p4;
    ((u32*)p4)[1] |= 4;
    self->v26();
    return self;
}
