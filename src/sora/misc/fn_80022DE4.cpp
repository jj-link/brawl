#include <types.h>
#pragma force_active on

class ipSwitch {
public:
    static ipSwitch* getInstance();
    u8 pad[0x18];
    void* m_18;
};

extern "C" void fn_8004B780(void*, void*);
extern "C" void* lbl_8059FFF0;

extern "C" void fn_80022DE4() {
    fn_8004B780(ipSwitch::getInstance()->m_18, &lbl_8059FFF0);
}
