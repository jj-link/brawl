#pragma force_active on
extern "C" {
extern char lbl_14_data_3DC[];
extern const float lbl_14_rodata_0;
extern const float lbl_14_rodata_200;

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setFrameVisible__8MuObjectFf(void*, float);
}

struct Scene {
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
    virtual void remove(int);

    char pad[0xE0];
    int count;
};

struct Object {
    char pad[0x10];
    void* model;
};

struct Menu {
    char pad0[0xB0];
    void* object;
    char pad1[4];
    Object* first;
    Object* second;
    char pad2[0x124];
    Scene* scene;
};

extern "C" void fn_14_39BC(Menu* self, int mode) {
    Scene* scene = self->scene;
    while (scene->count != 0) {
        if (scene->count != 0) {
            scene->remove(scene->count - 1);
        }
    }

    float frame;
    if (mode == 0) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            scene, self->first->model, lbl_14_data_3DC);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            scene, self->second->model, lbl_14_data_3DC);
        frame = lbl_14_rodata_0;
    } else {
        frame = lbl_14_rodata_200;
    }

    setFrameVisible__8MuObjectFf(self->object, frame);
}
