#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& p) : x(p.x), y(p.y), z(p.z) {}
};

struct Access;
struct Target;

#define SLOT(n) virtual void unused##n();

struct Obj {
    char pad[60];
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132)
    SLOT(136) SLOT(140) SLOT(144) SLOT(148)
    SLOT(152) SLOT(156) SLOT(160) SLOT(164)
    virtual int kind();
};

struct Target {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    virtual int id();
};

struct Link {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    virtual unsigned test(int, int);
    SLOT(28) SLOT(32) SLOT(36) SLOT(40) SLOT(44)
    virtual int exists(int);
    SLOT(52) SLOT(56) SLOT(60) SLOT(64)
    SLOT(68) SLOT(72) SLOT(76)
    virtual void* target(int);
    SLOT(84) SLOT(88) SLOT(92) SLOT(96)
    SLOT(100) SLOT(104) SLOT(108) SLOT(112)
    SLOT(116) SLOT(120) SLOT(124) SLOT(128)
    SLOT(132) SLOT(136) SLOT(140) SLOT(144)
    SLOT(148) SLOT(152) SLOT(156) SLOT(160)
    SLOT(164) SLOT(168) SLOT(172) SLOT(176)
    SLOT(180) SLOT(184) SLOT(188) SLOT(192)
    SLOT(196) SLOT(200) SLOT(204) SLOT(208)
    SLOT(212) SLOT(216) SLOT(220) SLOT(224)
    SLOT(228) SLOT(232) SLOT(236) SLOT(240)
    SLOT(244) SLOT(248) SLOT(252) SLOT(256)
    SLOT(260) SLOT(264) SLOT(268) SLOT(272)
    SLOT(276) SLOT(280) SLOT(284) SLOT(288)
    SLOT(292) SLOT(296) SLOT(300) SLOT(304)
    virtual void attach(int, int, int, int, int);
};

struct Work {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    virtual int get(int);
    virtual void set(int, int);
};

struct Status {
    SLOT(8) SLOT(12) SLOT(16)
    virtual void change(int, Access*);
};

struct Item {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28)
    virtual void act(int, int, bool);
    SLOT(36) SLOT(40) SLOT(44) SLOT(48)
    SLOT(52) SLOT(56) SLOT(60) SLOT(64)
    SLOT(68) SLOT(72) SLOT(76)
    virtual unsigned test(int);
    SLOT(84) SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    virtual Target* target(int);
};

struct Model {
    char pad[8];
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132) SLOT(136)
    virtual int query(int);
};

struct Ground {
    char pad[8];
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132)
    SLOT(136) SLOT(140)
    virtual int test(int);
};

struct Effect {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132)
    SLOT(136) SLOT(140) SLOT(144) SLOT(148)
    SLOT(152) SLOT(156) SLOT(160) SLOT(164)
    SLOT(168) SLOT(172) SLOT(176) SLOT(180)
    SLOT(184) SLOT(188) SLOT(192) SLOT(196)
    SLOT(200) SLOT(204) SLOT(208) SLOT(212)
    SLOT(216) SLOT(220) SLOT(224) SLOT(228)
    SLOT(232) SLOT(236) SLOT(240)
    virtual void act(int);
};

#undef SLOT

struct Modules {
    char p0[4];
    Model* m04;
    char p08[8];
    Ground* m10;
    char p14[8];
    Effect* m1c;
    char p20[0x34];
    Link* m54;
    char p58[0xc];
    Work* m64;
    char p68[8];
    Status* m70;
    char p74[0x10];
    Item* m84;
};

struct Access {
    char pad[0xd8];
    Modules* mods;
};

struct Self {
    char pad[0x60];
    Access* acc;
};

struct Event {
    int kind;
    bool done;
    char pad[3];
    union {
        Vec3 pos;
        int value;
    };
};

extern "C" {
Vec3 getPos__23soExternalValueAccesserFP11StageObject(void*);
int* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);
void* fn_94_17DDC();
void fn_27_50330(void*, int);
void fn_27_50190(void*, int);
void fn_27_1324D4(Self*, Event*, Access*, Obj*, int);
}

inline void change(Access* a, int v) {
    Status* m = a->mods->m70;
    m->change(v, a);
}

inline int query(Access* a) {
    Model* m = a->mods->m04;
    return m->query(0x12e);
}

extern "C" void fn_94_179E4(
    Self* self, Event* e, Access* a, Obj* sender, int link)
{
    switch (sender->kind()) {
    case 0x41:
        switch (e->kind) {
        case 0x838: {
            Link* m = self->acc->mods->m54;
            if (m->exists(0)) {
                m = self->acc->mods->m54;
                void* target = m->target(0);
                if (target) {
                    Vec3 p = getPos__23soExternalValueAccesserFP11StageObject(target);
                    e->pos.x = p.x;
                    e->pos.y = p.y;
                    e->pos.z = p.z;
                    e->done = true;
                }
            }
            break;
        }
        case 0x839:
            change(a, 0x39);
            break;
        case 0x83a:
            e->value = query(a);
            e->done = true;
            break;
        case 0x83b: {
            int* p =
                getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
                    a, 0xa80e, 0);
            Work* m = a->mods->m64;
            m->set(*p, 0x20000001);
            change(a, 0x81);
            Item* item = a->mods->m84;
            item->act(0, 15, 0);
            item = a->mods->m84;
            if (item->test(2) == 1) {
                Link* lm = a->mods->m54;
                item = a->mods->m84;
                Target* target = item->target(2);
                int id = target->id();
                if (lm->test(3, id) == 1) {
                    lm = a->mods->m54;
                    int q = query(a);
                    lm->attach(3, q, e->value, 5, 0);
                }
            }
            break;
        }
        case 0x83c: {
            Ground* m = a->mods->m10;
            if (m->test(0))
                change(a, 0x75);
            else
                change(a, 0x7b);
            break;
        }
        case 0x83e:
            change(a, 0x83);
            break;
        case 0:
        case 2:
        case 4: {
            Work* m = a->mods->m64;
            int h = m->get(0x10000041);
            if (h != -1) {
                a->mods->m1c->act(0);
                fn_27_50330(fn_94_17DDC(), h);
                fn_27_50190(fn_94_17DDC(), h);
                m = a->mods->m64;
                m->set(-1, 0x10000041);
            }
            break;
        }
        }
        break;
    }
    fn_27_1324D4(self, e, a, sender, link);
}
