#pragma force_active on
class Stage {
public:
    void saveMotionRatio(int p);
    char pad[0xc8];
    float m_c8;
    float m_cc;
    float m_d0;
    float m_d4;
};

void Stage::saveMotionRatio(int p) {
    float* out = (float*)p;
    out[0] = m_c8;
    out[1] = m_cc;
    out[2] = m_d0;
    out[3] = m_d4;
}
