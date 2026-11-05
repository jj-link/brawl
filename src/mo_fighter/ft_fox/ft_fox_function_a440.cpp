#pragma force_active on
#pragma scheduling off

class Class_789C {
public:
    virtual void fn_97_8138();
    virtual void fn_97_10664();
    virtual void fn_97_10B20();
    virtual void fn_97_10B1C();
    virtual void fn_97_10B18();
    virtual void fn_97_10B14();
    virtual void fn_97_10B0C();
    virtual void fn_97_10B54();
    virtual void fn_97_10B4C();
    virtual void fn_97_10B44();
    virtual void fn_97_10B3C();
    virtual void fn_97_10B34();
    virtual void fn_97_10ACC();
    virtual void fn_97_10B00();
    virtual void fn_97_10AF4();
    virtual int fn_97_10AEC();
};

class Class_7A1C {
public:
    virtual void fn_97_8138();
    virtual void fn_97_10608();
    virtual void fn_97_10CE4();
    virtual void fn_97_10CDC();
    virtual void fn_97_10CD4();
    virtual void fn_97_10CCC();
    virtual void fn_97_10CC4();
    virtual void fn_97_10CBC();
    virtual void fn_97_10CB4();
    virtual void fn_97_10CAC();
    virtual void fn_97_10CA4();
    virtual void fn_97_10C9C();
    virtual void fn_97_10C94();
    virtual void fn_97_10C8C();
    virtual void fn_97_10C3C();
    virtual void fn_97_10C84();
};

struct Work {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual int get(int);
    virtual void set(int, int);
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
struct Owner {
    int a, b;
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual Class_789C* get();
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
    unsigned int taskId;
};
struct Accesser {
    char pad00[8];
    StageObject* object;
    char pad0c[0xcc];
    Modules* modules;
};
extern "C" void fn_97_107F8(void*, unsigned int, int, int, unsigned char, float, int);
extern "C" int fn_97_A440(void* self, Accesser* accesser) {
    int count = accesser->modules->work->get(0x20000003);
    int active = count ? 1 : 0;
    Ground* ground = accesser->modules->ground;
    Resource* resource = accesser->modules->resource;
    Owner* owner = accesser->modules->owner;
    unsigned int taskId = accesser->object->taskId;
    Posture* posture = accesser->modules->posture;
    fn_97_107F8(self, taskId, owner->get()->fn_97_10AEC(),
        resource->get()->get(), ground->get(), posture->getLr(), active);
    accesser->modules->work->set(count + 1, 0x20000003);
    return 0;
}