#pragma force_active on
class Mgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual unsigned char* get(int idx);
};

struct Owner {
    char pad[0x7c];
    Mgr* mgr;
};

struct Flags {
    char pad[5];
    unsigned char f7 : 1;
    unsigned char rest : 7;
};

extern "C" void fn_94_10878(char* self) {
    Owner* o = *(Owner**)(self + 0xd8);
    Flags* p;
    p = (Flags*)o->mgr->get(0);
    p->f7 = 0;
    o = *(Owner**)(self + 0xd8);
    p = (Flags*)o->mgr->get(1);
    p->f7 = 0;
    o = *(Owner**)(self + 0xd8);
    p = (Flags*)o->mgr->get(2);
    p->f7 = 0;
    o = *(Owner**)(self + 0xd8);
    p = (Flags*)o->mgr->get(3);
    p->f7 = 0;
}
