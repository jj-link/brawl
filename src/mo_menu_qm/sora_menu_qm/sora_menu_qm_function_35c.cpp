#pragma force_active on
extern "C" {
extern char lbl_4_data_560[];
extern char lbl_4_data_568[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}
struct Scene {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void remove(int);
    char pad[0xE0];
    int count;
};
struct Object { char pad[0xc]; void* model; };
struct Menu {
    char pad[0x2d4];
    Object* a;
    Object* b;
    Object* c;
    Object* d;
    char pad2[8];
    Object* e;
    char pad3[0x68];
    Scene* scene;
    void* x;
    void* y;
    void* z;
};
extern "C" void fn_4_35C(Menu* self, int mode) {
    switch (mode) {
    case 1: {
        Scene* scene = self->scene;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->a->model, lbl_4_data_560);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->y, lbl_4_data_568);
        break;
    }
    case 2: {
        Scene* scene = self->scene;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->b->model, lbl_4_data_560);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->c->model, lbl_4_data_560);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->y, lbl_4_data_568);
        break;
    }
    case 3: {
        Scene* scene = self->scene;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->b->model, lbl_4_data_560);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->c->model, lbl_4_data_560);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->d->model, lbl_4_data_568);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->x, lbl_4_data_568);
        break;
    }
    case 4: {
        Scene* scene = self->scene;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->e->model, lbl_4_data_560);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->z, lbl_4_data_568);
        break;
    }
    }
}