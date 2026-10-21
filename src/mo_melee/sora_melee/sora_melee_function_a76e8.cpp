#pragma force_active on
extern "C" char lbl_27_data_157A0[];
extern "C" char lbl_27_data_157D8[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_80011528(void*, void*, float);

struct Vec2 {
    float x, y;
    void set(float b, float a) { x = a; y = b; }
};

struct Object {
    int unk0;
    void* obj;
    int unk8;
    Vec2 position;
    float value;
};

extern "C" void fn_27_A76E8(Object* dest, Vec2* src, float value) {
    void* casted = __dynamic_cast(dest->obj, 0x44, lbl_27_data_157A0, lbl_27_data_157D8, 1);
    fn_80011528(casted, src, value);
    dest->position.set(src->y, src->x);
    dest->value = value;
}
