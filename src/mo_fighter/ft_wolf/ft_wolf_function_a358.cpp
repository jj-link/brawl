#pragma force_active on
#pragma scheduling off

typedef unsigned int u32;

struct Info {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual int get();
};

struct Owner {
    int a;
    int b;
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual Info* get();
};

struct Posture {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual float getLr();
};

struct Ground {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual int get();
};

struct ResourceId {
    virtual void f08();
    virtual void f0c();
    virtual int get();
};

struct Resource {
    virtual void f08();
    virtual void f0c();
    virtual ResourceId* get();
};

struct Work {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual int isFlag(int);
    virtual void offFlag(int, int);
};

struct Modules {
    Owner* owner;
    char pad04[8];
    Posture* posture;
    char pad10[4];
    Ground* ground;
    Resource* resource;
    char pad1c[0x48];
    Work* work;
};

struct StageObject {
    char pad[0x28];
    u32 taskId;
};

struct Accesser {
    char pad00[8];
    StageObject* object;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" void fn_125_10710(void*, u32, int, int, unsigned char, float, int);

extern "C" int fn_125_A358(void* self, Accesser* accesser) {
    int count = accesser->modules->work->isFlag(0x20000003);
    int active = count ? 1 : 0;
    Ground* ground = accesser->modules->ground;
    Resource* resource = accesser->modules->resource;
    Owner* owner = accesser->modules->owner;
    u32 taskId = accesser->object->taskId;
    Posture* posture = accesser->modules->posture;

    fn_125_10710(self, taskId, owner->get()->get(),
        resource->get()->get(), ground->get() & 0xff, posture->getLr(), active);

    accesser->modules->work->offFlag(count + 1, 0x20000003);
    return 0;
}