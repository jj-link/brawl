#include <types.h>
#pragma force_active on

class YakumonoSub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void setTeamSub(s32 team, s32 flag);
};

class Yakumono {
public:
    void setTeam(int team);
};

void Yakumono::setTeam(int team) {
    YakumonoSub* sub = *(YakumonoSub**)(*(u8**)((u8*)this + 0x180) + 0x18);
    sub->setTeamSub(team, 1);
}
