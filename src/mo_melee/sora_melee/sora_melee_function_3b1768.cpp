#include <new>
#include <so/so_module_accesser.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class Object_vptr_0 {
public:
    virtual int slot0(); virtual int slot1(); virtual int slot2(); virtual int slot3();
    virtual int slot4(); virtual int slot5(); virtual int slot6(); virtual int slot7();
    virtual int slot8(); virtual int slot9(); virtual int slot10(); virtual int slot11();
    virtual int slot12(); virtual int slot13(); virtual int slot14(); virtual int slot15();
    virtual int slot16(); virtual int slot17(); virtual float slot18(); virtual int slot19();
    virtual int slot20(); virtual int slot21(); virtual int slot22(); virtual int slot23();
    virtual int slot24(); virtual int slot25(); virtual int slot26(); virtual int slot27();
    virtual int slot28(); virtual int slot29(); virtual int slot30(); virtual int slot31();
    virtual float slot32();
};

class ModuleTaskInterface {
public:
    virtual int slot0(); virtual int slot1(); virtual int slot2(); virtual int slot3();
    virtual int slot4(); virtual int slot5(); virtual int slot6(); virtual int slot7();
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
void* fn_27_2DA200(void*);
void* fn_27_2DA20C(void*);
void* fn_27_2DA218(void*);
void* fn_27_2DA224(void*);
void* fn_27_2DA230(void*);
void* fn_27_2DA23C(void*);
void* fn_27_2DA248(void*);
void* fn_27_2DA254(void*);
void* fn_27_2DA260(void*);
void* fn_27_2DA278(void*);
void* fn_27_2DA29C(void*);
void* fn_27_2DA2A8(void*);
void* fn_27_2DA2B4(void*);
void* fn_27_2DA2C0(void*);
void* fn_27_2DA2CC(void*);
void* fn_27_2DA2D8(void*);
void* fn_27_2DA2E4(void*);
void* fn_27_2DA2F0(void*);
void* fn_27_2DA2FC(void*);
void* fn_27_2DA308(void*);
void* fn_27_2DA314(void*);
void* fn_27_2DA320(void*);
void* fn_27_2DA32C(void*);
void* fn_27_2DA338(void*);
void* fn_27_2DA348(void*);
void** fn_27_2DBBA0(void*);
void* fn_27_2DA3C0(void*);
void* fn_27_2DA804(void*);
void* fn_27_2DA80C(void*);
void* fn_27_2DA81C(void*);
void* fn_27_2DA82C(void*);
void* fn_27_2DA834(void*);
void* fn_27_2DA83C(void*);
void* fn_27_2DA844(void*);
void* fn_27_2DA84C(void*);
void* fn_27_2DA854(void*);
void* fn_27_2DA858(void*);
void* fn_27_2DA85C(void*);
void* fn_27_2DA864(void*);
void* fn_27_2DA870(void*);
void* fn_27_2DA87C(void*);
void* fn_27_2DA880(void*);
void* fn_27_2DA888(void*);
void* fn_27_2DA890(void*);
void* fn_27_2DA894(void*);
void* fn_27_2DA898(void*);
void* fn_27_2DA89C(void*);
void* fn_27_2E1E40(void*);
void* fn_27_2E1E44(void*);
void* fn_27_2E1E48(void*);
void* fn_27_2E1E4C(void*);
void* fn_27_2F1A54(void*);
void* fn_27_2F4FB4(void*);
void* fn_27_32B7E0(void*);
void* fn_27_3B22C8(void*);
int fn_27_2815A0();
int fn_27_2815F4(StageObject*);
int fn_27_2815FC(StageObject*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E10E0(void*, void*, float, int, int);
void fn_27_1E1524(void*, int, void*);
void fn_27_1E15A4(void*, void*, int);
void fn_27_1E1648(void*, void*);
void fn_27_1E16CC(void*, short);
void fn_27_1E1774(void*);
void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_2DA354(void*, void*, int, unsigned char, int);
void fn_27_2DA358(void*, void*, int, unsigned char);
void fn_27_2DA35C(void*, void*, int, unsigned char);
void fn_27_2DA360(void*, void*, int, unsigned char);
void fn_27_2DA364(void*, void*, int, unsigned char);
void fn_27_2DA368(void*, void*, int, unsigned char);
void fn_27_2DA36C(void*, void*, int);
void fn_27_2DA370(void*, void*);
void fn_27_2DA374(void*, void*);
void fn_27_2DA37C(void*, void*);
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
void fn_27_2DAC38(void*, void*, int);
void fn_27_2DAD80(void*, void*, int, unsigned char, int);
void fn_27_2DB024(void*, void*, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_2DB0C8(void*, void*, int, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_2DB55C(void*, void*);
void fn_27_2DB778(void*, void*, int, int, int, int, int);
void fn_27_2DBB0C(void*, void*);
void fn_27_2DBB3C(void*, void*);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_2E21CC(void*, void*);
void fn_27_2E21FC(void*, void*, int);
void fn_27_2F1A60(void);
void fn_27_2F4FCC(void*, void*, int);
void fn_27_314FE8(void*, void*, short);
void* fn_27_3B1760(void*);
void fn_27_3B22D0(void*, void*, int);
}

#define MODULE(type, getter, offset) static_cast<type*>(getter(object + offset))
#define ACCESS (object + 0x7F8)

extern "C" void* fn_27_3B1768(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);
    unsigned char situation;

    fn_27_2DA1F0(self);
    fn_27_2DA3CC(self);

    new (object + 0x7F8) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x900),
        MODULE(soModelModule, fn_27_2DA80C, 0x930),
        static_cast<soMotionModule*>(fn_27_3B22C8(object + 0xB10)),
        MODULE(soPostureModule, fn_27_2DA81C, 0xD84),
        MODULE(soGroundModule, fn_27_2F4FB4, 0xE38),
        MODULE(soSituationModule, fn_27_2E1E40, 0xE3C),
        fn_27_2DA82C(object + 0xE78),
        MODULE(soCollisionAttackModule, fn_27_2DA834, 0xEDC),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0x10A0),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0x10A1),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0x10A2),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0x10A3),
        fn_27_2DA230(object + 0x10A4),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0x10A5),
        MODULE(soDamageModule, fn_27_2DA248, 0x10A6),
        fn_27_2DA254(object + 0x10A7),
        fn_27_2DA260(object + 0x10A8),
        MODULE(soStopModule, fn_27_2E1E44, 0x10AC),
        fn_27_2DA278(object + 0x10D0),
        fn_27_2DA83C(object + 0x10D4),
        MODULE(soSoundModule, fn_27_2DA844, 0x10E0),
        MODULE(soLinkModule, fn_27_2DA84C, 0x1148),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0x12AC),
        MODULE(soControllerModule, fn_27_32B7E0, 0x12C0),
        MODULE(soCameraModule, fn_27_2DA29C, 0x12E0),
        MODULE(soWorkManageModule, fn_27_2DA854, 0x12E4),
        fn_27_2DA2A8(object + 0x1885),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0x1318),
        MODULE(soStatusModule, fn_27_2DA85C, 0x13BC),
        fn_27_2DA864(object + 0x1578),
        fn_27_2DA870(object + 0x1579),
        MODULE(soKineticModule, fn_27_2DA87C, 0x157C),
        static_cast<soEventManageModule*>(fn_27_2DA880(object)),
        fn_27_2DA2B4(object + 0x168C),
        MODULE(soEffectModule, fn_27_2DA888, 0x1690),
        fn_27_2DA2C0(object + 0x1820),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x1821),
        fn_27_2DA2D8(object + 0x1822),
        fn_27_2DA2E4(object + 0x1823),
        fn_27_2DA2F0(object + 0x1824),
        fn_27_2DA2FC(object + 0x1825),
        MODULE(soShadowModule, fn_27_2DA308, 0x1826),
        MODULE(soItemManageModule, fn_27_2DA314, 0x1827),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x1828),
        fn_27_2DA32C(object + 0x1829),
        fn_27_2DA338(object + 0x182A),
        MODULE(soSlowModule, fn_27_2DA890, 0x182C),
        fn_27_2DA894(object + 0x1844),
        fn_27_2DA898(object + 0x8D8),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x8F0),
        fn_27_2F1A54(object + 0x1884));

    fn_27_2DA8A4(object + 0x8D8, buildData->slot27(), buildData->slot28(),
                 buildData->slot29(), buildData->slot30());
    fn_27_2DA8D4(object + 0x8F0, ACCESS);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x900, buildData->slot0(), buildData->slot1(),
                 static_cast<unsigned char>(resourceGroup), ACCESS);
    fn_27_1E10E0(object + 0x930, ACCESS, buildData->slot18(),
                 buildData->slot24(), fn_27_2815A0());
    fn_27_3B22D0(object + 0xB10, ACCESS, buildData->slot4());
    fn_27_2DAC38(object + 0xD84, ACCESS, fn_27_2815A0());

    fn_27_2F4FCC(object + 0xE38, ACCESS, buildData->slot8());
    int situationHeap = fn_27_2815A0();
    int situationTaskId =
        reinterpret_cast<ModuleTaskInterface*>(
            static_cast<unsigned char*>(fn_27_2DA348(ACCESS)) + 8)->slot7();
    fn_27_2E2190(object + 0xE3C, ACCESS, static_cast<short>(situationTaskId),
                 situationHeap);
    fn_27_1E1524(object + 0xE78, buildData->slot3(), ACCESS);
    int situationHeap2 = fn_27_2815A0();
    situation = fn_27_2815FC(stageObject);
    int situationKind = fn_27_2815F4(stageObject);
    fn_27_2DAD80(object + 0xEDC, ACCESS, situationKind, situation,
                 situationHeap2);

    fn_27_2DA354(object + 0x10A0, ACCESS, fn_27_2815F4(stageObject),
                 fn_27_2815FC(stageObject), fn_27_2815A0());
    fn_27_2DA358(object + 0x10A1, ACCESS, fn_27_2815F4(stageObject),
                 fn_27_2815FC(stageObject));
    fn_27_2DA35C(object + 0x10A2, ACCESS, fn_27_2815F4(stageObject),
                 fn_27_2815FC(stageObject));
    fn_27_2DA360(object + 0x10A3, ACCESS, fn_27_2815F4(stageObject),
                 fn_27_2815FC(stageObject));
    fn_27_2DA364(object + 0x10A4, ACCESS, fn_27_2815F4(stageObject),
                 fn_27_2815FC(stageObject));
    fn_27_2DA368(object + 0x10A5, ACCESS, fn_27_2815F4(stageObject),
                 fn_27_2815FC(stageObject));
    fn_27_2DA36C(object + 0x10A6, ACCESS, fn_27_2815A0());
    fn_27_2DA370(object + 0x10A7, ACCESS);
    fn_27_2DA374(object + 0x10A8, ACCESS);
    fn_27_2E21CC(object + 0x10AC, ACCESS);
    fn_27_2DA37C(object + 0x10D0, ACCESS);
    fn_27_1E15A4(object + 0x10D4, ACCESS, buildData->slot5());
    fn_27_2DB024(object + 0x10E0, ACCESS, buildData->slot31(),
                 fn_27_2815A0());
    fn_27_1E1648(object + 0x1148, ACCESS);
    fn_27_2E21FC(object + 0x12AC, ACCESS, buildData->slot6());

    int workTaskId =
        reinterpret_cast<ModuleTaskInterface*>(
            static_cast<unsigned char*>(fn_27_2DA348(ACCESS)) + 8)->slot7();
    fn_27_314FE8(object + 0x12C0, ACCESS, static_cast<short>(workTaskId));

    int slot22Val;
    int heap3 = fn_27_2815A0();
    slot22Val = buildData->slot22();
    int slot21Val = buildData->slot21();
    fn_27_2DA388(object + 0x12E0, ACCESS, slot21Val, slot22Val, heap3);
    fn_27_2DB098(object + 0x12E4, ACCESS, buildData->slot19());

    int workTaskId2 =
        reinterpret_cast<ModuleTaskInterface*>(
            static_cast<unsigned char*>(fn_27_2DA348(ACCESS)) + 8)->slot7();
    fn_27_1E16CC(object + 0x1318, static_cast<short>(workTaskId2));

    int s26 = buildData->slot26();
    int s7 = buildData->slot7();
    fn_27_2DB0C8(object + 0x13BC, ACCESS, s7, s26);

    fn_27_2DB554(object + 0x1578);
    fn_27_2DB558(object + 0x1579);
    fn_27_2DB55C(object + 0x157C, ACCESS);
    fn_27_1E1774(object + 0x1630);
    fn_27_2DA38C(object + 0x168C, ACCESS);

    int s10;
    int s11;
    int s12;
    int heap4;
    int s9;
    heap4 = fn_27_2815A0();
    s12 = buildData->slot12();
    s11 = buildData->slot11();
    s10 = buildData->slot10();
    s9 = buildData->slot9();
    fn_27_2DB778(object + 0x1690, ACCESS, s9, s10, s11, s12, heap4);

    fn_27_2DA390(object + 0x1820, ACCESS);

    int heap5 = fn_27_2815A0();
    int s20 = buildData->slot20();
    fn_27_2DA394(object + 0x1821, ACCESS, static_cast<unsigned char>(s20), heap5);

    int s14b = buildData->slot14();
    fn_27_2DA398(object + 0x1822, ACCESS, buildData->slot13(), s14b);
    fn_27_2DA39C(object + 0x1823, ACCESS, buildData->slot15());
    fn_27_2DA3A0(object + 0x1824, ACCESS, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x1825, ACCESS);
    fn_27_2DA3A8(object + 0x1826, ACCESS);
    fn_27_2DA3AC(object + 0x1827, ACCESS, buildData->slot23());
    fn_27_2DA3B0(object + 0x1828, ACCESS);
    fn_27_2DA3B4(object + 0x1829, ACCESS, buildData->slot25());
    fn_27_2DA3B8(object + 0x182A, ACCESS);
    fn_27_2DBB0C(object + 0x182C, ACCESS);
    fn_27_2DBB3C(object + 0x1844, ACCESS);
    reinterpret_cast<void (*)(void*, void*)>(fn_27_2F1A60)(
        object + 0x1884, ACCESS);
    fn_27_2DA3BC(object + 0x1885, ACCESS, fn_27_2815A0());

    if (!reinterpret_cast<ModuleNullableInterface*>(
             fn_27_2DBBA0(object + 0x1630))->isNull()) {
        reinterpret_cast<ModuleRegistryInterface*>(
            fn_27_2DA3C0(fn_27_3B1760(self)))
            ->add(1, reinterpret_cast<ModuleNullableInterface*>(
                         fn_27_2DBBA0(object + 0x1630)));
    }

    return self;
}
