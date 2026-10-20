#pragma force_active on
struct stCollisionWork {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned short m_0c;
    unsigned char m_0e;

    void initialize();
};

void stCollisionWork::initialize() {
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_0e = 0;
}
