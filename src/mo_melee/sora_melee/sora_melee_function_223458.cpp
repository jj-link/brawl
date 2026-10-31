#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

class Stage {
public:
    void getFighterReStartPos(Vec3f* pos, int idx);
};

extern const float lbl_27_rodata_33D8;

extern "C" void fn_27_227174(void* a, int b, Vec3f* c);

void Stage::getFighterReStartPos(Vec3f* pos, int idx) {
    float zero = lbl_27_rodata_33D8;
    pos->z = zero;
    pos->y = zero;
    pos->x = zero;
    if ((u32)idx >= 4) {
        return;
    }
    void* p = *(void**)((char*)this + 0x90);
    if (p == nullptr) {
        return;
    }
    fn_27_227174(p, idx, pos);
}
