#include <gr/gr_yakumono.h>
#pragma force_active on

extern "C" void fn_27_263780(void* self, void* arg);

void grYakumono::setSleepHit(bool isSleep) {
    if (m_yakumono != 0) {
        fn_27_263780(m_yakumono, (void*)(u32)isSleep);
    }
}
