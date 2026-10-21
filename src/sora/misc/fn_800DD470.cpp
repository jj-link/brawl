#include <if/if_mngr.h>
#pragma force_active on

extern "C" {
    extern void fn_800DC824(IfMngr*);
    void fn_800DD470(void);
}

void fn_800DD470(void) {
    fn_800DC824(g_IfMngr);
}
