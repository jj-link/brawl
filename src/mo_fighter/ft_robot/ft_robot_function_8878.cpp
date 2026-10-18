#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct PostureModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual float getLr();
};

struct ResourceAccesser {
    virtual void slot08();
    virtual void slot0C();
    virtual int getId();
};

struct ResourceModule {
    virtual void slot08();
    virtual void slot0C();
    virtual ResourceAccesser* getAccesser();
};

struct OwnerAccesser {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual int getId();
};

struct OwnerBase {
    unsigned int padding[2];
};

struct OwnerModule : OwnerBase {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual OwnerAccesser* getAccesser();
};

struct EffectModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void invoke(int, bool, bool, int);
};

struct ModuleTable {
    OwnerModule* owner;
    unsigned char padding04[8];
    PostureModule* posture;
    unsigned char padding10[8];
    ResourceModule* resource;
    unsigned char padding1C[0x40];
    EffectModule* effect;
};

struct ObjectData {
    unsigned char padding[0x28];
    unsigned int taskId;
};

struct soModuleAccesser {
    unsigned char padding00[8];
    ObjectData* objectData;
    unsigned char padding0C[0xCC];
    ModuleTable* modules;
};

extern "C" {
extern const float lbl_120_rodata_8;
void fn_120_8718(Vec3f*, float, float, float);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
int randi__Fl(long);
void fn_120_17FB4(
    void*, unsigned int, int, int, const Vec3f*, float, int, int);
}

extern "C" bool fn_120_8878(void* request, soModuleAccesser* accesser) {
    ResourceModule* resource;
    OwnerModule* owner;
    unsigned int taskId;
    float direction = accesser->modules->posture->getLr();
    Vec3f position;
    fn_120_8718(&position, lbl_120_rodata_8,
                lbl_120_rodata_8, lbl_120_rodata_8);

    int choice = 0;
    if (getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x5DCB, 0) > 1) {
        choice = randi__Fl(
            getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0x5DCB, 0));
        if (choice == 0 || choice == 2) {
            accesser->modules->effect->invoke(2, false, false, 8);
        }
    }

    resource = accesser->modules->resource;
    owner = accesser->modules->owner;
    taskId = accesser->objectData->taskId;

    fn_120_17FB4(
        request, taskId, owner->getAccesser()->getId(),
        resource->getAccesser()->getId(), &position, direction,
        getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x5DCB, 0),
        choice);
    return true;
}
