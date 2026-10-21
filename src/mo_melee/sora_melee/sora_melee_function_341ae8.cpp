#pragma force_active on

extern float lbl_27_rodata_77D8;
extern float lbl_27_rodata_77E0;

struct Vec3 {
    float x, y, z;

    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Motion {
    virtual ~Motion();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Vec3 slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(Vec3*, int);
};

struct Other {
    virtual ~Other();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot8(int, const Vec3*, const Vec3*, int, int, float);
};

struct Modules {
    char padding0[0xC];
    Motion* motion;
    char padding1[0x78];
    Other* other;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_341AE8(void*, Object* obj, int kind) {
    if (kind != 3) {
        Modules* mods = obj->modules;
        Motion* motion = mods->motion;
        Other* other = mods->other;

        Vec3 a;
        a.x = lbl_27_rodata_77E0;
        a.y = lbl_27_rodata_77E0;
        a.z = lbl_27_rodata_77E0;
        motion->slot17(&a, 0);

        other->slot8(
            0x22,
            &motion->slot6(),
            &Vec3(lbl_27_rodata_77E0, lbl_27_rodata_77E0, lbl_27_rodata_77E0),
            0,
            -1,
            lbl_27_rodata_77D8
        );
    }
}
