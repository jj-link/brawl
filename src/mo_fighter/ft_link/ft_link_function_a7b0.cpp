#pragma force_active on
struct Posture {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual float getLr();
};

struct ResourceId {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual unsigned int getMdlResId();
};

struct ResourceBase {
    char pad[8];
};

struct Resource : ResourceBase {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual ResourceId* getResourceIdAccesser();
};

struct Modules {
    Resource* resource;
    char pad[8];
    Posture* posture;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void* fn_93_A740();
extern "C" void fn_27_2DE9DC(void*, void*, Accesser*, unsigned int, float);

extern "C" void fn_93_A7B0(void* object, Accesser* accesser) {
    Resource* resource = accesser->modules->resource;
    float lr = accesser->modules->posture->getLr();
    unsigned int mdl = resource->getResourceIdAccesser()->getMdlResId();
    void* instance = fn_93_A740();
    fn_27_2DE9DC(instance, object, accesser, mdl, lr);
}
