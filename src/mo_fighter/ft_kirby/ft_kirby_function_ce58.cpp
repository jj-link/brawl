#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

#define V6(p) virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

struct ObjectBase {
    char pad[0x3c];
};

struct Obj : ObjectBase {
    V6(a0) V8(a1) V8(a2) V8(a3) V32(b) V32(c) V32(d) V8(e0) V8(e1) V8(e2) virtual void x150();
    virtual int v151();
    V8(f0) V8(f1) V8(f2) V8(f3) virtual void y184(); virtual void y185();
    virtual int v186();
    V32(g) virtual void z219(); virtual void z220(); virtual void z221(); virtual void z222();
    virtual void w223();
};

struct Link {
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual int s6(int);
    virtual void s7(int, int);
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual void s11(int, int);
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual int s19(int);
    virtual void s20(int);
};

struct Other {
    V6(r0) V8(r1) virtual void q14(); virtual void q15();
    virtual int r18();
};

struct Modules {
    char pad0[0x64];
    Link* link;
    char pad1[0x8];
    Other* other;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Event {
    char pad0[0xc];
    u32 id;
    char pad1[0x11];
    u8 flag;
    u8 cat;
};

struct Task {
    char pad[0x2c];
    u32 w;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFUl(void* sched, u32 id);
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void* sched, int cat, u32 id);
int getTeamNo__23soExternalValueAccesserFP11StageObject(void* stage);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_135EDC(void*, Event*, Access*);
void fn_96_1DA74(void*, Event*, Access*);
extern char lbl_96_data_5DA8[];
extern char lbl_96_data_68D8[];
extern char lbl_96_data_6024[];
extern char lbl_96_data_69D8[];

void fn_96_CE58(void* self, Event* ev, Access* acc) {
    if (acc->modules->other->r18() == 0x112 || acc->modules->other->r18() == 0x117) {
        if (acc->modules->link->s19(0x2200001a) == 0) {
            Task* t = (Task*)getTask__15gfTaskSchedulerFUl(getInstance__15gfTaskSchedulerFv(), ev->id);
            if (t != 0 && ((int)((t->w << 17) & 0xFF800000) >> 24) == 0xc) {
                Obj* o = (Obj*)__dynamic_cast(t, 0x3c, lbl_96_data_5DA8, lbl_96_data_69D8, 0);
                acc->modules->link->s7(0, 0x20000005);
                if (o->v151() != 0) {
                    int st = *(int*)((char*)o + 0xb8);
                    switch (st) {
                    case 0x37:
                        acc->modules->link->s7(2, 0x20000005);
                        /* fallthrough */
                    case 0x33:
                        acc->modules->link->s20(0x2200001a);
                        acc->modules->link->s7(ev->id, 0x20000004);
                        break;
                    }
                }
            }
        }
    } else {
        if (acc->modules->other->r18() == 0x116) {
            if (ev->flag == 1) {
                Task* t2 = (Task*)getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), ev->cat, ev->id);
                if (((int)((t2->w << 17) & 0xFF800000) >> 24) == 0xa) {
                    void* s = __dynamic_cast(t2, 0x3c, lbl_96_data_68D8, lbl_96_data_69D8, 1);
                    getTeamNo__23soExternalValueAccesserFP11StageObject(s);
                    Obj* o = (Obj*)__dynamic_cast(t2, 0x3c, lbl_96_data_6024, lbl_96_data_69D8, 0);
                    if (o->v186() != 0x1c) {
                        o->w223();
                        int v = acc->modules->link->s6(0x20000006);
                        acc->modules->link->s7(ev->id, v + 0x20000000);
                        acc->modules->link->s11(1, 0x20000006);
                    }
                }
            }
        }
    }
    fn_27_135EDC(self, ev, acc);
    if (ev != 0) {
        fn_96_1DA74((char*)self + 0x1B72C, ev, acc);
    }
}
}
