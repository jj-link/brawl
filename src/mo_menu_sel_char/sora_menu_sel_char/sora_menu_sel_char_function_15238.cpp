#include <types.h>
#pragma force_active on

struct TeamBattleData {
    char _0x0[0x5C8];
    u8 m_teamBattleType;
};

struct Test {
    char _0x0[0x1F4];
    TeamBattleData* m_data;
};

extern "C" {

u8 isTeamBattle__19muSelCharPlayerAreaFv(Test* area);

u8 isTeamBattle__19muSelCharPlayerAreaFv(Test* area) {
    return (area->m_data->m_teamBattleType);
}

}