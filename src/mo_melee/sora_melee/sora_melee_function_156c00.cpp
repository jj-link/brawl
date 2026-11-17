#pragma force_active on

struct Sys {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6(int);
};

struct Damage {
    float a, b, c, d;
};

struct Obj;

struct List {
    virtual void l0();
    virtual void l1();
    virtual Obj** l2(int);
    virtual void l3();
    virtual int l4();
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

struct Obj {
    virtual void o0();
    virtual void call(int, unsigned int, Damage*);
};

struct Owner_base {
    char pad[0xc];
};

class Owner : public Owner_base {
public:
    virtual void s0();
    virtual int s1();
    virtual void s2(float, int);
    virtual float s3();
    virtual void s4();
    virtual void s5();
    virtual float s6();
};

struct FtManager {
    char pad[0x6d];
    unsigned char flag;
};

struct Self {
    int unk0;
    short id1;
    short id2;
    List* cache;
    int ownerId;
};

extern "C" {
extern char lbl_27_bss_3168[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern FtManager* g_ftManager;
extern const float lbl_27_rodata_1F48;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_111870(unsigned char*);
Sys* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Sys*, long);
Owner* getOwner__9ftManagerFi(FtManager*, int);
}

extern "C" void fn_27_156C00(Self* self, Damage* arg1, unsigned int unused,
                             Owner* obj) {
    Mgr* mgr;
    float f;
    Owner* owner;
    List* sel;
    unsigned int b;
    int n;
    int i;

    obj->s2(arg1->a, 1);
    if (obj->s1() == 0 && arg1->b > lbl_27_rodata_1F48) {
        fn_27_111870((unsigned char*)obj);
        owner = getOwner__9ftManagerFi(g_ftManager, self->ownerId);
        b = (g_ftManager->flag != 0);
        if (b == 1) {
            f = owner->s6();
        } else {
            f = owner->s3();
        }

        {
            short id1;
            short id2;
            List* cur;
            Unit* unit;
            int flag;

            id1 = self->id1;
            if (id1 <= -1) {
                sel = (List*)lbl_27_bss_3168;
                goto LOOP;
            }
            if (self->cache != 0) {
                goto C;
            }
            if (id1 <= -1 || getInstance__13soEventSystemFv()->s6(id1) == 0) {
                flag = 0;
                goto CHECK;
            }
            if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1)->m4(self->id2) == 0) {
                self->cache = 0;
                flag = 0;
                goto CHECK;
            }
            id2 = self->id2;
            mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
            if (mgr->m4(id2) == 0) {
                cur = 0;
            } else {
                unit = (Unit*)__dynamic_cast(mgr->m8(id2), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
                if (unit == 0) {
                    cur = 0;
                } else {
                    cur = unit->u7();
                }
            }
            self->cache = cur;
            flag = (cur != 0);
        CHECK:
            if (flag == 0) {
                sel = (List*)lbl_27_bss_3168;
                goto LOOP;
            }
        C:
            mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id1);
            if (mgr->m4(self->id2) == 0) {
                self->cache = 0;
                sel = (List*)lbl_27_bss_3168;
            } else {
                sel = self->cache;
            }
        }
    LOOP:
        n = sel->l4();
        for (i = 0; i < n; i++) {
            Obj** p = sel->l2(i);
            (*p)->call(self->ownerId, (unsigned int)f, arg1);
        }
    }
}
