#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class Stage {
public:
    void getRandItemPos(Vec3f* pos);
};

extern const float lbl_27_rodata_33D8;
extern "C" void fn_27_226E2C(void* obj, Vec3f* pos);

void Stage::getRandItemPos(Vec3f* pos) {
    pos->z = lbl_27_rodata_33D8;
    pos->y = lbl_27_rodata_33D8;
    pos->x = lbl_27_rodata_33D8;
    void* obj = *(void**)((char*)this + 0x90);
    if (obj != 0) {
        fn_27_226E2C(obj, pos);
    }
}
