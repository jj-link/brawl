#pragma force_active on
extern "C" void stopGimmickSE__9grGimmickFUl(void*, unsigned long);
extern "C" void stopGimmickEffect__9grGimmickFUl(void*, unsigned long);

class grGimmickMotionPath {
public:
    void stopStartSE();
    char m_pad0[0xa8];
    int m_a8;
    char m_pad1[4];
    int m_b0;
};

void grGimmickMotionPath::stopStartSE() {
    if (m_a8 != 0) {
        for (unsigned long i = 0; i < 5; i++) {
            stopGimmickSE__9grGimmickFUl(this, i + 3);
        }
    }
    if (m_b0 != 0) {
        for (unsigned long i = 0; i < 5; i++) {
            stopGimmickEffect__9grGimmickFUl(this, i + 3);
        }
    }
}
