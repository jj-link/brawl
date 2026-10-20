#pragma force_active on
extern float lbl_27_data_547E0;

class grGimmickMotionPath {
public:
    char pad[0x64];
    float m_64;
    char pad2[0x158 - 0x68];
    float m_158;
    float m_15c;
    void setFrameUpdate(float);
};

void grGimmickMotionPath::setFrameUpdate(float f) {
    float v = m_64 * (f * lbl_27_data_547E0);
    m_158 = v;
    m_15c = v;
}
