#include <gm/gm_global.h>
#pragma force_active on
struct FrameInfo { u8 pad0[4]; u32 unk4; u8 unk8; u8 pad9; u8 unkA; };
f32 GameGlobal::getGameFrame() const {
    FrameInfo* info = reinterpret_cast<FrameInfo*>(m_appData);
    return (f32)info->unk4 + (f32)info->unkA / (f32)info->unk8;
}