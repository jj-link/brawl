#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_33D8;

struct Inner {
    float _0;
    float _4;
};
struct GameGlobal {
    char _pad[0x44];
    Inner* _44;
};
extern GameGlobal* g_GameGlobal;
}

class Stage {
    char _pad[0xc8];
    float m_c8;
    float m_cc;
    float m_d0;
    float m_d4;
public:
    void setMotionRatio(float a, float b);
};

void Stage::setMotionRatio(float a, float b) {
    if (lbl_27_rodata_33D8 == b) {
        g_GameGlobal->_44->_4 = a;
        m_c8 = lbl_27_rodata_33D8;
        m_cc = lbl_27_rodata_33D8;
        m_d0 = lbl_27_rodata_33D8;
        m_d4 = lbl_27_rodata_33D8;
    } else {
        m_c8 = g_GameGlobal->_44->_4;
        m_cc = a;
        m_d0 = lbl_27_rodata_33D8;
        m_d4 = b;
    }
}
