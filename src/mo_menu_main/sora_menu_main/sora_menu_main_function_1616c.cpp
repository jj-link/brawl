#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec3f {
    float x, y, z;

    Vec3f& operator=(const Vec3f& p) {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }
};

struct Model {
    char pad0[0x10];
    void* scene;
    char pad14[0x28];
    Vec3f pos;
};

struct Models {
    char pad[0x48];
    Model* objects[3];
};

struct SceneBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void attach(void*, void*);
};

struct Scene : SceneBase {
    char pad4[0xE0];
    void* root;
};

struct Control {
    char pad[0x3C];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void set(int, int);
};

struct Menu {
    char pad0[0x42];
    u16 target;
    char pad44[0x5F4];
    int state;
    u16* data;
    u16 count;
    u16 pad642;
    int base;
    int value;
    Models* models;
    char pad650[4];
    Scene* scene;
    Control* control;
    char pad65C[8];
    int mode;
    char pad668[4];
    int field66C;
    bool enabled;
};

extern "C" {
extern u16 lbl_2_data_1F00[];
extern float lbl_2_rodata_5D0;
extern float lbl_2_rodata_5D4;

void fn_8014FEFC();
u32 fn_8014FEDC(u32);
void fn_800B6838(Model*, const Vec3f*);
void fn_18_1C4C(Menu*, int);
int fn_18_1A9C(Menu*);
void fn_18_1D48(Menu*, int, int);

void fn_2_1616C(Menu* self, Scene* scene, int arg) {
    self->data = lbl_2_data_1F00;
    self->scene = scene;
    self->base = 0x12;
    self->field66C = 0;
    fn_8014FEFC();

    self->enabled =
        fn_8014FEDC(0x20) == 1 ? true : fn_8014FEDC(0x40) == 1;

    for (u32 i = 0; i < 3; ++i) {
        if (self->enabled || i != 2)
            scene->attach(scene->root, self->models->objects[i]->scene);
    }

    if (self->enabled == 1) {
        lbl_2_data_1F00[0] = 2;
        lbl_2_data_1F00[2] = 2;
        lbl_2_data_1F00[8] = 2;
        lbl_2_data_1F00[10] = 2;
    }

    if (self->enabled == 0) {
        lbl_2_data_1F00[0] = 0;
        lbl_2_data_1F00[2] = 0;
        lbl_2_data_1F00[8] = 1;
        lbl_2_data_1F00[10] = 1;
    }

    float y = self->enabled ? lbl_2_rodata_5D0 : lbl_2_rodata_5D4;
    Vec3f pos;

    pos = self->models->objects[0]->pos;
    pos.y = y;
    fn_800B6838(self->models->objects[0], &pos);

    pos = self->models->objects[1]->pos;
    pos.y = y;
    fn_800B6838(self->models->objects[1], &pos);

    switch (arg) {
    case 0:
        self->mode = 0;
        self->target = 0;
        self->state = 0;
        fn_18_1C4C(self, 1);
        break;

    case 0x1A:
        self->mode = 1;
        self->target = 0;
        self->state = 0x1A;
        fn_18_1C4C(self, 1);
        break;

    case 0x1B:
        self->mode = 1;
        self->target = 1;
        self->state = 0x1B;
        fn_18_1C4C(self, 1);
        break;

    case 0x1C:
        self->mode = 1;
        self->target = 2;
        self->state = 0x1C;
        fn_18_1C4C(self, 1);
        break;

    default:
        self->mode = 2;
        switch (fn_18_1A9C(self)) {
        case 0x22:
            arg = 0;
            break;
        case 0x23:
            arg = 1;
            break;
        }
        self->target = arg;
        fn_18_1D48(self, arg, 1);
        self->state = 0x22;
        break;
    }

    self->control->set(9, self->target + 0x12);
}
}
