#pragma force_active on
class StageData {
public:
    char pad[0xA4];
    float m_a4;
};

class Stage {
public:
    float getEnableZ();
private:
    char pad[0x98];
    StageData* m_98;
};

extern const float lbl_27_rodata_33D8;

float Stage::getEnableZ() {
    if (m_98 == 0) {
        return lbl_27_rodata_33D8;
    }
    return m_98->m_a4;
}
