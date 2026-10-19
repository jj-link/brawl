#pragma force_active on
struct Vec3f {
    float x, y, z;
};

class BaseItem {
public:
    void sendTouchMessage(int, Vec3f*, float);
};

extern "C" {
extern const float lbl_27_rodata_46DC;
}

extern "C" int fn_27_29BE9C(int, BaseItem* item, int kind, int, Vec3f* pos, float) {
    item->sendTouchMessage(kind, pos, lbl_27_rodata_46DC);
    return 0;
}
