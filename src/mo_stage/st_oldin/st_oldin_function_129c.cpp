#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Matrix {
    u32 v[12];
};

struct EntityBase {
    u8 pad[0x3C];
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
    virtual void show(int);
};

struct Entity : EntityBase {
    u8 pad40[8];
    void** animations;
};

struct Stage {
    u8 pad[0x1F8];
    Entity* e1f8;
    Entity* e1fc;
    u32 unk200;
    Entity* e204;
    Entity* e208;
    u8 pad20c[0x1D];
    u8 flag229;
    u8 pad22a[2];
    u32 value22c;
    u32 value230;
    u8 pad234[0x30];
    Matrix matrix264;
    Matrix matrix294;
    u8 pad2c4[0xC];
    float x2d0, y2d4, z2d8;
    float value2dc;
    u8 pad2e0[0x98];
    float x378, y37c, z380;
    u32 value384;
    u8 pad388[0x248];
    u32 value5d0;
    u32 value5d4;
    float value5d8;
    int value5dc;
};

extern "C" const float lbl_53_rodata_0[];
extern "C" u32 lbl_53_data_0;
extern "C" void startEntity__8grMadeinFv(Entity*);
extern "C" float randf__Fv();
extern "C" int playSeBasic__7stMeleeF5SndIDf(Stage*, int, float);
extern "C" void fn_27_279FC8(Entity*, const Matrix*, int);
extern "C" void setFrame__16gfModelAnimationFd(void*, double);
extern "C" void fn_8003F074(Matrix*, float, float, float);
extern "C" void setMotion__8grMadeinFUl(Entity*, u32);
extern "C" void startEntityAutoLoop__8grMadeinFv(Entity*);

extern "C" void fn_53_129C(Stage* self, const Matrix* matrix, int init) {
    const float* constants = lbl_53_rodata_0;
    if (init) {
        self->flag229 = 1;
        self->value22c = lbl_53_data_0;
        self->value230 = 0;
        startEntity__8grMadeinFv(self->e208);
        startEntity__8grMadeinFv(self->e204);
        self->value2dc = constants[0];
        float r = randf__Fv();
        self->value5d4 = 0;
        self->value5d8 = constants[22] + (constants[21] - constants[20] * r);
        self->value5dc = playSeBasic__7stMeleeF5SndIDf(self, 0x1BB1, constants[0]);
    }

    self->matrix294 = self->matrix264 = *matrix;
    self->e1fc->show(1);
    fn_27_279FC8(self->e1fc, &self->matrix264, 0);

    void* animation = self->e1fc->animations[0];
    if (animation) {
        setFrame__16gfModelAnimationFd(animation, constants[0]);
        self->value5d0 = 0;
    }

    Matrix m = self->matrix264;
    fn_8003F074(&m, self->x2d0, self->y2d4, self->z2d8);
    fn_27_279FC8(self->e208, &m, 0);

    self->e1f8->show(1);
    fn_27_279FC8(self->e1f8, &self->matrix264, 0);

    Matrix n = self->matrix264;
    fn_8003F074(&n, self->x378, self->y37c, self->z380);
    fn_27_279FC8(self->e204, &n, 0);

    if (init) {
        self->value384 = 0;
        setMotion__8grMadeinFUl(self->e1f8, 0);
        startEntityAutoLoop__8grMadeinFv(self->e1f8);
        void* animation = self->e1f8->animations[0];
        if (animation)
            setFrame__16gfModelAnimationFd(animation, constants[0]);
    }
}
