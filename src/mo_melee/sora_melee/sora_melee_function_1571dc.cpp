#pragma force_active on

struct Object_vptr_c_base { char pad[0xc]; };

class Owner : public Object_vptr_c_base {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual float s3();
    virtual void s4();
    virtual void s5();
    virtual float s6();
};

class Instance {
public:
    virtual void i0(); virtual void i1(); virtual void i2();
    virtual void i3(); virtual void i4(); virtual void i5();
    virtual int i6(int);
};

class Obj {
public:
    virtual void o0(); virtual void o1();
    virtual void call(int, unsigned int, int, int, float);
};

class Container {
public:
    virtual void c0(); virtual void c1();
    virtual Obj** c2(int);
    virtual void c3();
    virtual int c4();
};

class Unit {
public:
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6();
    virtual Container* u7();
};

class Mgr {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual int m4(int);
    virtual void m5(); virtual void m6(); virtual void m7();
    virtual void* m8(int);
};

struct FtManager {
    char pad[0x6d];
    unsigned char flag;
};

struct Self {
    int field0;
    short id1;
    short id2;
    Container* cached;
    int ownerId;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern FtManager* g_ftManager;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Instance* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Instance*, long);
void* getOwner__9ftManagerFi(FtManager*, int);
}

inline Container* selectList(Self* self) {
    short id2;
    Mgr* mgr;
    Container* cur;
    Unit* unit;
    void* obj;
    int flag;

    if (self->id1 <= -1) {
        return (Container*)lbl_27_bss_3168;
    }
    if (self->cached != 0) {
        goto CHECK_CACHED;
    }
    if (self->id1 <= -1 || getInstance__13soEventSystemFv()->i6(self->id1) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->m4(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->id2;
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(id2) == 0) {
        cur = 0;
    } else {
        obj = mgr->m8(id2);
        unit = (Unit*)__dynamic_cast(obj, 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            cur = 0;
        } else {
            cur = unit->u7();
        }
    }
    self->cached = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        return (Container*)lbl_27_bss_3168;
    }
CHECK_CACHED:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
    if (mgr->m4(self->id2) == 0) {
        self->cached = 0;
        return (Container*)lbl_27_bss_3168;
    }
    return self->cached;
}

extern "C" void fn_27_1571DC(Self* self, int arg1, int arg2, float farg0) {
    Owner* owner;
    float f;
    Container* list;
    int n;
    int i;
    unsigned int b;

    owner = (Owner*)getOwner__9ftManagerFi(g_ftManager, self->ownerId);
    b = (g_ftManager->flag != 0);
    if (b == 1) {
        f = owner->s6();
    } else {
        f = owner->s3();
    }

    list = selectList(self);
    n = list->c4();
    for (i = 0; i < n; i++) {
        Obj** p = list->c2(i);
        (*p)->call(self->ownerId, (unsigned int)f, arg1, arg2, farg0);
    }
}
