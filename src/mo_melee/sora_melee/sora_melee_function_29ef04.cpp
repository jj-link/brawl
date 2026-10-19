#pragma force_active on
struct Vec3f;

class BaseItem {
public:
    void sendTouchMessage(int, Vec3f*, float);
};

extern const float lbl_27_rodata_46DC;

extern "C" {
int fn_27_29EF04(void*, BaseItem* item, int kind, int, Vec3f* vec) {
    item->sendTouchMessage(kind, vec, lbl_27_rodata_46DC);
    return 0;
}
}
