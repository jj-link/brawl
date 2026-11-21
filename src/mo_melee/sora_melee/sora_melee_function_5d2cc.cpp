#pragma force_active on

struct Hit;
struct Access;

struct Listener {
    virtual void slot0();
    virtual void onHit(Hit*, void*, Access*);
    virtual void onExtra(Hit*, Access*);
};

struct List {
    virtual void slot0();
    virtual void slot1();
    virtual Listener** get(int);
    virtual void slot3();
    virtual int size();
};

struct EventUnit {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual List* observers();
};

struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int exists(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void* unit(int);
};

struct Instance {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int exists(int);
};

extern "C" {
extern char lbl_27_bss_B00[];
extern char lbl_27_data_6590[];
extern char __RTTI__11soEventUnit[];
extern float lbl_27_rodata_82C;
extern float lbl_27_rodata_828;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Instance* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(Instance*, long);
}

struct Hit {
    char pad0[4];
    float damage;
    char pad8[4];
    float other;
    char pad10[0x64];
    unsigned int flags;
    char pad78[0x1c];
    float extra;
    char pad98[4];
    unsigned char active;
};

struct HitArray {
    virtual void slot0();
    virtual Hit* get(int);
    virtual void slot2();
    virtual int size();
};

struct Module14 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int test();
};

struct Module1C {
    virtual void slot0();  virtual void slot1();
    virtual void slot2();  virtual void slot3();
    virtual void slot4();  virtual void slot5();
    virtual void slot6();  virtual void slot7();
    virtual void slot8();  virtual void slot9();
    virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13();
    virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37();
    virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41();
    virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45();
    virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49();
    virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53();
    virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57();
    virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61();
    virtual void set(unsigned int, unsigned int);
};

struct Module20 {
    virtual void slot0();  virtual void slot1();
    virtual void slot2();  virtual void slot3();
    virtual void slot4();  virtual void slot5();
    virtual void slot6();  virtual void slot7();
    virtual void slot8();  virtual void slot9();
    virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13();
    virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33();
    virtual int test(int);
};

struct Node {
    virtual void a();
    virtual void b();
    virtual int id();
};

struct Module18 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Node* node();
};

struct Result {
    char pad0[0x24];
    float x, y, z;
    char pad30[8];
    unsigned int high : 27;
    unsigned int low : 5;
};

struct Module10Base {
    int pad[2];
};

struct Module10 : Module10Base {
    virtual void slot0();  virtual void slot1();
    virtual void slot2();  virtual void slot3();
    virtual void slot4();  virtual void slot5();
    virtual void slot6();  virtual void slot7();
    virtual void slot8();  virtual void slot9();
    virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13();
    virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37();
    virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41();
    virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45();
    virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49();
    virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53();
    virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57();
    virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61();
    virtual void slot62(); virtual void slot63();
    virtual unsigned int query(Result*, int*, int*, int);
};

struct Modules {
    char pad[0x10];
    Module10* m10;
    Module14* m14;
    Module18* m18;
    Module1C* m1c;
    Module20* m20;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Base {
    int x, y;
};

struct Self : Base {
    virtual void slot0();  virtual void slot1();
    virtual void slot2();  virtual void slot3();
    virtual void slot4();  virtual void slot5();
    virtual void slot6();  virtual void slot7();
    virtual void slot8();  virtual void slot9();
    virtual void slot10();
    virtual void apply(Hit*, float);
    virtual void slot12(); virtual void slot13();
    virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35();
    virtual void slot36();
    virtual void reset();
    virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41();
    virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45();
    virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49();
    virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53();
    virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57();
    virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61();
    virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65();
    virtual void slot66(); virtual void slot67();
    virtual void slot68(); virtual void slot69();
    virtual void slot70(); virtual void slot71();
    virtual void* select(int);
    virtual unsigned int enabled();

    char pad0c[0x1c];
    short id1, id2;
    List* cached;
    char pad30[0xc];
    Access* access;
    HitArray* array;
    char pad44[0x5c];
    unsigned int param, value;
    unsigned char disabled, stopped;
};

extern "C" void* fn_27_5D93C(Self*, int, Result*);

inline List* resolve(Self* self) {
    short id1 = self->id1;
    short id2;
    Manager* mgr;
    List* cur;
    EventUnit* unit;
    int flag;

    if (id1 <= -1)
        return (List*)lbl_27_bss_B00;
    if (self->cached != 0)
        goto C;

    if (id1 <= -1 || getInstance__13soEventSystemFv()->exists(id1) == 0) {
        flag = 0;
        goto CHECK;
    }

    if (getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id1)->exists(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->id2;
    mgr = getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->id1);
    if (mgr->exists(id2) == 0) {
        cur = 0;
    } else {
        unit = (EventUnit*)__dynamic_cast(
            mgr->unit(id2), 0, lbl_27_data_6590, __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->observers();
    }

    self->cached = cur;
    flag = cur != 0;

CHECK:
    if (!flag)
        return (List*)lbl_27_bss_B00;

C:
    mgr = getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->id1);
    if (!mgr->exists(self->id2)) {
        self->cached = 0;
        return (List*)lbl_27_bss_B00;
    }
    return self->cached;
}

extern "C" void* fn_27_5D2CC(Self* self, void* arg) {
    List* extraList;
    int j;
    Hit* hit;
    void* result = arg;
    int i;

    if (self->stopped == 1)
        return 0;

    int count = self->array->size();
    float zero = lbl_27_rodata_82C;

    for (i = 0; i < count; ++i) {
        hit = self->array->get(i);
        float damage = hit->damage;

        if (!self->disabled)
            self->apply(hit, damage);

        if (damage > zero || hit->other > zero || hit->active == 1) {
            if (!arg)
                result = self->select(i);

            if (!self->disabled) {
                extraList = resolve(self);
                for (j = 0; j < extraList->size(); ++j)
                    (*extraList->get(j))->onHit(hit, result, self->access);
            }

            if (self->param != 0xffffffffU)
                self->access->modules->m1c->set(self->param, self->value);

            if (!result && !((hit->flags >> 5) & 1) &&
                !self->access->modules->m14->test())
                self->reset();
        }

        if (zero != hit->extra) {
            short id1;
            short id2;
            Manager* mgr;
            List* cur;
            EventUnit* unit;
            int flag;

            self->apply(hit, hit->extra);
            id1 = self->id1;
            if (id1 <= -1) {
                extraList = (List*)lbl_27_bss_B00;
                goto EXTRA_LOOP;
            }
            if (self->cached != 0)
                goto EXTRA_C;

            if (id1 <= -1 ||
                getInstance__13soEventSystemFv()->exists(id1) == 0) {
                flag = 0;
                goto EXTRA_CHECK;
            }

            if (getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    self->id1)->exists(self->id2) == 0) {
                self->cached = 0;
                flag = 0;
                goto EXTRA_CHECK;
            }

            id2 = self->id2;
            mgr = getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->id1);
            if (mgr->exists(id2) == 0) {
                cur = 0;
            } else {
                unit = (EventUnit*)__dynamic_cast(
                    mgr->unit(id2), 0, lbl_27_data_6590,
                    __RTTI__11soEventUnit, 0);
                if (unit == 0)
                    cur = 0;
                else
                    cur = unit->observers();
            }
            self->cached = cur;
            flag = cur != 0;

EXTRA_CHECK:
            if (!flag) {
                extraList = (List*)lbl_27_bss_B00;
                goto EXTRA_LOOP;
            }

EXTRA_C:
            mgr = getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->id1);
            if (!mgr->exists(self->id2)) {
                self->cached = 0;
                extraList = (List*)lbl_27_bss_B00;
            } else {
                extraList = self->cached;
            }

EXTRA_LOOP:
            for (j = 0; j < extraList->size(); ++j)
                (*extraList->get(j))->onExtra(hit, self->access);
            hit->extra = zero;
        }
    }

    if (!result && self->enabled() == 1 &&
        !self->access->modules->m20->test(0)) {
        Result data;
        data.x = lbl_27_rodata_828;
        data.y = lbl_27_rodata_828;
        data.z = lbl_27_rodata_828;
        data.low = 0;
        int id = 0;
        int other = -1;

        if (self->access->modules->m10->query(&data, &id, &other, id) == 1 &&
            other != self->access->modules->m18->node()->id())
            result = fn_27_5D93C(self, id, &data);
    }

    return result;
}
