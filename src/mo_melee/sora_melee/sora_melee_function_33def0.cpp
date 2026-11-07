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
    virtual float slot18();
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
    virtual float slot32();
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
void fn_27_33EA50(void*);

#define DECL_GET(name) void* name(void*)
DECL_GET(fn_27_2DA200);
DECL_GET(fn_27_2DA20C);
DECL_GET(fn_27_2DA218);
DECL_GET(fn_27_2DA224);
DECL_GET(fn_27_2DA230);
DECL_GET(fn_27_2DA23C);
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
DECL_GET(fn_27_2DA80C);
DECL_GET(fn_27_2DA81C);
DECL_GET(fn_27_2DA824);
DECL_GET(fn_27_2DA82C);
DECL_GET(fn_27_2DA83C);
DECL_GET(fn_27_2DA844);
DECL_GET(fn_27_2DA84C);
DECL_GET(fn_27_2DA854);
DECL_GET(fn_27_2DA858);
DECL_GET(fn_27_2DA864);
DECL_GET(fn_27_2DA870);
DECL_GET(fn_27_2DA87C);
DECL_GET(fn_27_2DA888);
DECL_GET(fn_27_2DA890);
DECL_GET(fn_27_2DA894);
DECL_GET(fn_27_2DA898);
DECL_GET(fn_27_2DA89C);
DECL_GET(fn_27_2DA8A0);
DECL_GET(fn_27_2E1E40);
DECL_GET(fn_27_2E1E44);
DECL_GET(fn_27_2E1E48);
DECL_GET(fn_27_323580);
DECL_GET(fn_27_33EC80);
DECL_GET(fn_27_33EC88);
DECL_GET(fn_27_33EC90);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E10E0(void*, void*, float, int, int);
void fn_27_33EC98(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_1E38AC(void*, void*, int);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_1E1524(void*, int, void*);
void fn_27_314AEC(void*, void*, int, unsigned char, int);
void fn_27_2DA354(void*, void*, int, unsigned char, int);
void fn_27_2DA358(void*, void*, int, unsigned char);
void fn_27_2DA35C(void*, void*, int, unsigned char);
void fn_27_2DA360(void*, void*, int, unsigned char);
void fn_27_2DA364(void*, void*, int, unsigned char);
void fn_27_2DA368(void*, void*, int, unsigned char);
void fn_27_2DA36C(void*, void*, int);
void fn_27_2DA370(void*, void*);
void fn_27_2DA374(void*, void*);
void fn_27_2E21CC(void*, void*);
void fn_27_2DA37C(void*, void*);
void fn_27_1E15A4(void*, void*, int);
void fn_27_2DB024(void*, void*, int, int);
void fn_27_1E1648(void*, void*);
void fn_27_2E21FC(void*, void*, int);
void fn_27_2DA384(void*, void*, short);
void fn_27_2DA388(void*, void*, int, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_1E16CC(void*, short);
void fn_27_33EF24(void*, void*, int, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_2DB55C(void*, void*);
void fn_27_1E1774(void*);
void fn_27_2DA38C(void*, void*);
void fn_27_2DB778(void*, void*, int, int, int, int, int);
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
void fn_27_2DBB0C(void*, void*);
void fn_27_2DBB3C(void*, void*);
void fn_27_2DBB70(void*, void*);
void fn_27_2DA3BC(void*, void*, int);

int fn_27_2815A0();
int fn_27_2815F4(StageObject*);
int fn_27_2815FC(StageObject*);
unsigned char* fn_27_2DA348(void*);
ModuleNullableInterface* fn_27_2DBBA0(void*);
void* fn_27_33DEE8(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x4B4)

extern "C" void* fn_27_33DEF0(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_33EA50(self);

    new (object + 0x4B4) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x5BC),
        MODULE(soModelModule, fn_27_2DA80C, 0x5EC),
        MODULE(soMotionModule, fn_27_33EC80, 0x7CC),
        MODULE(soPostureModule, fn_27_2DA81C, 0x9D8),
        MODULE(soGroundModule, fn_27_2DA824, 0xA8C),
        MODULE(soSituationModule, fn_27_2E1E40, 0xB34),
        fn_27_2DA82C(object + 0xB70),
        MODULE(soCollisionAttackModule, fn_27_323580, 0xBD4),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0xF48),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0xF49),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0xF4A),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0xF4B),
        fn_27_2DA230(object + 0xF4C),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0xF4D),
        MODULE(soDamageModule, fn_27_2DA248, 0xF4E),
        fn_27_2DA254(object + 0xF4F),
        fn_27_2DA260(object + 0xF50),
        MODULE(soStopModule, fn_27_2E1E44, 0xF54),
        fn_27_2DA278(object + 0xF78),
        fn_27_2DA83C(object + 0xF7C),
        MODULE(soSoundModule, fn_27_2DA844, 0xF88),
        MODULE(soLinkModule, fn_27_2DA84C, 0xFF0),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0x1154),
        MODULE(soControllerModule, fn_27_2DA290, 0x1168),
        MODULE(soCameraModule, fn_27_2DA29C, 0x1169),
        MODULE(soWorkManageModule, fn_27_2DA854, 0x116C),
        fn_27_2DA2A8(object + 0x16F0),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0x11A0),
        MODULE(soStatusModule, fn_27_33EC88, 0x1244),
        fn_27_2DA864(object + 0x13CC),
        fn_27_2DA870(object + 0x13CD),
        MODULE(soKineticModule, fn_27_2DA87C, 0x13D0),
        static_cast<soEventManageModule*>(fn_27_33EC90(object)),
        fn_27_2DA2B4(object + 0x14E0),
        MODULE(soEffectModule, fn_27_2DA888, 0x14E4),
        fn_27_2DA2C0(object + 0x1674),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x1675),
        fn_27_2DA2D8(object + 0x1676),
        fn_27_2DA2E4(object + 0x1677),
        fn_27_2DA2F0(object + 0x1678),
        fn_27_2DA2FC(object + 0x1679),
        MODULE(soShadowModule, fn_27_2DA308, 0x167A),
        MODULE(soItemManageModule, fn_27_2DA314, 0x167B),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x167C),
        fn_27_2DA32C(object + 0x167D),
        fn_27_2DA338(object + 0x167E),
        MODULE(soSlowModule, fn_27_2DA890, 0x1680),
        fn_27_2DA894(object + 0x1698),
        fn_27_2DA898(object + 0x594),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x5AC),
        fn_27_2DA8A0(object + 0x16D8));

    fn_27_2DA8A4(object + 0x594, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x5AC, accesser);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x5BC, buildData->slot0(),
                 buildData->slot1(),
                 static_cast<unsigned char>(resourceGroup), accesser);

    fn_27_1E10E0(object + 0x5EC, accesser, buildData->slot18(),
                 buildData->slot24(), fn_27_2815A0());
    fn_27_33EC98(object + 0x7CC, accesser, buildData->slot4());
    fn_27_2DAC38(object + 0x9D8, accesser, fn_27_2815A0());
    fn_27_1E38AC(object + 0xA8C, accesser, buildData->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2E2190(object + 0xB34, accesser,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0xB70, buildData->slot3(), accesser);
    fn_27_314AEC(object + 0xBD4, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0xF48, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0xF49, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0xF4A, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0xF4B, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0xF4C, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0xF4D, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA36C(object + 0xF4E, accesser, fn_27_2815A0());
    fn_27_2DA370(object + 0xF4F, accesser);
    fn_27_2DA374(object + 0xF50, accesser);
    fn_27_2E21CC(object + 0xF54, accesser);
    fn_27_2DA37C(object + 0xF78, accesser);
    fn_27_1E15A4(object + 0xF7C, accesser, buildData->slot5());
    fn_27_2DB024(object + 0xF88, accesser,
                 buildData->slot31(), fn_27_2815A0());
    fn_27_1E1648(object + 0xFF0, accesser);
    fn_27_2E21FC(object + 0x1154, accesser, buildData->slot6());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0x1168, accesser,
                 static_cast<short>(controllerTaskId));
    fn_27_2DA388(object + 0x1169, accesser, buildData->slot21(),
                 buildData->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0x116C, accesser, buildData->slot19());

    int animCmdTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0x11A0, static_cast<short>(animCmdTaskId));
    fn_27_33EF24(object + 0x1244, accesser, buildData->slot7(),
                 buildData->slot26());
    fn_27_2DB554(object + 0x13CC);
    fn_27_2DB558(object + 0x13CD);
    fn_27_2DB55C(object + 0x13D0, accesser);
    fn_27_1E1774(object + 0x1484);
    fn_27_2DA38C(object + 0x14E0, accesser);
    fn_27_2DB778(object + 0x14E4, accesser, buildData->slot9(),
                 buildData->slot10(), buildData->slot11(),
                 buildData->slot12(), fn_27_2815A0());
    fn_27_2DA390(object + 0x1674, accesser);

    int areaHeap = fn_27_2815A0();
    int areaCategory = buildData->slot20();
    fn_27_2DA394(object + 0x1675, accesser,
                 static_cast<unsigned char>(areaCategory), areaHeap);
    fn_27_2DA398(object + 0x1676, accesser, buildData->slot13(),
                 buildData->slot14());
    fn_27_2DA39C(object + 0x1677, accesser, buildData->slot15());
    fn_27_2DA3A0(object + 0x1678, accesser, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x1679, accesser);
    fn_27_2DA3A8(object + 0x167A, accesser);
    fn_27_2DA3AC(object + 0x167B, accesser, buildData->slot23());
    fn_27_2DA3B0(object + 0x167C, accesser);
    fn_27_2DA3B4(object + 0x167D, accesser, buildData->slot25());
    fn_27_2DA3B8(object + 0x167E, accesser);
    fn_27_2DBB0C(object + 0x1680, accesser);
    fn_27_2DBB3C(object + 0x1698, accesser);
    fn_27_2DBB70(object + 0x16D8, accesser);
    fn_27_2DA3BC(object + 0x16F0, accesser, fn_27_2815A0());

    if (!fn_27_2DBBA0(object + 0x1484)->isNull()) {
        ModuleNullableInterface* listener = fn_27_2DBBA0(object + 0x1484);
        fn_27_2DA3C0(fn_27_33DEE8(self))->add(1, listener);
    }

    return self;
}
