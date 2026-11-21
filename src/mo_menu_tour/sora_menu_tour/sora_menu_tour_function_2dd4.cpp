#pragma force_active on
extern "C" {
extern char lbl_3_data_110[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, const char*);
void fn_3_600(void*, void*, void*);
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

struct Obj {
    char pad[0xC];
    void* model;
};

struct Menu {
    char pad0[0x618];
    Obj* p618;
    char pad1[0x628 - 0x61C];
    Obj* p628;
    char pad2[0x91C - 0x62C];
    Scene* scene1;
    void* p920;
    Scene* scene2;
    char pad3[0x9C0 - 0x928];
    void** p9C0;
    char pad4[0x9E0 - 0x9C4];
    void* p9E0;
    void* p9E4;
};

extern "C" void fn_3_2DD4(Menu* self, int mode) {
    const char* data = lbl_3_data_110;
    switch (mode) {
    case 1: {
        Scene* scene = self->scene1;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene1, self->p618->model, data + 0x568);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene1, self->p920, data + 0x570);
        break;
    }
    case 2: {
        Scene* scene = self->scene1;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        Scene* scene2 = self->scene2;
        while (scene2->count != 0) {
            if (scene2->count != 0) scene2->remove(scene2->count - 1);
        }
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene1, *self->p9C0, data + 0x578);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene1, self->p920, data + 0x570);
        break;
    }
    case 3: {
        Scene* scene = self->scene1;
        while (scene->count != 0) {
            if (scene->count != 0) scene->remove(scene->count - 1);
        }
        fn_3_600(self->p9C0, self->p9E0, self->p9E4);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene2, *self->p9C0, data + 0x570);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene1, self->scene2, data + 0x568);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene1, self->p628->model, data + 0x570);
        break;
    }
    }
}