#include <types.h>
#pragma force_active on

struct ipSwitch {
    static ipSwitch* getInstance();
    char pad[0x18];
    void* m_18;
};

extern "C" void fn_8004B310(void* p1, s32 p2);

extern "C" {
void fn_27_255754(void* p1, s32 p2) {
    fn_8004B310(ipSwitch::getInstance()->m_18, p2);
}
}
