#pragma force_active on
#include <types.h>

struct Cmd {
    virtual unsigned getGroup();
    virtual s8 getType();
    virtual s8 getArgNum();
};

struct Elem;

struct List {
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual int l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void l10();
    virtual void l11();
    virtual void l12();
    virtual void l13();
    virtual void l14();
    virtual void l15();
    virtual void l16();
    virtual void l17();
    virtual void l18();
    virtual void l19();
    virtual Elem** l20(int);
};

struct Unit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual List* u7();
};

struct Mgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int m4(int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8(int);
};

struct Inst {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6(int);
};

struct Elem {
    virtual void e0();
    virtual unsigned e1(int);
    virtual unsigned e2(Cmd*, void*, int);
};

struct acCmdInterpreter {
    char pad[0x30];
    unsigned : 2;
    signed f : 3;
    unsigned : 27;
    int x34;
    short a;
    short b;
    List* cache;
    int m40;
    void* m44;

    Cmd* getCurrentCmd();
};

typedef void (acCmdInterpreter::*Pmf)();

extern "C" {
extern const Pmf lbl_27_rodata_968[5];
extern char lbl_27_bss_B60[];
extern char lbl_27_data_128[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Inst* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Inst*, long);

inline void selectList(acCmdInterpreter* self, List*& result) {
    short id1 = self->a;
    Mgr* mgr;
    short id2;
    List* cur;
    Unit* unit;
    int flag;

    if (id1 <= -1) {
        result = (List*)lbl_27_bss_B60;
        return;
    }
    if (self->cache != 0)
        goto C;
    if (id1 <= -1 || getInstance__13soEventSystemFv()->i6(id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->m4(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->b;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->m4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->m8(id2), 0, lbl_27_data_128,
                                     __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->u7();
    }
    self->cache = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0) {
        result = (List*)lbl_27_bss_B60;
        return;
    }

C:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->m4(self->b) == 0) {
        self->cache = 0;
        result = (List*)lbl_27_bss_B60;
        return;
    }
    result = self->cache;
}

inline bool hasModule(acCmdInterpreter* self) {
    if (*(int*)((char*)self + 0x44) == 0)
        return false;
    return true;
}

void fn_27_705C8(acCmdInterpreter* self) {
    Cmd* cmd = self->getCurrentCmd();
    if (cmd->getGroup() != 1) {
        s8 type = cmd->getType();
        if (type == 1) {
            s8 argNum = cmd->getArgNum();
            if (argNum > -1) {
                if (argNum < 5) {
                    Pmf pmf = lbl_27_rodata_968[argNum];
                    if (pmf != 0)
                        (self->*pmf)();
                }
            }
        } else {
            if (self->f != 0 || self->m44 == 0)
                return;
            List* sel;
            selectList(self, sel);
            int n = sel->l4();
            for (int i = 0; i < n; i++) {
                Elem** p = sel->l20(i);
                Elem* e = *p;
                if (e->e1(type) == 1 && e->e2(cmd, self->m44, self->m40) == 1)
                    return;
            }
        }
    }
}
}
