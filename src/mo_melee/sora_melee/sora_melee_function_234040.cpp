#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

struct CBBASE {
    void* m_next;
};

class ObsCBFake : public CBBASE {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void setAreaSleep(bool sleep);
};

class stTrigger {
    char m_pad[0x18];
public:
    ObsCBFake* m_obsTriggerCB;
    void* m_yakumono;

    bool setAreaSleep(bool sleep);
};

extern "C" void fn_27_263A48(void* self, bool arg);

bool stTrigger::setAreaSleep(bool sleep) {
    if (m_obsTriggerCB) {
        m_obsTriggerCB->setAreaSleep(sleep);
        return true;
    }
    if (m_yakumono != nullptr) {
        fn_27_263A48(m_yakumono, sleep);
        return true;
    }
    return false;
}
