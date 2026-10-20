#pragma force_active on
struct Vec3f {
    float x, y, z;
};

class Effect {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void spawn(unsigned int, Vec3f*, Vec3f*, int, float);
};

struct Modules {
    char pad[0x88];
    Effect* effect;
};

struct Accessor {
    char pad[0xD8];
    Modules* modules;
};

struct Item {
    char pad[0x60];
    Accessor* accessor;
};

extern "C" {
extern const float lbl_27_rodata_46DC;
extern const float lbl_27_rodata_46C8;

void fn_27_29FB28(void*, Item* item, int kind) {
    if (kind == 11) {
        Vec3f position;
        Vec3f rotation;
        rotation.x = lbl_27_rodata_46DC;
        rotation.y = lbl_27_rodata_46DC;
        rotation.z = lbl_27_rodata_46DC;
        position.x = lbl_27_rodata_46DC;
        position.y = lbl_27_rodata_46DC;
        position.z = lbl_27_rodata_46DC;

        Effect* effect = item->accessor->modules->effect;
        effect->spawn(0xCC0003, &position, &rotation, 6, lbl_27_rodata_46C8);
    }
}
}
