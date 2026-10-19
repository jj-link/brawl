#include <types.h>
#pragma force_active on

extern "C" void fn_27_263A48(u8* self, u32 arg);

class grYakumono {
public:
    u8 m_pad[0x14C];
    u8* m_target;
    bool setSleepArea(bool flag);
};

bool grYakumono::setSleepArea(bool flag) {
    if (m_target == nullptr) {
        return false;
    }
    fn_27_263A48(m_target, flag);
    return true;
}
