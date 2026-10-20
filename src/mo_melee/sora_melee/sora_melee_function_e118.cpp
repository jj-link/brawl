#pragma force_active on
typedef unsigned char u8;

class soModelModuleImpl {
public:
    char _pad[0xC5];
    u8 m_flagA : 1;
    u8 m_flagB : 1;
    u8 m_flagC : 1;
    u8 m_disposeInstanceImm : 1;
    u8 m_flagE : 4;
    void setDisposeInstanceImm(bool imm);
};

void soModelModuleImpl::setDisposeInstanceImm(bool imm) {
    m_disposeInstanceImm = imm;
}
