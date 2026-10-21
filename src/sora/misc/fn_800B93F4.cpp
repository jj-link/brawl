#pragma force_active on
class MuMsg {
public:
    void setFontWidthModeAuto(unsigned long mode);

private:
    int m_pad[3];
    char* m_entries;
};

void MuMsg::setFontWidthModeAuto(unsigned long mode) {
    unsigned long* p = (unsigned long*)(m_entries + mode * 0x48);
    *p &= ~0x0C000000UL;
}
