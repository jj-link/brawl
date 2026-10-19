#include <types.h>
#pragma force_active on

class tyFigListDataManager {
public:
    void getBilTexNameFigId(u32 id, char* name);
};

extern char lbl_27_bss_72F8[0x20];

extern "C" {
char* fn_27_2C1C48(u32* p, u32 id) {
    ((tyFigListDataManager*)p[1])->getBilTexNameFigId(id, lbl_27_bss_72F8);
    return lbl_27_bss_72F8;
}
}
