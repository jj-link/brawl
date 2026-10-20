#include <gr/gr_yakumono.h>
#pragma force_active on

extern "C" {
    void getPos__9grGimmickFv(Vec3f* out, void* self);
    void fn_27_2632F4(void* obj, Vec3f* pos, float f1, float f2);
    void fn_27_2637E8(void* obj, u32 a, u32 b, u32 c);
}

extern const float lbl_27_rodata_42C8;
extern const float lbl_27_rodata_42CC;

bool grYakumono::enableYakumono(u32 unk1) {
    Yakumono* yakumono = m_yakumono;
    if (yakumono == 0) {
        return false;
    }
    Vec3f pos;
    getPos__9grGimmickFv(&pos, this);
    fn_27_2632F4(yakumono, &pos, lbl_27_rodata_42C8, lbl_27_rodata_42CC);
    fn_27_2637E8(yakumono, unk1, 0, 0);
    return true;
}
