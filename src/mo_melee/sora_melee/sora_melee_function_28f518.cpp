#pragma force_active on
typedef unsigned int u32;

class TeamOwner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual u32 getTeamOwnerTaskId();
};

class BaseItem {
    unsigned char padding[0xF60];
    TeamOwner teamOwner;

public:
    u32 getTeamOwnerTaskId();
};

u32 BaseItem::getTeamOwnerTaskId() {
    return teamOwner.getTeamOwnerTaskId();
}
