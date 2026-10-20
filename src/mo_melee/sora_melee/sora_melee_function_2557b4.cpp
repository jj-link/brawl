#include <types.h>
#pragma force_active on

class ipSwitch {
public:
    static ipSwitch* getInstance();
    u8 m_pad0[0x18];
    s32* m_ptr18;
    u8 m_pad1[0x24 - 0x1C];
    u8 m_flag24;
};

extern "C" bool fn_27_2557B4() {
    bool result = true;
    if (*ipSwitch::getInstance()->m_ptr18 != 1) {
        if (!((ipSwitch::getInstance()->m_flag24 >> 7) & 1)) {
            result = false;
        }
    }
    return result;
}
