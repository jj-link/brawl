#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Module {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual int has(int);
    virtual void set(float);
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual Vec3 get(int);
};

struct Accesser {
    char pad0[8];
    Module* posture;
    char pad1[0x48];
    Module* ground;
};

struct Object {
    char pad[0xd8];
    Accesser* accesser;
};

extern "C" const float lbl_110_rodata_18[];

extern "C" void fn_110_D9D0(void*, Object* object) {
    const float* constants = lbl_110_rodata_18;
    Accesser* a = object->accesser;
    Module* posture = a->posture;
    Module* ground = a->ground;

    if (ground->has(6)) {
        const Vec3& v = ground->get(6);
        float f = constants[2] + v.x;

        if (f < constants[0])
            f = constants[0];
        else if (f > constants[3])
            f = constants[3];

        posture->set(f);
    }
}
