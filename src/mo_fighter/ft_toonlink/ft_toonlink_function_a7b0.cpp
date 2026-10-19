#pragma force_active on
struct ResourceIdAccesser {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual unsigned int getMdlResId();
};

struct ResourceModule {
    char unused[8];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual ResourceIdAccesser* getResourceIdAccesser();
};

struct PostureModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float getLr();
};

struct ModuleEnumeration {
    ResourceModule* resource;
    char unused[8];
    PostureModule* posture;
};

struct ModuleAccesser {
    char unused[0xD8];
    ModuleEnumeration* modules;
};

extern "C" void* fn_121_A740();
extern "C" void fn_27_3A5C74(
    void*, void*, ModuleAccesser*, unsigned int, float);

extern "C" void fn_121_A7B0(void* object, ModuleAccesser* accesser) {
    ResourceModule* resource = accesser->modules->resource;
    float facing = accesser->modules->posture->getLr();
    unsigned int modelId =
        resource->getResourceIdAccesser()->getMdlResId();

    fn_27_3A5C74(fn_121_A740(), object, accesser, modelId, facing);
}
