#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
// fn_8004D148 in the original executable; tail-called by fn_2_1EF48.
extern void fn_8004D148(GameGlobal*);

void fn_2_1EF48()
{
    fn_8004D148(g_GameGlobal);
}
}
