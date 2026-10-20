#pragma force_active on
struct Query {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int get();
};

struct Action {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual int set(int);
};

struct Object {
    char pad0[0x8c0];
    int state;
    char pad1[0x3a68 - 0x8c4];
    Action action;
    char pad2[0x3ab4 - 0x3a6c];
    Query query;
    char pad3[0x3c68 - 0x3ab8];
    unsigned char enabled;
};

extern "C" int fn_27_28DC0C(Object* obj) {
    if (obj->state == 0x53) {
        if (obj->enabled && obj->query.get() > 2) {
            return obj->action.set(2);
        }
        return 0;
    }
    return 0;
}
