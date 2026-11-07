#include <ft/fighter.h>
#include <ft/ft_manager.h>
#include <gm/gm_global.h>
#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual int slot7(); virtual void slot8();
};
struct FtSub {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18();
    virtual int f21();
};
struct Pack {
    void* vt;
    short a, b;
    int c;
    unsigned long d;
};
struct Self {
    unsigned int unk0, unk4;
    char pad8[2];
    unsigned char active;
    char padB[3];
    unsigned char flags;
    char padF[0x19];
    void* p28;
    char pad2C[8];
    struct Pair { Fighter* fighter; unsigned int unk; } fighters[2];
    char pad44[8];
    Fighter* p4C;
    char pad50[8];
    int index;
};
extern "C" {
extern char lbl_27_data_261F0[], lbl_27_data_261B0[], lbl_27_data_26440[], __RTTI__11soEventUnit[];
extern float lbl_27_rodata_FB8, lbl_27_rodata_FBC;
void fn_27_111B7C(Vec3f*, void*);
int fn_27_112E20(void*);
void fn_27_15A880(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
inline int getUnit(soEventManager* m, short id) {
    Object_vptr_0* u = (Object_vptr_0*)__dynamic_cast(
        m->getEventUnit(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (u == 0)
        return 0;
    return u->slot7();
}
struct TeamFlagView {
    char pad[0x6e];
    unsigned char teams : 1;
};
inline bool isTeams(ftManager* m) {
    return ((TeamFlagView*)m)->teams;
}
extern "C" void fn_27_1153BC(Self* self) {
    Vec3f pos;
    fn_27_111B7C(&pos, self->p28);
    int kind = 5;
    char* result = (char*)g_GameGlobal->m_resultInfo;
    char* mode = (char*)g_GameGlobal->m_modeMelee;
    if ((unsigned char)result[0x1378] == 9) {
        unsigned long id;
        soEventManager* m;
        short n = (short)((FtSub*)((char*)g_ftManager + 0xb4))->f21();
        id = self->unk4;
        int res = 0;
        Pack pk;
        pk.vt = lbl_27_data_261F0;
        pk.a = n;
        pk.b = 0;
        pk.c = 0;
        if (n > 0 && n > -1) {
            if (soEventSystem::getInstance()->getInstanceManager().isContain(n)) {
                if (soEventSystem::getInstance()->getManager(pk.a)->getObserverCapacity(pk.b) == 0) {
                    pk.c = res;
                } else {
                    short unitId = pk.b;
                    m = soEventSystem::getInstance()->getManager(pk.a);
                    if (m->getObserverCapacity(unitId) == 0)
                        res = 0;
                    else
                        res = getUnit(m, unitId);
                    pk.c = res;
                }
            }
        }
        pk.d = id;
        pk.vt = lbl_27_data_261B0;
        fn_27_15A880(&pk, 0);
    } else if ((unsigned int)isTeams(g_ftManager) == 1) {
        if ((unsigned char)result[0x1e] == *(unsigned char*)(mode + self->index * 0x5c + 0xa3))
            kind = 4;
    } else {
        unsigned char player = *(unsigned char*)(mode + self->index * 0x5c + 0x9b);
        if (*(unsigned char*)(result + player * 0x2ac + 0x32) == 0)
            kind = 4;
    }
    if (self->flags & 1) {
        self->fighters[self->active].fighter->start(&pos, lbl_27_rodata_FBC, lbl_27_rodata_FB8, kind, false);
        self->p4C->trainerStart(lbl_27_rodata_FBC, &pos, &pos, kind, false);
    } else if (self->flags & 2) {
        self->fighters[0].fighter->start(&pos, lbl_27_rodata_FBC, lbl_27_rodata_FB8, kind, false);
        if (fn_27_112E20(self->p28) == 0)
            self->fighters[1].fighter->start(&pos, lbl_27_rodata_FBC, lbl_27_rodata_FB8, kind, false);
    } else {
        self->fighters[self->active].fighter->start(&pos, lbl_27_rodata_FBC, lbl_27_rodata_FB8, kind, false);
    }
}
