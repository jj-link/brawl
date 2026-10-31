#include <types.h>
#pragma force_active on

extern "C" void fn_800479A8(void* obj, void* arg);

class soModelModuleImpl {
public:
    void clearSetUpMtx();

    u8 pad_00[0x0C];
    void* m_0c;
    u8 pad_10[0xA8 - 0x10];
    void* m_a8;
    u8 pad_ac[0xC2 - 0xAC];
    s8 m_c2;
    u8 pad_c3[0xC5 - 0xC3];
    u8 m_c5;
};

void soModelModuleImpl::clearSetUpMtx() {
    if (m_c2 != 1) {
        return;
    }
    if ((m_c5 >> 6) & 1) {
        return;
    }
    void* obj = m_0c;
    m_c2 = 0;
    if (obj != nullptr) {
        fn_800479A8(obj, m_a8);
    }
}
