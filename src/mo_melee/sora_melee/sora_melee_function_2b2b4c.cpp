#include <types.h>
#pragma force_active on

class soArchiveDb {
public:
    static soArchiveDb* getManager(u32 index);
};

struct FnArg {
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_C;
};

extern "C" int fn_80045DC0(void* manager, u32 value, int flag);

extern "C" bool fn_27_2B2B4C(FnArg* arg) {
    if (arg->m_C == 0xFFFF) {
        return true;
    }
    return fn_80045DC0(soArchiveDb::getManager(2), arg->m_C, 0) != 0;
}
