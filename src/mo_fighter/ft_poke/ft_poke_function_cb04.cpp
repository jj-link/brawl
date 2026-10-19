#pragma force_active on
struct Vec2fCopy {
    float x;
    float y;
};

struct VectorState {
    Vec2fCopy first;
    Vec2fCopy second;
};

extern "C" {
extern const float lbl_116_rodata_8;

void fn_116_CB3C(Vec2fCopy*, const Vec2fCopy*);
}

extern "C" void fn_116_CB04(VectorState* object) {
    Vec2fCopy zero;
    zero.x = lbl_116_rodata_8;
    zero.y = lbl_116_rodata_8;
    fn_116_CB3C(&object->second, &zero);
}
