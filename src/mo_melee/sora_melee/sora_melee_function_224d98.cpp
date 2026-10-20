#pragma force_active on
typedef unsigned char u8;

class Stage {
public:
    void setStageInEffectInit();
private:
    u8 m_pad[0xe9];
    u8 m_e9;
    u8 m_ea;
};

void Stage::setStageInEffectInit() {
    m_e9 = 1;
    m_ea = 1;
}
