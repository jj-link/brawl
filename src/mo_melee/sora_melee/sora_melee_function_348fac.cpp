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
void* fn_27_349B0C(void*);

#define DECL_GET(name) void* name(void*)
DECL_GET(fn_27_2DA8A0);
DECL_GET(fn_27_2DA89C);
DECL_GET(fn_27_2DA898);
DECL_GET(fn_27_2DA894);
DECL_GET(fn_27_2DA890);
DECL_GET(fn_27_2DA338);
DECL_GET(fn_27_2DA32C);
DECL_GET(fn_27_2DA320);
DECL_GET(fn_27_2DA314);
DECL_GET(fn_27_2DA308);
DECL_GET(fn_27_349E14);
DECL_GET(fn_27_2DA2F0);
DECL_GET(fn_27_2DA2E4);
DECL_GET(fn_27_2DA2D8);
DECL_GET(fn_27_2DA2CC);
DECL_GET(fn_27_2DA2C0);
DECL_GET(fn_27_2DA888);
DECL_GET(fn_27_2DA2B4);
DECL_GET(fn_27_349E0C);
DECL_GET(fn_27_349E08);
DECL_GET(fn_27_2DA870);
DECL_GET(fn_27_2DA864);
DECL_GET(fn_27_2E1E4C);
DECL_GET(fn_27_2DA858);
DECL_GET(fn_27_2DA2A8);
DECL_GET(fn_27_2DA854);
DECL_GET(fn_27_2DA29C);
DECL_GET(fn_27_2DA290);
DECL_GET(fn_27_2E1E48);
DECL_GET(fn_27_2DA84C);
DECL_GET(fn_27_2DA844);
DECL_GET(fn_27_2DA83C);
DECL_GET(fn_27_2DA278);
DECL_GET(fn_27_2E1E44);
DECL_GET(fn_27_2DA260);
DECL_GET(fn_27_2DA254);
DECL_GET(fn_27_349E00);
DECL_GET(fn_27_2DA23C);
DECL_GET(fn_27_2DA230);
DECL_GET(fn_27_2DA224);
DECL_GET(fn_27_2DA218);
DECL_GET(fn_27_2DA20C);
DECL_GET(fn_27_349DF8);
DECL_GET(fn_27_2DA834);
DECL_GET(fn_27_2DA82C);
DECL_GET(fn_27_2E1E40);
DECL_GET(fn_27_2DA824);
DECL_GET(fn_27_2DA81C);
DECL_GET(fn_27_30921C);
DECL_GET(fn_27_2DA80C);
DECL_GET(fn_27_2DA804);
DECL_GET(fn_27_2DA83C);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E10E0(void*, void*, int, int);
void fn_27_30922C(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_1E38AC(void*, void*, int);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_1E1524(void*, int, void*);
void fn_27_2DAD80(void*, void*, int, unsigned char, int);
void fn_27_349E18(void*, void*, int, unsigned char, int);
void fn_27_2DA358(void*, void*, int, unsigned char);
void fn_27_2DA35C(void*, void*, int, unsigned char);
void fn_27_2DA360(void*, void*, int, unsigned char);
void fn_27_2DA364(void*, void*, int, unsigned char);
void fn_27_2DA368(void*, void*, int, unsigned char);
void fn_27_34A058(void*, void*, int);
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
void fn_27_2E2230(void*, void*, int, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_34A1C4(void*, void*);
void fn_27_1E1774(void*);
void fn_27_2DA38C(void*, void*);
void fn_27_2DB778(void*, void*, int, int, int, int, int);
void fn_27_2DA390(void*, void*);
void fn_27_2DA394(void*, void*, unsigned char, int);
void fn_27_2DA398(void*, void*, int, int);
void fn_27_2DA39C(void*, void*, int);
void fn_27_2DA3A0(void*, void*, int);
void fn_27_34A3A4(void*, void*);
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
unsigned char fn_27_2815FC(StageObject*);
unsigned char* fn_27_2DA348(void*);
ModuleNullableInterface* fn_27_2DBBA0(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
void* fn_27_348FA4(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x804)

extern "C" void* fn_27_348FAC(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);
    int buildValue;
    int moduleValue;

    fn_27_2DA1F0(self);
    fn_27_349B0C(self);

    new (accesser) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x90C),
        MODULE(soModelModule, fn_27_2DA80C, 0x93C),
        MODULE(soMotionModule, fn_27_30921C, 0xB1C),
        MODULE(soPostureModule, fn_27_2DA81C, 0xD28),
        MODULE(soGroundModule, fn_27_2DA824, 0xDDC),
        MODULE(soSituationModule, fn_27_2E1E40, 0xE84),
        fn_27_2DA82C(object + 0xEC0),
        MODULE(soCollisionAttackModule, fn_27_2DA834, 0xF24),
        MODULE(soCollisionHitModule, fn_27_349DF8, 0x10E8),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0x128C),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0x128D),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0x128E),
        fn_27_2DA230(object + 0x128F),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0x1290),
        MODULE(soDamageModule, fn_27_349E00, 0x1294),
        fn_27_2DA254(object + 0x13EC),
        fn_27_2DA260(object + 0x13ED),
        MODULE(soStopModule, fn_27_2E1E44, 0x13F0),
        fn_27_2DA278(object + 0x1414),
        fn_27_2DA83C(object + 0x1418),
        MODULE(soSoundModule, fn_27_2DA844, 0x1424),
        MODULE(soLinkModule, fn_27_2DA84C, 0x148C),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0x15F0),
        MODULE(soControllerModule, fn_27_2DA290, 0x1604),
        MODULE(soCameraModule, fn_27_2DA29C, 0x1605),
        MODULE(soWorkManageModule, fn_27_2DA854, 0x1608),
        fn_27_2DA2A8(object + 0x1CC0),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0x163C),
        MODULE(soStatusModule, fn_27_2E1E4C, 0x16E0),
        fn_27_2DA864(object + 0x18A4),
        fn_27_2DA870(object + 0x18A5),
        MODULE(soKineticModule, fn_27_349E08, 0x18A8),
        static_cast<soEventManageModule*>(fn_27_349E0C(self)),
        fn_27_2DA2B4(object + 0x1A2C),
        MODULE(soEffectModule, fn_27_2DA888, 0x1A30),
        fn_27_2DA2C0(object + 0x1BC0),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x1BC1),
        fn_27_2DA2D8(object + 0x1BC2),
        fn_27_2DA2E4(object + 0x1BC3),
        fn_27_2DA2F0(object + 0x1BC4),
        fn_27_349E14(object + 0x1BC8),
        MODULE(soShadowModule, fn_27_2DA308, 0x1C48),
        MODULE(soItemManageModule, fn_27_2DA314, 0x1C49),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x1C4A),
        fn_27_2DA32C(object + 0x1C4B),
        fn_27_2DA338(object + 0x1C4C),
        MODULE(soSlowModule, fn_27_2DA890, 0x1C50),
        fn_27_2DA894(object + 0x1C68),
        fn_27_2DA898(object + 0x8E4),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x8FC),
        fn_27_2DA8A0(object + 0x1CA8));

    fn_27_2DA8A4(object + 0x8E4, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x8FC, accesser);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x90C, buildData->slot0(),
                 buildData->slot1(), static_cast<unsigned char>(resourceGroup),
                 accesser);
    moduleValue = fn_27_2815A0();
    buildValue = buildData->slot24();
    buildData->slot18();
    fn_27_1E10E0(object + 0x93C, accesser, buildValue, moduleValue);
    fn_27_30922C(object + 0xB1C, accesser, buildData->slot4());
    fn_27_2DAC38(object + 0xD28, accesser, fn_27_2815A0());
    fn_27_1E38AC(object + 0xDDC, accesser, buildData->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2E2190(object + 0xE84, accesser,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0xEC0, buildData->slot3(), accesser);

    fn_27_2DAD80(object + 0xF24, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_349E18(object + 0x10E8, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0x128C, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0x128D, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0x128E, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0x128F, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0x1290, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_34A058(object + 0x1294, accesser, fn_27_2815A0());

    fn_27_2DA370(object + 0x13EC, accesser);
    fn_27_2DA374(object + 0x13ED, accesser);
    fn_27_2E21CC(object + 0x13F0, accesser);
    fn_27_2DA37C(object + 0x1414, accesser);
    fn_27_1E15A4(object + 0x1418, accesser, buildData->slot5());
    fn_27_2DB024(object + 0x1424, accesser, buildData->slot31(),
                 fn_27_2815A0());
    fn_27_1E1648(object + 0x148C, accesser);
    fn_27_2E21FC(object + 0x15F0, accesser, buildData->slot6());

    int taskId2 = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0x1604, accesser,
                 static_cast<short>(taskId2));
    fn_27_2DA388(object + 0x1605, accesser, buildData->slot21(),
                 buildData->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0x1608, accesser, buildData->slot19());

    int taskId3 = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0x163C, static_cast<short>(taskId3));
    fn_27_2E2230(object + 0x16E0, accesser, buildData->slot7(),
                 buildData->slot26());

    fn_27_2DB554(object + 0x18A4);
    fn_27_2DB558(object + 0x18A5);
    fn_27_34A1C4(object + 0x18A8, accesser);
    fn_27_1E1774(object + 0x19D0);
    fn_27_2DA38C(object + 0x1A2C, accesser);
    fn_27_2DB778(object + 0x1A30, accesser, buildData->slot9(),
                 buildData->slot10(), buildData->slot11(),
                 buildData->slot12(), fn_27_2815A0());

    fn_27_2DA390(object + 0x1BC0, accesser);
    int workFlagHeap = fn_27_2815A0();
    int workFlag = buildData->slot20();
    fn_27_2DA394(object + 0x1BC1, accesser,
                 static_cast<unsigned char>(workFlag), workFlagHeap);
    fn_27_2DA398(object + 0x1BC2, accesser, buildData->slot13(),
                 buildData->slot14());
    fn_27_2DA39C(object + 0x1BC3, accesser, buildData->slot15());
    fn_27_2DA3A0(object + 0x1BC4, accesser, buildData->slot16());
    buildData->slot32();
    fn_27_34A3A4(object + 0x1BC8, accesser);
    fn_27_2DA3A8(object + 0x1C48, accesser);
    fn_27_2DA3AC(object + 0x1C49, accesser, buildData->slot23());
    fn_27_2DA3B0(object + 0x1C4A, accesser);
    fn_27_2DA3B4(object + 0x1C4B, accesser, buildData->slot25());
    fn_27_2DA3B8(object + 0x1C4C, accesser);
    fn_27_2DBB0C(object + 0x1C50, accesser);
    fn_27_2DBB3C(object + 0x1C68, accesser);
    fn_27_2DBB70(object + 0x1CA8, accesser);
    fn_27_2DA3BC(object + 0x1CC0, accesser, fn_27_2815A0());

    ModuleNullableInterface* nullable =
        fn_27_2DBBA0(object + 0x19D0);
    if (!nullable->isNull()) {
        nullable = fn_27_2DBBA0(object + 0x19D0);
        fn_27_2DA3C0(fn_27_348FA4(self))->add(1, nullable);
    }

    return self;
}

#undef accesser
#undef MODULE
