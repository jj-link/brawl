#pragma force_active on
class SSub {
public:
    virtual void sv0();
    virtual void sv1();
    short m_unk;
    unsigned char m_flag;
};

class SMain {
public:
    char data1[0x40];
    SSub m_sub1;
    char data2[0x54];
    SSub m_sub2;
    SSub m_sub3;
};

extern "C" void fn_40_173F4(SMain* self) {
    if (self->m_sub1.m_flag)
        self->m_sub1.sv1();
    if (self->m_sub2.m_flag)
        self->m_sub2.sv1();
    if (self->m_sub3.m_flag)
        self->m_sub3.sv1();
}