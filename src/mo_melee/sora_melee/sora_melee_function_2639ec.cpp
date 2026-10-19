#include <yk/yakumono.h>
#pragma force_active on

struct TeamObject;

struct TeamAccess {
    virtual void slot0();
    virtual void slot1();
    virtual TeamObject* get();
};

struct TeamObject {
    virtual void slot0();
    virtual void slot1();
    virtual int get();
};

int Yakumono::getTeam() {
    TeamAccess* access = *(TeamAccess**)((char*)this + 0x180);
    TeamAccess* object = *(TeamAccess**)((char*)access + 0x18);
    return object->get()->get();
}
