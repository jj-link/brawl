#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

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
    virtual void method40();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void method50();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void method74(int, int);

    u8 pad04[0x50];
    u32 work54;
    u8 pad58[0x0C];
    u32 work64;
    u8 pad68[0x0C];
    u32 work74;
    u8 pad78[0xBC];
    u8 b134;
    u8 flag80 : 1;
    u8 flag40 : 1;
    u8 flag20 : 1;
    u8 flag10 : 1;
    u8 flag08 : 1;
    u8 flagRest : 3;
};

extern "C" void fn_27_97C48(Obj* self) {
    self->method74(0, 0);
    self->method40();
    self->method50();

    self->work54 = 0;
    self->work64 = 0;
    self->flag80 = 0;
    self->flag20 = 0;
    self->flag08 = 1;
    self->work74 = 0xFFFFFFFF;
    self->b134 = 1;
}
