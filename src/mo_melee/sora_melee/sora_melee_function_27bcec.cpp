#pragma force_active on
typedef float f32;
typedef int s32;

extern "C" float randf__Fv();
extern const f32 lbl_27_rodata_4598;

class grTenganEvent {
public:
    f32 m_00;
    f32 m_04;
    f32 m_08;
    f32 m_0c;
    f32 m_10;
    unsigned char _14[0xa4 - 0x14];
    s32 m_a4;
    s32 m_a8;

    bool start();
};

bool grTenganEvent::start() {
    if (m_a4 == 0) {
        m_0c = m_04 + (m_08 - m_04) * randf__Fv();
        m_a4 = 1;
        m_a8 = 0;
        m_10 = lbl_27_rodata_4598;
        m_00 = lbl_27_rodata_4598;
        return true;
    }
    return false;
}
