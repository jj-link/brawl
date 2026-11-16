#include <types.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#pragma force_active on

extern "C" {
extern char __RTTI__11soEventUnit[];
extern char lbl_27_data_52F0[];
extern void* lbl_27_bss_B8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
}

struct Self {
    void* vt;
    char pad0[8];
    s16 f0c;
    s16 f0e;
    s16 f10;
    char pad1[0x26];
    s16 f38;
    char pad2[2];
    s32 f3c;
    u8 f40;
};

class SubIF {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual s32 m19();
};

class InstIF {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual u32 m6(s16);
};

class MgrIF {
public:
    virtual void m0(); virtual void m1(); virtual u32 m2(s16); virtual void m3(s16, s16);
    virtual u32 m4(s16); virtual void m5(); virtual void m6(); virtual void m7(); virtual void* m8(s16);
};

class UnitIF {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual s16 m6(void*, s16);
};

extern "C" void fn_27_B58F8(Self* self) {
    if (self->f40 == 1) {
        if (lbl_27_bss_B8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
            if (p != 0) p = fn_27_4FAB4(p);
            lbl_27_bss_B8 = p;
        }
        s32 ret = ((SubIF*)((char*)lbl_27_bss_B8 + 0x8d4))->m19();
        if (self->f38 != (s16)ret) {
            self->f38 = (s16)ret;
            if ((s16)ret > -1) self->f3c = 0;
        }
        if (self->f10 == -1) {
            if (lbl_27_bss_B8 == 0) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                if (p != 0) p = fn_27_4FAB4(p);
                lbl_27_bss_B8 = p;
            }
            s32 tmp = ((SubIF*)((char*)lbl_27_bss_B8 + 0x8d4))->m19();
            s32 r30 = tmp;
            soEventManager* mg;
            u32 r29 = 0;
            s32 r28 = 0;
            s32 r3 = 0;
            s32 r4 = 0;
            s16 result;
            s16 id;
            s16 r27 = self->f0c;
            if (r27 >= 0) {
                if (self->f0e >= 0) r4 = 1;
            }
            if (r4 != 0) {
                if (self->f10 > -1) r3 = 1;
            }
            if (r3 != 0) {
                if (soEventSystem::getInstance()->getInstanceManager().isContain(r27) == 1) r28 = 1;
            }
            if (r28 != 0) {
                if (soEventSystem::getInstance()->getManager(self->f0c)->getObserverCapacity(self->f0e) == 1) r29 = 1;
            }
            if (r29 == 1) {
                id = self->f0c;
                if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1) {
                    soEventSystem::getInstance()->getManager(self->f0c)->eraseObserver(self->f0e, self->f10);
                }
                self->f10 = -1;
                self->f0c = -1;
            }
            if ((s16)r30 > -1 && self->f0e > -1) {
                if (soEventSystem::getInstance()->getInstanceManager().isContain((s16)r30) != 0) {
                    if (soEventSystem::getInstance()->getManager((s16)r30)->isNullUnit(self->f0e) != 1) {
                        mg = soEventSystem::getInstance()->getManager((s16)r30);
                        if (mg->getObserverCapacity(self->f0e) == 0) {
                            result = -1;
                        } else {
                            soEventUnit* ptr = mg->getEventUnit(self->f0e);
                            void* cast = __dynamic_cast(ptr, 0, lbl_27_data_52F0, __RTTI__11soEventUnit, 0);
                            if (cast == 0) {
                                result = -1;
                            } else {
                                result = ((UnitIF*)cast)->m6((char*)self + 8, -1);
                            }
                        }
                        self->f10 = result;
                        if (result > -1 && result > -1) self->f0c = (s16)r30;
                    }
                }
            }
        }
    }
}
