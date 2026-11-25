#pragma force_active on
#include <ft/ft_manager.h>
#include <so/event/so_event_system.h>

struct Arg2Base { char pad[12]; };
struct Arg2 : Arg2Base {
    virtual void v0();
    virtual int v1();
    virtual void v2(float, int);
};
struct OwnerBase { char pad[12]; };
struct Owner : OwnerBase {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual float v3(); virtual void v4(); virtual void v5(); virtual float v6();
};
struct Elem {
    virtual void e0(); virtual void e1();
    virtual void e2(int, unsigned int, int, int, float);
};
struct List {
    virtual void l0(); virtual void l1();
    virtual Elem** l2(int);
    virtual void l3(); virtual int l4();
};
struct EvInst {
    virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3();
    virtual void i4(); virtual void i5(); virtual int i6(int);
};
struct EvMgr {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual int m4(int); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void* m8(int);
};
struct Unit {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6(); virtual List* u7();
};
struct Self {
    int field0; short id1; short id2; List* cached; int entry_id;
};
extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_1F48;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_111870(Arg2*);
}
extern "C" void fn_27_156ED8(Self* self, float* arg1, Arg2* arg2) {
    EvMgr* mgr;
    List* list;
    int i;
    int n;
    float saved;
    float res;
    int flag_a;
    int flag_b;

    arg2->v2(*arg1, 1);
    if (arg2->v1() == 0) {
        flag_a = 1;
        flag_b = 0;
        if (*(float*)((char*)arg1 + 0x94) > lbl_27_rodata_1F48) {
            flag_b = 1;
            flag_a = 0;
            fn_27_111870(arg2);
        }
        saved = *(float*)((char*)arg1 + 0x94);
        {
            Owner* owner = (Owner*)g_ftManager->getOwner(self->entry_id);
            if ((unsigned int)(*((unsigned char*)g_ftManager + 0x6d) != 0) == 1)
                res = owner->v6();
            else
                res = owner->v3();
        }
        {
            short id1;
            short id2;
            List* cur;
            Unit* unit;
            int flag;
            id1 = self->id1;
            if (id1 <= -1) {
                list = (List*)lbl_27_bss_3168;
                goto LOOP;
            }
            if (self->cached != 0)
                goto C;
            if (id1 <= -1 || ((EvInst*)soEventSystem::getInstance())->i6(id1) == 0) {
                flag = 0;
                goto CHECK;
            }
            if (((EvMgr*)soEventSystem::getInstance()->getManager(self->id1))->m4(self->id2) == 0) {
                self->cached = 0;
                flag = 0;
                goto CHECK;
            }
            id2 = self->id2;
            mgr = (EvMgr*)soEventSystem::getInstance()->getManager(self->id1);
            if (mgr->m4(id2) == 0) {
                cur = 0;
            } else {
                unit = (Unit*)__dynamic_cast(mgr->m8(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
                if (unit == 0)
                    cur = 0;
                else
                    cur = unit->u7();
            }
            self->cached = cur;
            flag = (cur != 0);
        CHECK:
            if (flag == 0) {
                list = (List*)lbl_27_bss_3168;
                goto LOOP;
            }
        C:
            mgr = (EvMgr*)soEventSystem::getInstance()->getManager(self->id1);
            if (mgr->m4(self->id2) == 0) {
                self->cached = 0;
                list = (List*)lbl_27_bss_3168;
            } else {
                list = self->cached;
            }
        }
    LOOP:
        n = list->l4();
        for (i = 0; i < n; i++) {
            Elem** p = list->l2(i);
            (*p)->e2(self->entry_id, (unsigned int)res, flag_b, flag_a, saved);
        }
    }
}
