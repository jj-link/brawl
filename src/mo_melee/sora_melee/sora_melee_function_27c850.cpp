#pragma force_active on
struct Vec3f;

class Ground {
public:
    void getNodePosition(Vec3f* pos, unsigned long idx, const char* name);
};

extern "C" extern const char lbl_27_data_5AAC8[];

extern "C" void fn_27_27C850(Ground* ground, Vec3f* pos) {
    ground->getNodePosition(pos, 0, lbl_27_data_5AAC8);
}
