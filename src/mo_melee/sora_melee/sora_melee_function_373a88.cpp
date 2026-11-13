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
void fn_27_36F9DC(void*);

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
DECL_GET(fn_27_2DA284);
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
DECL_GET(fn_27_2DA84C);
DECL_GET(fn_27_2DA854);
DECL_GET(fn_27_2DA858);
DECL_GET(fn_27_2DA864);
DECL_GET(fn_27_2DA870);
DECL_GET(fn_27_2DA890);
DECL_GET(fn_27_2DA894);
DECL_GET(fn_27_2DA898);
DECL_GET(fn_27_2DA89C);
DECL_GET(fn_27_2DA8A0);
DECL_GET(fn_27_2E1E44);
DECL_GET(fn_27_2E6C48);
DECL_GET(fn_27_2FD670);
DECL_GET(fn_27_3055C4);
DECL_GET(fn_27_36B408);
DECL_GET(fn_27_3700F0);
DECL_GET(fn_27_370100);
DECL_GET(fn_27_3745E8);
DECL_GET(fn_27_2DA1F4);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_2E6C74(void*, void*, int, int);
void fn_27_370108(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_1E38AC(void*, void*, int);
void fn_27_2DA344(void*, void*, short, int);
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
void fn_27_3055D0(void*, void*, int, int);
void fn_27_1E1648(void*, void*);
void fn_27_2DA380(void*, void*, int);
void fn_27_2DA384(void*, void*, short);
void fn_27_2DA388(void*, void*, int, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_1E16CC(void*, short);
void fn_27_3745F0(void*, void*, int, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_1E3968(void*, void*);
void fn_27_302650(void*);
void fn_27_2DA38C(void*, void*);
void fn_27_36B838(void*, void*, int, int, int, int, int);
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
ModuleNullableInterface* fn_27_302718(void*);
void* fn_27_373A80(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x428)

extern "C" void* fn_27_373A88(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_36F9DC(self);

    new (object + 0x428) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x530),
        MODULE(soModelModule, fn_27_2E6C48, 0x560),
        MODULE(soMotionModule, fn_27_3700F0, 0x670),
        MODULE(soPostureModule, fn_27_2DA81C, 0x7FC),
        MODULE(soGroundModule, fn_27_2DA824, 0x8B0),
        MODULE(soSituationModule, fn_27_2DA1F4, 0x958),
        fn_27_2DA82C(object + 0x95C),
        MODULE(soCollisionAttackModule, fn_27_2DA834, 0x9C0),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0xB84),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0xB85),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0xB86),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0xB87),
        fn_27_2DA230(object + 0xB88),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0xB89),
        MODULE(soDamageModule, fn_27_2DA248, 0xB8A),
        fn_27_2DA254(object + 0xB8B),
        fn_27_2DA260(object + 0xB8C),
        MODULE(soStopModule, fn_27_2E1E44, 0xB90),
        fn_27_2DA278(object + 0xBB4),
        fn_27_2DA83C(object + 0xBB8),
        MODULE(soSoundModule, fn_27_3055C4, 0xBC4),
        MODULE(soLinkModule, fn_27_2DA84C, 0xBC8),
        MODULE(soVisibilityModule, fn_27_2DA284, 0xD2C),
        MODULE(soControllerModule, fn_27_2DA290, 0xD2D),
        MODULE(soCameraModule, fn_27_2DA29C, 0xD2E),
        MODULE(soWorkManageModule, fn_27_2DA854, 0xD30),
        fn_27_2DA2A8(object + 0x11E4),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0xD64),
        MODULE(soStatusModule, fn_27_3745E8, 0xE08),
        fn_27_2DA864(object + 0xF44),
        fn_27_2DA870(object + 0xF45),
        MODULE(soKineticModule, fn_27_2FD670, 0xF48),
        static_cast<soEventManageModule*>(fn_27_370100(self)),
        fn_27_2DA2B4(object + 0x1018),
        MODULE(soEffectModule, fn_27_36B408, 0x101C),
        fn_27_2DA2C0(object + 0x1168),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x1169),
        fn_27_2DA2D8(object + 0x116A),
        fn_27_2DA2E4(object + 0x116B),
        fn_27_2DA2F0(object + 0x116C),
        fn_27_2DA2FC(object + 0x116D),
        MODULE(soShadowModule, fn_27_2DA308, 0x116E),
        MODULE(soItemManageModule, fn_27_2DA314, 0x116F),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x1170),
        fn_27_2DA32C(object + 0x1171),
        fn_27_2DA338(object + 0x1172),
        MODULE(soSlowModule, fn_27_2DA890, 0x1174),
        fn_27_2DA894(object + 0x118C),
        fn_27_2DA898(object + 0x508),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x520),
        fn_27_2DA8A0(object + 0x11CC));

    fn_27_2DA8A4(object + 0x508, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x520, accesser);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x530, buildData->slot0(),
                 buildData->slot1(),
                 static_cast<unsigned char>(resourceGroup), accesser);
    int modelHeap;
    int modelCategory = (modelHeap = fn_27_2815A0(), buildData->slot24());
    buildData->slot18();
    fn_27_2E6C74(object + 0x560, accesser, modelCategory, modelHeap);
    fn_27_370108(object + 0x670, accesser, buildData->slot4());
    fn_27_2DAC38(object + 0x7FC, accesser, fn_27_2815A0());
    fn_27_1E38AC(object + 0x8B0, accesser, buildData->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA344(object + 0x958, accesser,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0x95C, buildData->slot3(), accesser);
    fn_27_2DAD80(object + 0x9C0, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0xB84, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0xB85, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0xB86, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0xB87, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0xB88, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0xB89, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA36C(object + 0xB8A, accesser, fn_27_2815A0());
    fn_27_2DA370(object + 0xB8B, accesser);
    fn_27_2DA374(object + 0xB8C, accesser);
    fn_27_2E21CC(object + 0xB90, accesser);
    fn_27_2DA37C(object + 0xBB4, accesser);
    fn_27_1E15A4(object + 0xBB8, accesser, buildData->slot5());
    fn_27_3055D0(object + 0xBC4, accesser, buildData->slot31(),
                 fn_27_2815A0());
    fn_27_1E1648(object + 0xBC8, accesser);
    fn_27_2DA380(object + 0xD2C, accesser, buildData->slot6());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0xD2D, accesser,
                 static_cast<short>(controllerTaskId));
    fn_27_2DA388(object + 0xD2E, accesser, buildData->slot21(),
                 buildData->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0xD30, accesser, buildData->slot19());

    int animCmdTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0xD64, static_cast<short>(animCmdTaskId));
    fn_27_3745F0(object + 0xE08, accesser, buildData->slot7(),
                 buildData->slot26());
    fn_27_2DB554(object + 0xF44);
    fn_27_2DB558(object + 0xF45);
    fn_27_1E3968(object + 0xF48, accesser);
    fn_27_302650(object + 0xFB4);
    fn_27_2DA38C(object + 0x1018, accesser);
    fn_27_36B838(object + 0x101C, accesser, buildData->slot9(),
                 buildData->slot10(), buildData->slot11(),
                 buildData->slot12(), fn_27_2815A0());
    fn_27_2DA390(object + 0x1168, accesser);

    int areaHeap = fn_27_2815A0();
    int areaCategory = buildData->slot20();
    fn_27_2DA394(object + 0x1169, accesser,
                 static_cast<unsigned char>(areaCategory), areaHeap);
    fn_27_2DA398(object + 0x116A, accesser, buildData->slot13(),
                 buildData->slot14());
    fn_27_2DA39C(object + 0x116B, accesser, buildData->slot15());
    fn_27_2DA3A0(object + 0x116C, accesser, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x116D, accesser);
    fn_27_2DA3A8(object + 0x116E, accesser);
    fn_27_2DA3AC(object + 0x116F, accesser, buildData->slot23());
    fn_27_2DA3B0(object + 0x1170, accesser);
    fn_27_2DA3B4(object + 0x1171, accesser, buildData->slot25());
    fn_27_2DA3B8(object + 0x1172, accesser);
    fn_27_2DBB0C(object + 0x1174, accesser);
    fn_27_2DBB3C(object + 0x118C, accesser);
    fn_27_2DBB70(object + 0x11CC, accesser);
    fn_27_2DA3BC(object + 0x11E4, accesser, fn_27_2815A0());

    if (!fn_27_302718(object + 0xFB4)->isNull()) {
        ModuleNullableInterface* listener = fn_27_302718(object + 0xFB4);
        fn_27_2DA3C0(fn_27_373A80(self))->add(1, listener);
    }

    return self;
}
