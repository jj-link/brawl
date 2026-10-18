#include <types.h>
#pragma force_active on

extern "C" {

struct Stage {
    u8 _spacer[0x184];
    u8 m_unk2;
    u32 m_unk3;
    f32 m_unk4;
};

void fn_83_2C50(Stage* stage, u8 arg1, u32 arg2, f32 arg3)
{
    stage->m_unk2 = arg1;
    stage->m_unk3 = arg2;
    stage->m_unk4 = arg3;
}

}
