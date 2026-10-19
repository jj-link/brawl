#include <ip/ip_switch.h>
#include <types.h>
#pragma force_active on

struct fn_27_flags {
    u8 _0 : 4;
    u8 m_bit : 1;
    u8 _1 : 3;
};

extern "C" void fn_27_2550F4(void* unused, u32 flag) {
    fn_27_flags* f = (fn_27_flags*)((u8*)ipSwitch::getInstance() + 0x24);
    f->m_bit = flag;
}
