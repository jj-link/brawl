#include <types.h>
#include <gf/gf_task.h>
#include <ft/ft_manager.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

struct AiTask {
    void* vt;
    char pad04[0x38];
    void* f3c;
    void* f40;
    s16 f44;
    s16 f46;
    s16 f48;
    char pad4a[2];
    s32 f4c[14];
    s8 f84[28];
    s8 fa0;
    s8 fa1;
    s16 fa2;
    s8 fa4;
    char pad_a5[0x53];
    void* fF8;
    void* fFC;
    void* f100;
    char pad104[0x30];
    s32 f134;
    s32 f138;
    s32 f13c;
    s32 f140;
    s32 f144;
    s8 f148;
    char pad149[0x1ff];
    void* f348;
    void* f34c;
    char pad350[2];
    u16 f352;
    char pad354[2];
    u16 f356;
};

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char __vt__22ftOutsideEventObserver[];
extern char lbl_27_data_47BFC[];
extern char lbl_27_data_47E98[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern AiTask* g_aiMgr;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __construct_new_array(void*, void (*)(), void*, unsigned long, unsigned long);
void* fn_27_217590(void*);
void* fn_27_21BE40(void*);
void fn_27_1E8EE4(void*);
void fn_27_206D94();
void fn_27_1E8C6C();
void fn_27_1E8C68();
}

class FtManagerPart {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual s32 slot19();
};

class EventUnitCast {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual s16 slot6(void*, s8);
    virtual void slot7(); virtual void slot8();
};

extern "C" AiTask* fn_27_1E87C0(AiTask* self) {
    soEventManager* mgr;
    u32 f29;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_27_data_47BFC, 0x24, 5, 6, 1);
    ftOutsideEventObserver* observer = reinterpret_cast<ftOutsideEventObserver*>(&self->f40);
    observer->m_manageID = -1;
    observer->m_unitID = 0;
    observer->m_sendID = -1;
    self->f40 = __vt__22ftOutsideEventObserver;
    observer->addObserver(-1, 0);
    self->fa4 = -1;
    self->f3c = (void*)lbl_27_data_47E98;
    self->f40 = (void*)(lbl_27_data_47E98 + 0x64);
    self->f140 = 0;
    g_aiMgr = self;
    self->fF8 = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(0x1A8C, 2), fn_27_206D94, 0, 0x1C4, 0xF);
    void* p = __nw__FUlQ25Heaps8HeapType(0x1920, 2);
    if (p != 0) p = fn_27_217590(p);
    self->fFC = p;
    void* q = __nw__FUlQ25Heaps8HeapType(0x484, 2);
    if (q != 0) q = fn_27_21BE40(q);
    self->f100 = q;
    fn_27_1E8EE4(self);
    self->f348 = 0;
    self->f34c = 0;
    self->f356 = 0x176;
    self->f352 = 0x176;
    if ((s16)self->f48 <= -1) {
        s32 manageId = reinterpret_cast<FtManagerPart*>(reinterpret_cast<char*>(g_ftManager) + 0xb4)->slot19();
        f29 = 0;
        s32 f28 = 0;
        s16 id;
        s32 f3 = 0;
        s32 f4 = 0;
        s16 a = self->f44;
        if (a >= 0 && self->f46 >= 0) f4 = 1;
        if (f4 != 0 && (s16)self->f48 > -1) f3 = 1;
        if (f3 != 0) {
            if (soEventSystem::getInstance()->getInstanceManager().isContain(a) == 1) f28 = 1;
        }
        if (f28 != 0) {
            if (soEventSystem::getInstance()->getManager(self->f44)->getObserverCapacity(self->f46) == 1) f29 = 1;
        }
        if (f29 == 1) {
            id = self->f44;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1)
                soEventSystem::getInstance()->getManager(self->f44)->eraseObserver(self->f46, self->f48);
            self->f48 = -1;
            self->f44 = -1;
        }
        if ((s16)manageId > -1 && (s16)self->f46 > -1) {
            if (soEventSystem::getInstance()->getInstanceManager().isContain((s16)manageId) != 0) {
                if (soEventSystem::getInstance()->getManager((s16)manageId)->isNullUnit(self->f46) != 1) {
                    mgr = soEventSystem::getInstance()->getManager((s16)manageId);
                    s16 ret;
                    if (mgr->getObserverCapacity(self->f46) == 0) {
                        ret = -1;
                    } else {
                        soEventUnit* unit = mgr->getEventUnit(self->f46);
                        EventUnitCast* cast = (EventUnitCast*)__dynamic_cast(unit, 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
                        if (cast == 0) ret = -1;
                        else ret = cast->slot6((void*)&self->f40, -1);
                    }
                    self->f48 = ret;
                    if (ret > -1 && ret > -1) self->f44 = (s16)manageId;
                }
            }
        }
    }
    for (int i = 0; i < 14; ++i) {
        self->f4c[i] = 0;
        self->f84[i] = -1;
    }
    for (int i = 14; i < 28; ++i) {
        self->f84[i] = -1;
    }
    u16 n = self->f356;
    self->fa0 = 1;
    self->fa1 = 0;
    self->fa2 = 0;
    self->f148 = 0;
    self->f144 = 0;
    self->f134 = 0;
    self->f138 = 0;
    self->f13c = 0;
    if (n != 0 && self->f352 != 0) {
        void* r = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(((u32)n << 5) + 0x10, 2), fn_27_1E8C6C, 0, 0x20, n);
        f29 = self->f352;
        self->f348 = r;
        self->f34c = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(f29 * 0x4C + 0x10, 2), fn_27_1E8C68, 0, 0x4C, f29);
    }
    return self;
}
