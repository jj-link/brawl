#pragma force_active on
struct Vec3f { float x, y, z; };
struct Model { char pad[0xE8]; void* data; };

struct Object {
    char pad0[0x3C];
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
    virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29();
    virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
    virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
    virtual void getPos(Vec3f*, int, int);
    virtual void u49();
    virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59();
    virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69();
    virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79();
    virtual void u80(); virtual void u81();
    virtual void changeAnim(int, int);
    virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89();
    virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99();
    virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109();
    virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114();
    virtual float duration();

    char pad1[4];
    Model** models;
    void** animations;
    char pad2[0x164 - 0x4C];
    Model* model;
    void* data;
    void* animation;
    unsigned char pad3;
    unsigned char state;
    char pad4[0x184 - 0x172];
    char generator[4];
};

extern "C" const float lbl_56_rodata_58[6];
extern "C" float lbl_56_bss_18;

extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

extern "C" void fn_56_2368(Object* self, float delta) {
    Vec3f pos;
    const float* constants = lbl_56_rodata_58;
    float t;

    self->model = *self->models;
    self->data = self->model->data;
    self->animation = *self->animations;

    switch (self->state) {
    case 0:
        break;
    case 1:
        self->changeAnim(0, 0);
        setUpdateRate__16gfModelAnimationFf(self->animation, delta);
        lbl_56_bss_18 = constants[4];
        playSE__14snd3DGeneratorF5SndIDiii(self->generator, 0x1BE0, 0, 0, -1);
        self->state = 2;
    case 2:
        t = lbl_56_bss_18 - delta;
        lbl_56_bss_18 = t;
        if (t <= constants[0])
            self->state = 3;
        break;
    case 3:
        self->changeAnim(2, 0);
        setUpdateRate__16gfModelAnimationFf(self->animation, delta);
        lbl_56_bss_18 = self->duration();
        self->state = 4;
    case 4:
        t = lbl_56_bss_18 - delta;
        lbl_56_bss_18 = t;
        if (t <= constants[0])
            self->state = 5;
        break;
    case 5:
        self->changeAnim(4, 0);
        setUpdateRate__16gfModelAnimationFf(self->animation, delta);
        lbl_56_bss_18 = constants[5];
        self->state = 6;
    case 6:
        t = lbl_56_bss_18 - delta;
        lbl_56_bss_18 = t;
        if (t <= constants[0])
            self->state = 0;
        break;
    }

    self->getPos(&pos, 0, 1);
    setPos__14snd3DGeneratorFP5Vec3f(self->generator, &pos);
}
