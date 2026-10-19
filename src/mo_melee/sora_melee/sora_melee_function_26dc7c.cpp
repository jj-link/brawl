#include <gr/gr_gimmick.h>
#pragma force_active on

extern const float lbl_27_rodata_4388;

Vec3f grGimmick::getRot() {
    grGimmickMotionPath* path = *reinterpret_cast<grGimmickMotionPath**>(
        reinterpret_cast<char*>(this) + 0xd4);
    if (path) {
        return *reinterpret_cast<Vec3f*>(reinterpret_cast<char*>(path) + 0x14);
    }
    return Vec3f(lbl_27_rodata_4388, lbl_27_rodata_4388, lbl_27_rodata_4388);
}
