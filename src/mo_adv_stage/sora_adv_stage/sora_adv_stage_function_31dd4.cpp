#include <sora_adv_stage/gr_adventure_final.h>
#pragma force_active on

extern "C" void fn_40_278C0(grYakumono* self);

extern "C" void fn_40_31DD4(grYakumono* r3) {
    fn_40_278C0(r3);
    r3->grYakumono::disableAttack(0);
    r3->grYakumono::setTeamYakumono(0x11, -1);
}
