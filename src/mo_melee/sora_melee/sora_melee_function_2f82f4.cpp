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
void fn_27_2ECD14(void*);

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
DECL_GET(fn_27_2DA2FC);
DECL_GET(fn_27_2DA308);
DECL_GET(fn_27_2DA314);
DECL_GET(fn_27_2DA320);
DECL_GET(fn_27_2DA32C);
DECL_GET(fn_27_2DA338);
DECL_GET(fn_27_2DA804);
DECL_GET(fn_27_2DA80C);
DECL_GET(fn_27_2DA81C);
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
DECL_GET(fn_27_2E1E40);
DECL_GET(fn_27_2E1E44);
DECL_GET(fn_27_2E1E48);
DECL_GET(fn_27_2ED368);
DECL_GET(fn_27_2F1A54);
DECL_GET(fn_27_2F4FB4);
DECL_GET(fn_27_2F4FC0);
DECL_GET(fn_27_2F8E54);
DECL_GET(fn_27_2F8E5C);
DECL_GET(fn_27_2F8E64);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E10E0(void*, void*, float, int, int);
void fn_27_2F8E6C(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_2F4FCC(void*, void*, int);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_1E1524(void*, int, void*);
void fn_27_2F4FD0(void*, void*, int, unsigned char, int);
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
void fn_27_2F9048(void*, void*, int, int);
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
void fn_27_1E1A6C(void*, void*, int);
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
void* fn_27_2F82EC(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x478)

extern "C" void* fn_27_2F82F4(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_2ECD14(self);

    new (object + 0x478) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x580),
        MODULE(soModelModule, fn_27_2DA80C, 0x5B0),
        MODULE(soMotionModule, fn_27_2F8E54, 0x790),
        MODULE(soPostureModule, fn_27_2DA81C, 0x954),
        MODULE(soGroundModule, fn_27_2F4FB4, 0xA08),
        MODULE(soSituationModule, fn_27_2E1E40, 0xA0C),
        fn_27_2DA82C(object + 0xA48),
        MODULE(soCollisionAttackModule, fn_27_2F4FC0, 0xAAC),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0xAAD),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0xAAE),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0xAAF),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0xAB0),
        fn_27_2DA230(object + 0xAB1),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0xAB2),
        MODULE(soDamageModule, fn_27_2DA248, 0xAB3),
        fn_27_2DA254(object + 0xAB4),
        fn_27_2DA260(object + 0xAB5),
        MODULE(soStopModule, fn_27_2E1E44, 0xAB8),
        fn_27_2DA278(object + 0xADC),
        fn_27_2DA83C(object + 0xAE0),
        MODULE(soSoundModule, fn_27_2DA844, 0xAEC),
        MODULE(soLinkModule, fn_27_2DA84C, 0xB54),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0xCB8),
        MODULE(soControllerModule, fn_27_2DA290, 0xCCC),
        MODULE(soCameraModule, fn_27_2DA29C, 0xCCD),
        MODULE(soWorkManageModule, fn_27_2DA854, 0xCD0),
        fn_27_2DA2A8(object + 0x12A5),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0xD04),
        MODULE(soStatusModule, fn_27_2F8E5C, 0xDA8),
        fn_27_2DA864(object + 0xF4C),
        fn_27_2DA870(object + 0xF4D),
        MODULE(soKineticModule, fn_27_2DA87C, 0xF50),
        static_cast<soEventManageModule*>(fn_27_2ED368(object)),
        fn_27_2DA2B4(object + 0x1060),
        MODULE(soEffectModule, fn_27_2DA888, 0x1064),
        fn_27_2DA2C0(object + 0x11F4),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x11F5),
        fn_27_2DA2D8(object + 0x11F6),
        fn_27_2DA2E4(object + 0x11F7),
        fn_27_2F8E64(object + 0x11F8),
        fn_27_2DA2FC(object + 0x1244),
        MODULE(soShadowModule, fn_27_2DA308, 0x1245),
        MODULE(soItemManageModule, fn_27_2DA314, 0x1246),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x1247),
        fn_27_2DA32C(object + 0x1248),
        fn_27_2DA338(object + 0x1249),
        MODULE(soSlowModule, fn_27_2DA890, 0x124C),
        fn_27_2DA894(object + 0x1264),
        fn_27_2DA898(object + 0x558),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x570),
        fn_27_2F1A54(object + 0x12A4));

    fn_27_2DA8A4(object + 0x558, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x570, accesser);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x580, buildData->slot0(),
                 buildData->slot1(),
                 static_cast<unsigned char>(resourceGroup), accesser);

    fn_27_1E10E0(object + 0x5B0, accesser, buildData->slot18(),
                 buildData->slot24(), fn_27_2815A0());
    fn_27_2F8E6C(object + 0x790, accesser, buildData->slot4());
    fn_27_2DAC38(object + 0x954, accesser, fn_27_2815A0());
    fn_27_2F4FCC(object + 0xA08, accesser, buildData->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2E2190(object + 0xA0C, accesser,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0xA48, buildData->slot3(), accesser);
    fn_27_2F4FD0(object + 0xAAC, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0xAAD, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0xAAE, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0xAAF, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0xAB0, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0xAB1, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0xAB2, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA36C(object + 0xAB3, accesser, fn_27_2815A0());
    fn_27_2DA370(object + 0xAB4, accesser);
    fn_27_2DA374(object + 0xAB5, accesser);
    fn_27_2E21CC(object + 0xAB8, accesser);
    fn_27_2DA37C(object + 0xADC, accesser);
    fn_27_1E15A4(object + 0xAE0, accesser, buildData->slot5());
    fn_27_2DB024(object + 0xAEC, accesser,
                 buildData->slot31(), fn_27_2815A0());
    fn_27_1E1648(object + 0xB54, accesser);
    fn_27_2E21FC(object + 0xCB8, accesser, buildData->slot6());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0xCCC, accesser,
                 static_cast<short>(controllerTaskId));
    fn_27_2DA388(object + 0xCCD, accesser, buildData->slot21(),
                 buildData->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0xCD0, accesser, buildData->slot19());

    int animCmdTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0xD04, static_cast<short>(animCmdTaskId));
    fn_27_2F9048(object + 0xDA8, accesser, buildData->slot7(),
                 buildData->slot26());
    fn_27_2DB554(object + 0xF4C);
    fn_27_2DB558(object + 0xF4D);
    fn_27_2DB55C(object + 0xF50, accesser);
    fn_27_1E1774(object + 0x1004);
    fn_27_2DA38C(object + 0x1060, accesser);
    fn_27_2DB778(object + 0x1064, accesser, buildData->slot9(),
                 buildData->slot10(), buildData->slot11(),
                 buildData->slot12(), fn_27_2815A0());
    fn_27_2DA390(object + 0x11F4, accesser);

    int areaHeap = fn_27_2815A0();
    int areaCategory = buildData->slot20();
    fn_27_2DA394(object + 0x11F5, accesser,
                 static_cast<unsigned char>(areaCategory), areaHeap);
    fn_27_2DA398(object + 0x11F6, accesser, buildData->slot13(),
                 buildData->slot14());
    fn_27_2DA39C(object + 0x11F7, accesser, buildData->slot15());
    fn_27_1E1A6C(object + 0x11F8, accesser, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x1244, accesser);
    fn_27_2DA3A8(object + 0x1245, accesser);
    fn_27_2DA3AC(object + 0x1246, accesser, buildData->slot23());
    fn_27_2DA3B0(object + 0x1247, accesser);
    fn_27_2DA3B4(object + 0x1248, accesser, buildData->slot25());
    fn_27_2DA3B8(object + 0x1249, accesser);
    fn_27_2DBB0C(object + 0x124C, accesser);
    fn_27_2DBB3C(object + 0x1264, accesser);
    fn_27_2F1A60(object + 0x12A4, accesser);
    fn_27_2DA3BC(object + 0x12A5, accesser, fn_27_2815A0());

    if (!fn_27_2DBBA0(object + 0x1004)->isNull()) {
        ModuleNullableInterface* listener = fn_27_2DBBA0(object + 0x1004);
        fn_27_2DA3C0(fn_27_2F82EC(self))->add(1, listener);
    }

    return self;
}
