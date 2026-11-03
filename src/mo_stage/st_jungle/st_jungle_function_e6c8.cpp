#pragma force_active on
#pragma fp_contract off

extern "C" const float lbl_51_rodata_120[];

struct Params {
    char pad[4];
    float value1;
    float value2;
    unsigned char state;
};

struct Base {
    char pad[0x3c];
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
    virtual void v27();
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
    virtual Params* v40();
};

struct JungleObj : Base {
    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x48];
    float position;
    char pad1a4[8];
    float target;
    char pad1b0[4];
    unsigned char flag;
};

extern "C" void fn_51_E6C8(JungleObj* self, float delta) {
    const float* c = lbl_51_rodata_120;
    Params* p = self->v40();
    if (p) {
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            if (self->flag != p->state)
                self->state = 1;
            break;
        case 1:
            break;
        case 4:
            self->position += p->value2 * delta;
            if (self->position - self->target > c[2] * p->value1)
                self->state = 5;
            break;
        case 5: {
            float prod = c[3] * p->value2;
            self->position -= prod * delta;
            if (self->position - self->target < p->value1) {
                float newPos = self->target + p->value1;
                self->state = 0;
                self->position = newPos;
            }
            break;
        }
        }
    }
}