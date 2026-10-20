#include <types.h>
#pragma force_active on

class ipSwitch {
public:
    static ipSwitch* getInstance();
    u8 pad[0x18];
    void* m_18;
};

extern "C" void fn_8004B304(void*);

extern "C" {
void fn_27_25578C() {
    fn_8004B304(ipSwitch::getInstance()->m_18);
}
}
