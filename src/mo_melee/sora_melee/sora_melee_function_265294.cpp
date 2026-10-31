#pragma force_active on
extern "C" void fn_27_263768(void* p);

class grYakumono {
public:
    char pad[0x14c];
    void* m_unk14c;

    void setSleepAttack(bool flag);
};

void grYakumono::setSleepAttack(bool flag) {
    if (m_unk14c == 0) {
        return;
    }
    return fn_27_263768(m_unk14c);
}
