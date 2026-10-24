#pragma force_active on

extern "C" void fn_800B753C(void*, float);
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);

extern const float lbl_805A2368;
extern const float lbl_805A2374;

class Target {
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
    virtual void v11(int, void*);
    virtual void v12();
    virtual void v13(void*);
    virtual void v14();
    virtual void v15();

    char pad[0xE4 - 4];
    int f_e4;
};

struct Item {
    char pad[0x10];
    void* data;
};

struct Model {
    char pad[0x10];
    void* f10;
    void* animation;
};

struct Ctx {
    char pad0[8];
    Target* target;
    char pad1[0x68 - 0x0C];
    Model* model;
};

extern "C" void fn_800DF168(Ctx* self) {
    int i;
    Model* m = self->model;
    setUpdateRate__16gfModelAnimationFf(m->animation, lbl_805A2368);
    fn_800B753C(m, lbl_805A2374);

    char* p = (char*)self + 0x34;
    for (i = 13; i < 24; i++, p += 4) {
        Item* it = *(Item**)(p + 0x10);
        if (it != 0) {
            self->target->v13(it->data);
        }
    }

    self->target->v11(self->target->f_e4, m->f10);
}
