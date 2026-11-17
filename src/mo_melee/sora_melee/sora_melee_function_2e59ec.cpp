#include <new>
#include <so/so_module_accesser.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class Object_vptr_0 {
public:
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int slot5();
    virtual int slot6();
    virtual int slot7();
    virtual int slot8();
    virtual int slot9();
    virtual int slot10();
    virtual int slot11();
    virtual int slot12();
    virtual int slot13();
    virtual int slot14();
    virtual int slot15();
    virtual int slot16();
    virtual int slot17();
    virtual int slot18();
    virtual int slot19();
    virtual int slot20();
    virtual int slot21();
    virtual int slot22();
    virtual int slot23();
    virtual int slot24();
    virtual int slot25();
    virtual int slot26();
    virtual int slot27();
    virtual int slot28();
    virtual int slot29();
    virtual int slot30();
    virtual int slot31();
    virtual int slot32();
};

class ModuleTaskInterface {
public:
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int slot5();
    virtual int slot6();
    virtual int slot7();
};

class ModuleNullableInterface {
public:
    virtual bool isNull() const;
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};

class ModuleRegistryInterface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void add(int, ModuleNullableInterface*);
};

extern "C" {
void fn_27_2DA1F0(void*);
void fn_27_2E654C(void*);

#define DECL_GET(name) void* name(void*)
DECL_GET(fn_27_2DA200);
DECL_GET(fn_27_2DA20C);
DECL_GET(fn_27_2DA218);
DECL_GET(fn_27_2DA224);
DECL_GET(fn_27_2DA230);
DECL_GET(fn_27_2DA248);
DECL_GET(fn_27_2DA254);
DECL_GET(fn_27_2DA260);
DECL_GET(fn_27_2DA278);
DECL_GET(fn_27_2DA290);
DECL_GET(fn_27_2DA29C);
DECL_GET(fn_27_2DA2A8);
DECL_GET(fn_27_2DA2B4);
DECL_GET(fn_27_2DA2C0);
DECL_GET(fn_27_2DA2CC);
DECL_GET(fn_27_2DA2D8);
DECL_GET(fn_27_2DA2E4);
DECL_GET(fn_27_2DA2F0);
DECL_GET(fn_27_2DA2FC);
DECL_GET(fn_27_2DA308);
DECL_GET(fn_27_2DA314);
DECL_GET(fn_27_2DA320);
DECL_GET(fn_27_2DA32C);
DECL_GET(fn_27_2DA338);
DECL_GET(fn_27_2DA804);
DECL_GET(fn_27_2DA81C);
DECL_GET(fn_27_2DA824);
DECL_GET(fn_27_2DA82C);
DECL_GET(fn_27_2DA834);
DECL_GET(fn_27_2DA83C);
DECL_GET(fn_27_2DA844);
DECL_GET(fn_27_2DA84C);
DECL_GET(fn_27_2DA854);
DECL_GET(fn_27_2DA858);
DECL_GET(fn_27_2DA864);
DECL_GET(fn_27_2DA870);
DECL_GET(fn_27_2DA888);
DECL_GET(fn_27_2DA890);
DECL_GET(fn_27_2DA894);
DECL_GET(fn_27_2DA898);
DECL_GET(fn_27_2DA89C);
DECL_GET(fn_27_2DA8A0);
DECL_GET(fn_27_2E1E40);
DECL_GET(fn_27_2E1E44);
DECL_GET(fn_27_2E1E48);
DECL_GET(fn_27_2E6C48);
DECL_GET(fn_27_2E6C50);
DECL_GET(fn_27_2E6C58);
DECL_GET(fn_27_2E6C60);
DECL_GET(fn_27_2E6C68);
DECL_GET(fn_27_2E6C6C);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
unsigned char* fn_27_2DA348(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
void* fn_27_2DBBA0(void*);
void* fn_27_2E59E4(void*);
void fn_27_2DA354(void*, void*, int, unsigned char, int);
void fn_27_2DA358(void*, void*, int, unsigned char);
void fn_27_2DA35C(void*, void*, int, unsigned char);
void fn_27_2DA360(void*, void*, int, unsigned char);
void fn_27_2DA364(void*, void*, int, unsigned char);
void fn_27_2DA36C(void*, void*, int);
void fn_27_2DA370(void*, void*);
void fn_27_2DA374(void*, void*);
void fn_27_2DA37C(void*, void*);
void fn_27_2DA384(void*, void*, short);
void fn_27_2DA388(void*, void*, int, int, int);
void fn_27_2DA38C(void*, void*);
void fn_27_2DA390(void*, void*);
void fn_27_2DA394(void*, void*, unsigned char, int);
void fn_27_2DA398(void*, void*, int, int);
void fn_27_2DA39C(void*, void*, int);
void fn_27_2DA3A0(void*, void*, int);
void fn_27_2DA3A4(void*, void*);
void fn_27_2DA3A8(void*, void*);
void fn_27_2DA3AC(void*, void*, int);
void fn_27_2DA3B0(void*, void*);
void fn_27_2DA3B4(void*, void*, int);
void fn_27_2DA3B8(void*, void*);
void fn_27_2DA3BC(void*, void*, int);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E1524(void*, int, void*);
void fn_27_1E15A4(void*, void*, int);
void fn_27_1E1648(void*, void*);
void fn_27_1E16CC(void*, short);
void fn_27_1E1774(void*);
void fn_27_1E38AC(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_2DAD80(void*, void*, int, unsigned char, int);
void fn_27_2DB024(void*, void*, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_2DB778(void*, void*, int, int, int, int, int);
void fn_27_2DBB0C(void*, void*);
void fn_27_2DBB3C(void*, void*);
void fn_27_2DBB70(void*, void*);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_2E21CC(void*, void*);
void fn_27_2E21FC(void*, void*, int);
void fn_27_2E6C74(void*, void*, int, int);
void fn_27_2E6D5C(void*, void*, int);
void fn_27_2E6F0C(void*, void*, int, unsigned char);
void fn_27_2E717C(void*, void*, int, int);
void fn_27_2E760C(void*, void*);
int fn_27_2815A0();
int fn_27_2815F4(StageObject*);
unsigned char fn_27_2815FC(StageObject*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x4E0)

extern "C" void* fn_27_2E59EC(
    void* self, StageObject* stageObject, Object_vptr_0* buildData,
    void* arg_sp0)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_2E654C(self);

    void* r18 = fn_27_2DA8A0(object + 0x15B8);
    void* r19 = fn_27_2DA89C(object + 0x5D8);
    void* r20 = fn_27_2DA898(object + 0x5C0);
    void* r21 = fn_27_2DA894(object + 0x1578);
    void* r22 = fn_27_2DA890(object + 0x1560);
    void* r23 = fn_27_2DA338(object + 0x155E);
    void* r24 = fn_27_2DA32C(object + 0x155D);
    void* r25 = fn_27_2DA320(object + 0x155C);
    void* r26 = fn_27_2DA314(object + 0x155B);
    void* r27 = fn_27_2DA308(object + 0x155A);
    void* r28 = fn_27_2DA2FC(object + 0x1559);
    void* r29 = fn_27_2DA2F0(object + 0x1558);
    void* r30 = fn_27_2DA2E4(object + 0x1557);
    void* r31 = fn_27_2DA2D8(object + 0x1556);
    void* r14 = fn_27_2DA2CC(object + 0x1555);
    void* spC0 = fn_27_2DA2C0(object + 0x1554);
    void* spC4 = fn_27_2DA888(object + 0x13C4);
    void* spC8 = fn_27_2DA2B4(object + 0x13C0);
    void* spCC = fn_27_2E6C6C(object);
    void* spD0 = fn_27_2E6C68(object + 0x12EC);

    new (accesser) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x5E8),
        MODULE(soModelModule, fn_27_2E6C48, 0x618),
        MODULE(soMotionModule, fn_27_2E6C50, 0x728),
        MODULE(soPostureModule, fn_27_2DA81C, 0x8B4),
        MODULE(soGroundModule, fn_27_2DA824, 0x968),
        MODULE(soSituationModule, fn_27_2E1E40, 0xA10),
        fn_27_2DA82C(object + 0xA4C),
        MODULE(soCollisionAttackModule, fn_27_2DA834, 0xAB0),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0xC74),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0xC75),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0xC76),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0xC77),
        fn_27_2DA230(object + 0xC78),
        MODULE(soCollisionSearchModule, fn_27_2E6C58, 0xC7C),
        MODULE(soDamageModule, fn_27_2DA248, 0xE74),
        fn_27_2DA254(object + 0xE75),
        fn_27_2DA260(object + 0xE76),
        MODULE(soStopModule, fn_27_2E1E44, 0xE78),
        fn_27_2DA278(object + 0xE9C),
        fn_27_2DA83C(object + 0xEA0),
        MODULE(soSoundModule, fn_27_2DA844, 0xEAC),
        MODULE(soLinkModule, fn_27_2DA84C, 0xF14),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0x1078),
        MODULE(soControllerModule, fn_27_2DA290, 0x108C),
        MODULE(soCameraModule, fn_27_2DA29C, 0x108D),
        MODULE(soWorkManageModule, fn_27_2DA854, 0x1090),
        fn_27_2DA2A8(object + 0x15D0),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0x10C4),
        MODULE(soStatusModule, fn_27_2E6C60, 0x1168),
        fn_27_2DA864(object + 0x12E8),
        fn_27_2DA870(object + 0x12E9),
        static_cast<soKineticModule*>(spD0),
        static_cast<soEventManageModule*>(spCC),
        spC8,
        static_cast<soEffectModule*>(spC4),
        spC0,
        static_cast<soAreaModule*>(r14),
        r31,
        r30,
        r29,
        r28,
        static_cast<soShadowModule*>(r27),
        static_cast<soItemManageModule*>(r26),
        static_cast<soColorBlendModule*>(r25),
        r24,
        r23,
        static_cast<soSlowModule*>(r22),
        r21,
        r20,
        static_cast<soParamCustomizeModule*>(r19),
        r18);

    fn_27_2DA8A4(object + 0x5C0, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x5D8, accesser);

    int situation = buildData->slot2();
    fn_27_1E107C(object + 0x5E8, buildData->slot0(),
                 buildData->slot1(),
                 static_cast<unsigned char>(situation), accesser);
    int modelData;
    int modelArg = fn_27_2815A0();
    modelData = buildData->slot24();
    buildData->slot18();
    fn_27_2E6C74(object + 0x618, accesser, modelData, modelArg);
    fn_27_2E6D5C(object + 0x728, accesser, buildData->slot4());
    fn_27_2DAC38(object + 0x8B4, accesser, fn_27_2815A0());
    fn_27_1E38AC(object + 0x968, accesser, buildData->slot8());

    int taskId;
    int taskArg = fn_27_2815A0();
    taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2E2190(object + 0xA10, accesser, static_cast<short>(taskId), taskArg);
    fn_27_1E1524(object + 0xA4C, buildData->slot3(), accesser);

    fn_27_2DAD80(object + 0xAB0, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0xC74, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0xC75, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0xC76, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0xC77, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0xC78, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2E6F0C(object + 0xC7C, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));

    fn_27_2DA36C(object + 0xE74, accesser, fn_27_2815A0());
    fn_27_2DA370(object + 0xE75, accesser);
    fn_27_2DA374(object + 0xE76, accesser);
    fn_27_2E21CC(object + 0xE78, accesser);
    fn_27_2DA37C(object + 0xE9C, accesser);

    fn_27_1E15A4(object + 0xEA0, accesser, buildData->slot5());
    fn_27_2DB024(object + 0xEAC, accesser, buildData->slot31(),
                 fn_27_2815A0());
    fn_27_1E1648(object + 0xF14, accesser);
    fn_27_2E21FC(object + 0x1078, accesser, buildData->slot6());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0x108C, accesser,
                 static_cast<short>(controllerTaskId));
    fn_27_2DA388(object + 0x108D, accesser, buildData->slot21(),
                 buildData->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0x1090, accesser, buildData->slot19());

    int animTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0x10C4, static_cast<short>(animTaskId));
    fn_27_2E717C(object + 0x1168, accesser, buildData->slot7(),
                 buildData->slot26());
    fn_27_2DB554(object + 0x12E8);
    fn_27_2DB558(object + 0x12E9);
    fn_27_2E760C(object + 0x12EC, accesser);
    fn_27_1E1774(object + 0x1364);
    fn_27_2DA38C(object + 0x13C0, accesser);

    fn_27_2DB778(object + 0x13C4, accesser, buildData->slot9(),
                 buildData->slot10(), buildData->slot11(),
                 buildData->slot12(), fn_27_2815A0());

    fn_27_2DA390(object + 0x1554, accesser);
    int areaValue;
    int areaArg = fn_27_2815A0();
    areaValue = buildData->slot20();
    fn_27_2DA394(object + 0x1555, accesser,
                 static_cast<unsigned char>(areaValue), areaArg);
    fn_27_2DA398(object + 0x1556, accesser, buildData->slot13(),
                 buildData->slot14());
    fn_27_2DA39C(object + 0x1557, accesser, buildData->slot15());
    fn_27_2DA3A0(object + 0x1558, accesser, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x1559, accesser);
    fn_27_2DA3A8(object + 0x155A, accesser);
    fn_27_2DA3AC(object + 0x155B, accesser, buildData->slot23());
    fn_27_2DA3B0(object + 0x155C, accesser);
    fn_27_2DA3B4(object + 0x155D, accesser, buildData->slot25());
    fn_27_2DA3B8(object + 0x155E, accesser);
    fn_27_2DBB0C(object + 0x1560, accesser);
    fn_27_2DBB3C(object + 0x1578, accesser);
    fn_27_2DBB70(object + 0x15B8, accesser);
    fn_27_2DA3BC(object + 0x15D0, accesser, fn_27_2815A0());

    if (!reinterpret_cast<ModuleNullableInterface*>(
             fn_27_2DBBA0(object + 0x1364))->isNull()) {
        ModuleNullableInterface* listener =
            reinterpret_cast<ModuleNullableInterface*>(
                fn_27_2DBBA0(object + 0x1364));
        fn_27_2DA3C0(fn_27_2E59E4(self))->add(1, listener);
    }

    (void)arg_sp0;
    return self;
}
