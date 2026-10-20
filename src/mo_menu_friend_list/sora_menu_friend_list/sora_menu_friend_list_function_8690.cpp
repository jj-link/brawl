#pragma force_active on

extern "C" {
extern char lbl_14_data_570[];
extern double fn_80400B3C(float, double);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setFrameVisible__8MuObjectFf(void*, float);
int sprintf(char*, const char*, ...);
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
    virtual void v12();
    virtual void pushback(void*);
};

struct Model {
    char pad[0x10];
    void* model;
};

struct RoData {
    float pad0[4];
    float f10;
    float pad1[3];
    double d20;
    float pad2[5];
    float f3c;
};

extern const RoData lbl_14_rodata_4D8;

struct Menu {
    char pad0[0xD4];
    void* objectD4;
    char pad1[0x180 - 0xD8];
    Model* model180;
    char pad2[0x1F4 - 0x184];
    Scene* scene;
    char pad3[0x2A08 - 0x1F8];
    float frame2A08;
    char pad4[0x2A18 - 0x2A0C];
    unsigned char flag2A18;
};

extern "C" void fn_14_8690(Menu* self, char* str, int param) {
    const RoData* rodata = &lbl_14_rodata_4D8;
    Scene* scene = self->scene;
    Model* model = self->model180;

    scene->pushback(model->model);

    if (self->flag2A18 == 0) {
        float x = self->frame2A08;
        int frame = (int)x;
        int digits = 6;
        if ((float)fn_80400B3C(x, rodata->d20) != rodata->f10) {
            digits = 7;
        }
        if (param >= frame && param < frame + digits) {
            char buf[8];
            sprintf(buf, lbl_14_data_570, str + (param - frame) * 6);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scene, model->model, buf);
        }
        setFrameVisible__8MuObjectFf(self->objectD4, rodata->f10);
    } else {
        setFrameVisible__8MuObjectFf(self->objectD4, rodata->f3c);
    }
}
