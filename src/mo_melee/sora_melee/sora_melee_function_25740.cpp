#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

class soAnimCmdEventObserver;
template <typename T> class soEventObserver {
public:
    static void __vt(int, int);
};

extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_801108D0(void*, s32);
extern unsigned char lbl_27_data_28A0[0x2B0];
extern unsigned char lbl_27_data_1180[0x10];
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
};

struct T {
    void* f0;
    void* f4;
    void* f8;
    void* fC;
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
    void* f18;
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
    void* f24;
    void* f28;
    void* f2C;
    void* f30;
    void* f34;
};

extern "C" void* fn_27_25740(void* self, s32 flag) {
    T* t = (T*)self;
    if (t) {
        char* d = (char*)&lbl_27_data_28A0;
        void* f34 = t->f34;
        t->f8 = (void*)d;
        t->f0 = (void*)(d + 8);
        t->fC = (void*)(d + 0x270);
        t->f18 = (void*)(d + 0x280);
        t->f24 = (void*)(d + 0x294);
        if (f34) {
            __dla__FPv(f34);
            t->f34 = 0;
        }
        if (t->f30) {
            fn_801108D0(t->f30, 1);
            t->f30 = 0;
            if (((Object_vptr_0*)t->f28)->slot3() > 0) {
                void* p = ((Object_vptr_0*)t->f28)->slot1(0);
                *(void**)((char*)*(void**)((char*)p + 4) + 0x80) = 0;
            }
        }
        void* f2C = t->f2C;
        if (f2C) {
            __dl__FPv(f2C);
            t->f2C = 0;
        }
        if ((char*)t + 0x18 && (char*)t + 0x18) {
            s16 id1 = t->f1C;
            t->f18 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id1) == 1U) {
                soEventSystem::getInstance()->getManager(t->f1C)->eraseObserver(t->f1E, t->f20);
            }
            t->f20 = -1;
            t->f1C = -1;
        }
        if ((char*)t + 0x0C && (char*)t + 0x0C) {
            s16 id2 = t->f10;
            t->fC = (void*)lbl_27_data_1180;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id2) == 1U) {
                soEventSystem::getInstance()->getManager(t->f10)->eraseObserver(t->f12, t->f14);
            }
            t->f14 = -1;
            t->f10 = -1;
        }
        if (flag > 0) {
            __dl__FPv(t);
        }
    }
    return self;
}
