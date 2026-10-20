#include <types.h>
#pragma force_active on

class tyFigListDataManager {
public:
    u32 getFigDataId(u32 id);
};

struct fn_27_2C0E10_arg {
    u32 unk0;
    tyFigListDataManager* mgr;
};

extern "C" {
bool fn_27_2C0E10(fn_27_2C0E10_arg* p, u32 id) {
    if (id == 0x1388 || (id > 0x1389 && id < 0x1390)) {
        return false;
    }
    tyFigListDataManager* mgr = p->mgr;
    if (mgr == 0) {
        return false;
    }
    return mgr->getFigDataId(id) != 0;
}
}
