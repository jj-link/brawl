#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct Range {
    char pad0[4];
    float lo;
    char pad8[8];
    float hi;
};

struct Base {
    char padding[0x3C];
};

struct Object : Base {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void getPos(Vec3f*, int, int);

    char pad40[0x124];
    Range* range164;
    char pad168[0x3C];
    int field1A4;
    char generator[4];
    char pad1AC[4];
    int handle1B0;
};

extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
extern "C" void stopSE__14snd3DGeneratorFll(void*, int, int);
extern float lbl_51_rodata_1B8;

extern "C" void fn_51_1121C(Object* self) {
    Vec3f pos;
    self->getPos(&pos, 0, self->field1A4);
    setPos__14snd3DGeneratorFP5Vec3f(self->generator, &pos);
    Range* r = self->range164;
    if (pos.y < lbl_51_rodata_1B8 + r->lo && pos.y > r->hi - lbl_51_rodata_1B8) {
        if (self->handle1B0 == -1) {
            self->handle1B0 = playSE__14snd3DGeneratorF5SndIDiii(self->generator, 0x1B8E, 0, 0x78, -1);
        }
    } else {
        int h = self->handle1B0;
        if (h != -1) {
            stopSE__14snd3DGeneratorFll(self->generator, h, 0x78);
            self->handle1B0 = -1;
        }
    }
}
