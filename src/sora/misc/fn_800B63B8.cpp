#pragma force_active on
struct Data {
    char pad[0x1c];
    unsigned short frames;
    char pad1[2];
    int mode;
    int mode2;
    char pad2[4];
    unsigned short frames2;
    char pad3[6];
    int mode3;
};
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual float fn_801B269C();
    char pad[0x28];
    Data* data;
};
struct Group {
    char pad[8];
    Class_8042B6D0* a;
    Class_8042B6D0* b;
    Class_8042B6D0* c;
    Class_8042B6D0* d;
    Class_8042B6D0* e;
};
struct Obj { char pad[0x14]; Group* group; };
inline bool check1(Group* g) {
    if (!g) return true;
    Class_8042B6D0* p = g->b;
    if (!p) return true;
    Data* d = p->data;
    if (d->mode != 1) {
        unsigned short n = d->frames;
        if (p->fn_801B269C() >= (float)(n - 1)) return true;
    }
    return false;
}
inline bool check2(Group* g) {
    if (!g) return true;
    Class_8042B6D0* p = g->a;
    if (!p) return true;
    Data* d = p->data;
    if (d->mode != 1) {
        unsigned short n = d->frames;
        if (p->fn_801B269C() >= (float)(n - 1)) return true;
    }
    return false;
}
inline bool check3(Group* g) {
    if (!g) return true;
    Class_8042B6D0* p = g->c;
    if (!p) return true;
    Data* d = p->data;
    if (d->mode3 != 1) {
        unsigned short n = d->frames2;
        if (p->fn_801B269C() >= (float)(n - 1)) return true;
    }
    return false;
}
inline bool check4(Group* g) {
    if (!g) return true;
    Class_8042B6D0* p = g->d;
    if (!p) return true;
    Data* d = p->data;
    if (d->mode2 != 1) {
        unsigned short n = d->frames;
        if (p->fn_801B269C() >= (float)(n - 1)) return true;
    }
    return false;
}
inline bool check5(Group* g) {
    if (!g) return true;
    Class_8042B6D0* p = g->e;
    if (!p) return true;
    Data* d = p->data;
    if (d->mode != 1) {
        unsigned short n = d->frames;
        if (p->fn_801B269C() >= (float)(n - 1)) return true;
    }
    return false;
}
extern "C" int fn_800B63B8(Obj* obj) {
    if (!check1(obj->group)) return 0;
    if (!check2(obj->group)) return 0;
    if (!check3(obj->group)) return 0;
    if (!check4(obj->group)) return 0;
    return check5(obj->group);
}
