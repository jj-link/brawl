#pragma force_active on
class BaseItem;
struct Vec3f;

class BaseItem {
public:
    int sendTouchMessage(int, Vec3f*, float);
};

extern const float lbl_27_rodata_46DC;

extern "C" int fn_27_29BE64(int, BaseItem* item, int kind, int, Vec3f* pos) {
    item->sendTouchMessage(kind, pos, lbl_27_rodata_46DC);
    return 0;
}
