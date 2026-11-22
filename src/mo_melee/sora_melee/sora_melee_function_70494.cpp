#include <types.h>
#pragma force_active on

struct Inner {
    s32 kind;
    s32 field4;
};

class Module {
public:
    virtual void v0();
    virtual void v1();
    virtual Inner* get(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void finish();
    char pad[0x14];
    Inner* first() { return get(0); }
    void done() { finish(); }
};

class Actor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int count();
    virtual void v4();
    virtual Module getLocal();
};

class Middle;
class Target {
public:
    virtual void v0();
    virtual int update(int, Module*, Middle*);
};

class TargetHolder {
    char pad[0x78];
public:
    Target* target;
};

class Middle {
    char pad[0xd8];
public:
    TargetHolder* holder;
};

class ThisObj {
    char pad[0x44];
public:
    Middle* middle;
};

extern "C" s32 fn_27_70494(ThisObj* self, Actor* actor) {
    if (!self->middle) return 0;
    if (actor->count() <= 0) return 0;
    Module local = actor->getLocal();
    u8 workspace[24];
    Inner* data = local.first();
    *(Inner**)workspace = data;
    workspace[4] = 0;
    u32 copiedFlag = *(u32*)(workspace + 4);
    *(Inner**)(workspace + 8) = data;
    *(u32*)(workspace + 12) = copiedFlag;
    *(Inner**)(workspace + 16) = data;
    workspace[20] = workspace[12];

    if ((workspace[12] == 1 ? -1 : (*(Inner**)(workspace + 16))->kind) != 0) return 0;
    local.done();
    Middle* middle = self->middle;
    Target* target = middle->holder->target;
    s32 arg;
    if (workspace[20] == 1) arg = 0; else arg = (*(Inner**)(workspace + 16))->field4;
    return target->update(arg, &local, middle);
}
