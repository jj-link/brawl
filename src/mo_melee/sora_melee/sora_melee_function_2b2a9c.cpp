#include <types.h>
#pragma force_active on

class soArchiveDb {
public:
    static soArchiveDb* getManager(u32 index);
};

extern "C" int fn_80045DC0(void* manager, int value, int flag);

struct FnArg2 {
    int m_0;
    int m_4;
    int m_8;
    unsigned int m_c;
};

extern "C" {
bool fn_27_2B2A9C(FnArg2* arg) {
    if (arg->m_c == 0xFFFF) {
        return false;
    }
    return fn_80045DC0(soArchiveDb::getManager(2), (int)arg->m_c, 0) != 0;
}
}
