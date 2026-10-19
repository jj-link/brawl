#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

extern const float lbl_27_rodata_4388;

struct grGimmickEffect {
    s16 m_state;
    s16 unk2;
    f32 m_time;
    s32 unk8;
    s32 m_flag;
    u8 unk10[0x28 - 0x10];
};

class grGimmick {
public:
    void startGimmickEffect(unsigned long idx);

    u8 unk0[0xb0];
    grGimmickEffect* m_effects;
};

void grGimmick::startGimmickEffect(unsigned long idx) {
    if (m_effects[idx].m_flag == 0) {
        return;
    }
    m_effects[idx].m_state = 1;
    m_effects[idx].m_time = lbl_27_rodata_4388;
}
