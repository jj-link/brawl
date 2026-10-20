#pragma force_active on
extern "C" {
extern unsigned char lbl_2_rodata_B40[];
extern char lbl_2_data_2F60[];
extern char lbl_2_data_2F68[];
extern void* g_GameGlobal;

int fn_8004D148(void*);
void setFrameVisible__8MuObjectFf(void*, float);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

struct Scene {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void remove(void*);
};

struct Anim {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void frame(float);
};

struct Model {
    char pad[8];
    Anim* anim;
};

struct Object {
    char pad[0x10];
    void* node;
    Model* model;
};

struct Objects {
    char pad[0x220];
    Object* visible;
    char gap[4];
    Object* left;
    Object* right;
};

struct SceneHolder {
    char pad[0x34];
    Scene* scene;
};

struct Menu {
    char pad[0x64c];
    Objects* objects;
    SceneHolder* holder;
    char gap[0x1c];
    int index;
};

extern "C" void fn_2_26520(Menu* self, int show) {
    float* values = (float*)lbl_2_rodata_B40;
    Object* object = self->objects->visible;
    int left = 0;
    int right = 0;

    self->holder->scene->remove(self->objects->left->node);
    self->holder->scene->remove(self->objects->right->node);

    object->model->anim->frame(values[0x260 / 4]);
    setFrameVisible__8MuObjectFf(object, values[0x260 / 4]);

    if (show) {
        if (self->index > 0) {
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                self->holder->scene,
                self->objects->left->node,
                lbl_2_data_2F60);
            left = 1;
        }

        bool extra = fn_8004D148(g_GameGlobal) > 0;
        int current = self->index;
        if (current < extra + 2) {
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                self->holder->scene,
                self->objects->right->node,
                lbl_2_data_2F68);
            right = 1;
        }

        float frame;
        if (left) {
            if (right)
                frame = values[0x294 / 4];
            else
                frame = values[0x298 / 4];
        } else {
            if (right)
                frame = values[0x280 / 4];
            else
                frame = values[0x260 / 4];
        }
        setFrameVisible__8MuObjectFf(object, frame);
    }
}
