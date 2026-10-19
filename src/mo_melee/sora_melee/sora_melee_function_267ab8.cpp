#pragma force_active on
class Ground {
public:
    void preExit();
};

class grYakumono : public Ground {
public:
    void preExit();

private:
    char m_pad[0x14b];
    void* m_0x14c;
};

extern "C" void fn_27_263464(void* p);

void grYakumono::preExit() {
    Ground::preExit();
    if (m_0x14c) {
        fn_27_263464(m_0x14c);
    }
}
