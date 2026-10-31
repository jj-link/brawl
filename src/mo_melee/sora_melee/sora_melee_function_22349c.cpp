#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

class Stage;

extern "C" void fn_27_22736C(void* obj, u32 idx, Vec3f* pos);
extern const float lbl_27_rodata_33D8;

class Stage {
public:
    char pad_0000[0x90];
    void* m_unk90;
    void getPokeTrainerStartPos(Vec3f* pos, u32 idx);
};

void Stage::getPokeTrainerStartPos(Vec3f* pos, u32 idx) {
    float zero = lbl_27_rodata_33D8;
    pos->z = zero;
    pos->y = zero;
    pos->x = zero;
    if (idx < 4 && m_unk90 != nullptr) {
        fn_27_22736C(m_unk90, idx, pos);
    }
}
