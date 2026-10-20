#pragma force_active on
class itCounter {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int getCount();
};

class itManager {
public:
    static itManager* getInstance();
    char pad[0x6d8];
    itCounter m_counter;
};

extern "C" {
void* fn_27_2A8A00(itManager* mgr, int idx);
int fn_27_28E91C(void* owner);

int fn_96_199C0() {
    int i;
    for (i = 0; i < itManager::getInstance()->m_counter.getCount(); i++) {
        void* owner = fn_27_2A8A00(itManager::getInstance(), i);
        if (owner != 0) {
            if (fn_27_28E91C(owner) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
}
