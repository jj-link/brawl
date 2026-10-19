#include <ac/ac_anim_cmd_impl.h>
#pragma force_active on

extern "C" bool fn_27_ACF24(const acAnimCmd* cmd) {
    return cmd->getArgNum() == 0;
}
