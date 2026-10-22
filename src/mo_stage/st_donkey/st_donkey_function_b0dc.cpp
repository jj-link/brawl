#pragma force_active on
#pragma fp_contract off

extern "C" float randf__Fv();
extern "C" const float lbl_50_rodata_1A4;

struct Parameters {
    char pad[0x5C];
    float low0;
    float high0;
    float low9;
    float high9;
};

struct Base {
    char pad[0x3C];
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
    virtual void set(int);
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual Parameters* getParameters();
};

struct Self : Base {
    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x10];
    unsigned char* ptr;
};

extern "C" void fn_50_B0DC(Self* self, float delta) {
    Parameters* p = self->getParameters();
    if (p == 0) return;
    self->timer -= delta;
    if (self->timer < lbl_50_rodata_1A4)
        self->timer = lbl_50_rodata_1A4;
    switch (self->state) {
    case 0:
        self->set(0);
        self->timer = p->low0 + (p->high0 - p->low0) * randf__Fv();
        self->state = 1;
        break;
    case 1:
        if (lbl_50_rodata_1A4 == self->timer) {
            unsigned char* ptr = self->ptr;
            *ptr = 3;
            self->set(1);
            self->state = 8;
        }
        break;
    case 8:
        if ((unsigned char)(*self->ptr + 0xFC) > 1)
            break;
        self->set(0);
        self->state = 9;
        break;
    case 9:
        if (*self->ptr == 6) {
            self->timer = p->low9 + (p->high9 - p->low9) * randf__Fv();
            self->state = 1;
        }
        break;
    }
}
