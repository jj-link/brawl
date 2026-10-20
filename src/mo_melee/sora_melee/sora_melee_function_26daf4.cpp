#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" void fn_27_261908(grGimmick* gimmick, u32 value);

void grGimmick::setTransparency(u32 unk1, u32 unk2) {
    if (unk2 & 0x10) {
        setVisibilityByClipping(unk1);
    }
    if (unk2 & 1) {
        fn_27_261908(this, unk1);
    }
    *(u8*)&m_transparencyFlag = unk1;
}
