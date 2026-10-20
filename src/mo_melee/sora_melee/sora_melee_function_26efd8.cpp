#pragma force_active on
class grGimmickMotionPath {
public:
    bool isStartFrame();

private:
    char pad_0[0x150];
    float m_150;
    char pad_154[4];
    float m_158;
};

bool grGimmickMotionPath::isStartFrame() {
    return m_150 <= m_158;
}
