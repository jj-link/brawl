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
void fn_27_2DA3CC(void*);

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
DECL_GET(fn_27_3B01A0);
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
DECL_GET(fn_27_2F4FB4);
DECL_GET(fn_27_2DA82C);
DECL_GET(fn_27_2DA834);
DECL_GET(fn_27_2DA83C);
DECL_GET(fn_27_2DA844);
DECL_GET(fn_27_2DA84C);
DECL_GET(fn_27_2DA854);
DECL_GET(fn_27_2DA858);
DECL_GET(fn_27_2DA864);
DECL_GET(fn_27_2DA870);
DECL_GET(fn_27_2DA87C);
DECL_GET(fn_27_2DA880);
DECL_GET(fn_27_2DA888);
DECL_GET(fn_27_2DA890);
DECL_GET(fn_27_2DA894);
DECL_GET(fn_27_2DA898);
DECL_GET(fn_27_2DA89C);
DECL_GET(fn_27_2F1A54);
DECL_GET(fn_27_30921C);
DECL_GET(fn_27_2E1E40);
DECL_GET(fn_27_2E1E44);
DECL_GET(fn_27_2E1E48);
DECL_GET(fn_27_2E1E4C);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E10E0(void*, void*, float, int, int);
void fn_27_30922C(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_2F4FCC(void*, void*, int);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_1E1524(void*, int, void*);
void fn_27_2DAD80(void*, void*, int, unsigned char, int);
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
void fn_27_3B0274(void*, void*, int, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_1E16CC(void*, short);
void fn_27_2E2230(void*, void*, int, int);
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
void fn_27_2F1A60(void*, void*);
void fn_27_2DA3BC(void*, void*, int);

int fn_27_2815A0();
int fn_27_2815F4(StageObject*);
int fn_27_2815FC(StageObject*);
unsigned char* fn_27_2DA348(void*);
ModuleNullableInterface* fn_27_2DBBA0(void*);
void* fn_27_3B4FE8(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x7F8)

extern "C" void* fn_27_3B4FF0(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_2DA3CC(self);

    new (object + 0x7F8) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x900),
        MODULE(soModelModule, fn_27_2DA80C, 0x930),
        MODULE(soMotionModule, fn_27_30921C, 0xB10),
        MODULE(soPostureModule, fn_27_2DA81C, 0xD1C),
        MODULE(soGroundModule, fn_27_2F4FB4, 0xDD0),
        MODULE(soSituationModule, fn_27_2E1E40, 0xDD4),
        fn_27_2DA82C(object + 0xE10),
        MODULE(soCollisionAttackModule, fn_27_2DA834, 0xE74),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0x1038),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0x1039),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0x103A),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0x103B),
        fn_27_2DA230(object + 0x103C),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0x103D),
        MODULE(soDamageModule, fn_27_2DA248, 0x103E),
        fn_27_2DA254(object + 0x103F),
        fn_27_2DA260(object + 0x1040),
        MODULE(soStopModule, fn_27_2E1E44, 0x1044),
        fn_27_2DA278(object + 0x1068),
        fn_27_2DA83C(object + 0x106C),
        MODULE(soSoundModule, fn_27_2DA844, 0x1078),
        MODULE(soLinkModule, fn_27_2DA84C, 0x10E0),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0x1244),
        MODULE(soControllerModule, fn_27_2DA290, 0x1258),
        MODULE(soCameraModule, fn_27_3B01A0, 0x125C),
        MODULE(soWorkManageModule, fn_27_2DA854, 0x1278),
        fn_27_2DA2A8(object + 0x1821),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0x12AC),
        MODULE(soStatusModule, fn_27_2E1E4C, 0x1350),
        fn_27_2DA864(object + 0x1514),
        fn_27_2DA870(object + 0x1515),
        MODULE(soKineticModule, fn_27_2DA87C, 0x1518),
        static_cast<soEventManageModule*>(fn_27_2DA880(object)),
        fn_27_2DA2B4(object + 0x1628),
        MODULE(soEffectModule, fn_27_2DA888, 0x162C),
        fn_27_2DA2C0(object + 0x17BC),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x17BD),
        fn_27_2DA2D8(object + 0x17BE),
        fn_27_2DA2E4(object + 0x17BF),
        fn_27_2DA2F0(object + 0x17C0),
        fn_27_2DA2FC(object + 0x17C1),
        MODULE(soShadowModule, fn_27_2DA308, 0x17C2),
        MODULE(soItemManageModule, fn_27_2DA314, 0x17C3),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x17C4),
        fn_27_2DA32C(object + 0x17C5),
        fn_27_2DA338(object + 0x17C6),
        MODULE(soSlowModule, fn_27_2DA890, 0x17C8),
        fn_27_2DA894(object + 0x17E0),
        fn_27_2DA898(object + 0x8D8),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x8F0),
        fn_27_2F1A54(object + 0x1820));

    fn_27_2DA8A4(object + 0x8D8, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x8F0, accesser);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x900, buildData->slot0(),
                 buildData->slot1(),
                 static_cast<unsigned char>(resourceGroup), accesser);
    fn_27_1E10E0(object + 0x930, accesser, buildData->slot18(),
                 buildData->slot24(), fn_27_2815A0());
    fn_27_30922C(object + 0xB10, accesser, buildData->slot4());
    fn_27_2DAC38(object + 0xD1C, accesser, fn_27_2815A0());
    fn_27_2F4FCC(object + 0xDD0, accesser, buildData->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2E2190(object + 0xDD4, accesser,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0xE10, buildData->slot3(), accesser);
    fn_27_2DAD80(object + 0xE74, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0x1038, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0x1039, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0x103A, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0x103B, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0x103C, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0x103D, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA36C(object + 0x103E, accesser, fn_27_2815A0());
    fn_27_2DA370(object + 0x103F, accesser);
    fn_27_2DA374(object + 0x1040, accesser);
    fn_27_2E21CC(object + 0x1044, accesser);
    fn_27_2DA37C(object + 0x1068, accesser);
    fn_27_1E15A4(object + 0x106C, accesser, buildData->slot5());
    fn_27_2DB024(object + 0x1078, accesser,
                 buildData->slot31(), fn_27_2815A0());
    fn_27_1E1648(object + 0x10E0, accesser);
    fn_27_2E21FC(object + 0x1244, accesser, buildData->slot6());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0x1258, accesser,
                 static_cast<short>(controllerTaskId));
    fn_27_3B0274(object + 0x125C, accesser, buildData->slot21(),
                 buildData->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0x1278, accesser, buildData->slot19());

    int animCmdTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0x12AC, static_cast<short>(animCmdTaskId));
    fn_27_2E2230(object + 0x1350, accesser, buildData->slot7(),
                 buildData->slot26());
    fn_27_2DB554(object + 0x1514);
    fn_27_2DB558(object + 0x1515);
    fn_27_2DB55C(object + 0x1518, accesser);
    fn_27_1E1774(object + 0x15CC);
    fn_27_2DA38C(object + 0x1628, accesser);
    fn_27_2DB778(object + 0x162C, accesser, buildData->slot9(),
                 buildData->slot10(), buildData->slot11(),
                 buildData->slot12(), fn_27_2815A0());
    fn_27_2DA390(object + 0x17BC, accesser);

    int areaHeap = fn_27_2815A0();
    int areaCategory = buildData->slot20();
    fn_27_2DA394(object + 0x17BD, accesser,
                 static_cast<unsigned char>(areaCategory), areaHeap);
    fn_27_2DA398(object + 0x17BE, accesser, buildData->slot13(),
                 buildData->slot14());
    fn_27_2DA39C(object + 0x17BF, accesser, buildData->slot15());
    fn_27_2DA3A0(object + 0x17C0, accesser, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x17C1, accesser);
    fn_27_2DA3A8(object + 0x17C2, accesser);
    fn_27_2DA3AC(object + 0x17C3, accesser, buildData->slot23());
    fn_27_2DA3B0(object + 0x17C4, accesser);
    fn_27_2DA3B4(object + 0x17C5, accesser, buildData->slot25());
    fn_27_2DA3B8(object + 0x17C6, accesser);
    fn_27_2DBB0C(object + 0x17C8, accesser);
    fn_27_2DBB3C(object + 0x17E0, accesser);
    fn_27_2F1A60(object + 0x1820, accesser);
    fn_27_2DA3BC(object + 0x1821, accesser, fn_27_2815A0());

    if (!fn_27_2DBBA0(object + 0x15CC)->isNull()) {
        ModuleNullableInterface* listener = fn_27_2DBBA0(object + 0x15CC);
        fn_27_2DA3C0(fn_27_3B4FE8(self))->add(1, listener);
    }

    return self;
}