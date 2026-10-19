#include <types.h>
#pragma force_active on

class soArchiveDb {
public:
    static soArchiveDb* getManager(u32 index);
};

struct FnArg {
    int m_0;
    int m_4;
};

extern "C" int fn_80045DC0(void* manager, int value, int flag);

extern "C" {
bool fn_27_2C2BD0(FnArg* arg) {
    return fn_80045DC0(soArchiveDb::getManager(2), arg->m_4, 0) != 0;
}
}
