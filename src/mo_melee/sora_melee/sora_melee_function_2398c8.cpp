#include <st/st_melee.h>
#include <types.h>
#pragma force_active on

extern "C" bool fn_27_239664(int id, Vec3f* out, int kind);

bool stMelee::getPlayerPosition(int playerNo, Vec3f* pos) {
    return fn_27_239664(playerNo, pos, 0);
}
