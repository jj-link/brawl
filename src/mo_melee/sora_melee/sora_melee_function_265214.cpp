#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2637E8(void* obj, int a, int b, int c);

class grYakumono {
public:
    bool disableHit(u32 a, u32 b);
    char pad[0x14c];
    void* m_obj;
};

bool grYakumono::disableHit(u32 a, u32 b) {
    if (m_obj == 0) {
        return false;
    }
    fn_27_2637E8(m_obj, a, 3, b);
    return true;
}
