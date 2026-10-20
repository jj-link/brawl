#pragma force_active on
extern const float lbl_27_rodata_5EBC;

struct Vec2 {
    float x;
    float y;
};

struct Object {
    unsigned int unk0;
    unsigned int unk4;
    Vec2 value;
};

extern "C" void fn_27_2B8218(Object* p) {
    Vec2 v;
    v.x = lbl_27_rodata_5EBC;
    v.y = lbl_27_rodata_5EBC;
    p->value = v;
}
