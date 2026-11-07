#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on
extern "C" {
extern char __vt__22ftOutsideEventObserver[];
extern char lbl_27_data_5AF98[];
extern char lbl_27_data_5ADB8[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
}
struct Self {
    void* vt;
    s16 a, b, c;
    char pad0[2];
    void* game;
    char pad1[0x1c];
    int x, y;
    u8 flags;
    char pad2[3];
    int z;
};
class ftOutsideEventObserver {
public:
    virtual void addObserver(s16, s8);
    virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
    virtual void slot7(); virtual void slot8();
};
class ManagerPart {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual s32 slot19();
};
class Unit {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual s16 slot6(Self*, s8);
    virtual void slot7(); virtual void slot8();
};
struct FTManager { char pad[0xb4]; ManagerPart part; };
struct GameGlobal { char pad[8]; void* game; };
extern "C" FTManager* g_ftManager;
extern "C" GameGlobal* g_GameGlobal;
extern "C" Self* fn_27_27F0A8() {
    Self* self = (Self*)__nw__FUlQ25Heaps8HeapType(0x3c, 0xf);
    if (self) {
        self->a = -1;
        self->b = 0;
        self->c = -1;
        self->vt = __vt__22ftOutsideEventObserver;
        ((ftOutsideEventObserver*)self)->addObserver(-1, 0);
        self->vt = lbl_27_data_5AF98;
        if (self->c <= -1) {
            soEventManager* mgr;
            s32 manageId = g_ftManager->part.slot19();
            u32 f31 = 0;
            s32 f30 = 0;
            s32 f4 = 0;
            s32 f5 = 0;
            s16 ret;
            s16 id;
            s16 a = self->a;
            if (a >= 0 && self->b >= 0) f5 = 1;
            if (f5 != 0 && self->c > -1) f4 = 1;
            if (f4 != 0) {
                if (soEventSystem::getInstance()->getInstanceManager().isContain(a) == 1) f30 = 1;
            }
            if (f30 != 0) {
                if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 1) f31 = 1;
            }
            if (f31 == 1) {
                id = self->a;
                if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1)
                    soEventSystem::getInstance()->getManager(self->a)->eraseObserver(self->b, self->c);
                self->c = -1;
                self->a = -1;
            }
            if ((s16)manageId > -1 && self->b > -1) {
                if (soEventSystem::getInstance()->getInstanceManager().isContain((s16)manageId) != 0) {
                    if (soEventSystem::getInstance()->getManager((s16)manageId)->isNullUnit(self->b) != 1) {
                        mgr = soEventSystem::getInstance()->getManager((s16)manageId);
                        if (mgr->getObserverCapacity(self->b) == 0) ret = -1;
                        else {
                            soEventUnit* unit = mgr->getEventUnit(self->b);
                            Unit* cast = (Unit*)__dynamic_cast(unit, 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
                            if (cast == 0) ret = -1;
                            else ret = cast->slot6(self, -1);
                        }
                        self->c = ret;
                        if (ret > -1 && self->c > -1) self->a = (s16)manageId;
                    }
                }
            }
        }
        self->game = g_GameGlobal->game;
        self->x = 0;
        self->y = 0;
        self->z = 0;
        self->flags = (self->flags | 0x80) & ~0x40 | 0x20;
        self->flags &= ~0x10;
        self->vt = lbl_27_data_5ADB8;
    }
    return self;
}