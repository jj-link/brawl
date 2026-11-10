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
#define GET(name) void* name(void*)
GET(fn_27_2F1A54);
GET(fn_27_2DA89C);
GET(fn_27_2DA898);
GET(fn_27_3203B0);
GET(fn_27_2DA890);
GET(fn_27_2DA338);
GET(fn_27_2DA32C);
GET(fn_27_2F563C);
GET(fn_27_2DA314);
GET(fn_27_30204C);
GET(fn_27_2DA2FC);
GET(fn_27_2DA2F0);
GET(fn_27_2DA2E4);
GET(fn_27_2DA2D8);
GET(fn_27_2DA2CC);
GET(fn_27_2DA2C0);
GET(fn_27_36B408);
GET(fn_27_2DA2B4);
GET(fn_27_392664);
GET(fn_27_2F3434);
GET(fn_27_2DA870);
GET(fn_27_2DA864);
GET(fn_27_39265C);
GET(fn_27_2DA858);
GET(fn_27_2DA2A8);
GET(fn_27_2DA854);
GET(fn_27_38B674);
GET(fn_27_2DA290);
GET(fn_27_302038);
GET(fn_27_38B66C);
GET(fn_27_2DA844);
GET(fn_27_2DA83C);
GET(fn_27_2DA278);
GET(fn_27_2DA26C);
GET(fn_27_2DA260);
GET(fn_27_2DA254);
GET(fn_27_2DA248);
GET(fn_27_2DA23C);
GET(fn_27_2DA230);
GET(fn_27_2DA224);
GET(fn_27_2DA218);
GET(fn_27_2DA20C);
GET(fn_27_2DA200);
GET(fn_27_392654);
GET(fn_27_2DA82C);
GET(fn_27_2E1E40);
GET(fn_27_2DA824);
GET(fn_27_2DA81C);
GET(fn_27_39264C);
GET(fn_27_392644);
GET(fn_27_2DA804);
#undef GET

void fn_27_2DA1F0(void*);
void fn_27_392418(void*);
void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_39266C(void*, void*, float, int, int);
void fn_27_392758(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_1E38AC(void*, void*, int);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_1E1524(void*, int, void*);
void fn_27_3929FC(void*, void*, int, unsigned char, int);
void fn_27_2DA354(void*, void*, int, unsigned char, int);
void fn_27_2DA358(void*, void*, int, unsigned char);
void fn_27_2DA35C(void*, void*, int, unsigned char);
void fn_27_2DA360(void*, void*, int, unsigned char);
void fn_27_2DA364(void*, void*, int, unsigned char);
void fn_27_2DA368(void*, void*, int, unsigned char);
void fn_27_2DA36C(void*, void*, int);
void fn_27_2DA370(void*, void*);
void fn_27_2DA374(void*, void*);
void fn_27_2DA378(void*, void*);
void fn_27_2DA37C(void*, void*);
void fn_27_1E15A4(void*, void*, int);
void fn_27_2DB024(void*, void*, int, int);
void fn_27_38BA1C(void*, void*);
void fn_27_3022F4(void*, void*, int);
void fn_27_2DA384(void*, void*, short);
void fn_27_37BFD0(void*, void*, int, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_1E16CC(void*, short);
void fn_27_392C08(void*, void*, int, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_2F3440(void*, void*);
void fn_27_392E48(void*);
void fn_27_2DA38C(void*, void*);
void fn_27_36B838(void*, void*, int, int, int, int, int);
void fn_27_2DA390(void*, void*);
void fn_27_2DA394(void*, void*, unsigned char, int);
void fn_27_2DA398(void*, void*, int, int);
void fn_27_2DA39C(void*, void*, int);
void fn_27_2DA3A0(void*, void*, int);
void fn_27_2DA3A4(void*, void*);
void fn_27_3026DC(void*, void*);
void fn_27_2DA3AC(void*, void*, int);
void fn_27_2F5D2C(void*, void*);
void fn_27_2DA3B4(void*, void*, int);
void fn_27_2DA3B8(void*, void*);
void fn_27_2DBB0C(void*, void*);
void fn_27_3203BC(void*, void*);
void fn_27_2F1A60(void*, void*);
void fn_27_2DA3BC(void*, void*, int);

int fn_27_2815A0();
int fn_27_2815F4(StageObject*);
int fn_27_2815FC(StageObject*);
unsigned char* fn_27_2DA348(void*);
ModuleNullableInterface* fn_27_392ED4(void*);
void* fn_27_3918B0(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define ACCESSER (object + 0x490)

extern "C" void* fn_27_3918B8(
    void* self, StageObject* stageObject, Object_vptr_0* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_392418(self);

    new (ACCESSER) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x598),
        MODULE(soModelModule, fn_27_392644, 0x5C8),
        MODULE(soMotionModule, fn_27_39264C, 0x774),
        MODULE(soPostureModule, fn_27_2DA81C, 0x98C),
        MODULE(soGroundModule, fn_27_2DA824, 0xA40),
        MODULE(soSituationModule, fn_27_2E1E40, 0xAE8),
        fn_27_2DA82C(object + 0xB24),
        MODULE(soCollisionAttackModule, fn_27_392654, 0xB88),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0x137C),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0x137D),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0x137E),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0x137F),
        fn_27_2DA230(object + 0x1380),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0x1381),
        MODULE(soDamageModule, fn_27_2DA248, 0x1382),
        fn_27_2DA254(object + 0x1383),
        fn_27_2DA260(object + 0x1384),
        MODULE(soStopModule, fn_27_2DA26C, 0x1385),
        fn_27_2DA278(object + 0x1386),
        fn_27_2DA83C(object + 0x1388),
        MODULE(soSoundModule, fn_27_2DA844, 0x1394),
        MODULE(soLinkModule, fn_27_38B66C, 0x13FC),
        MODULE(soVisibilityModule, fn_27_302038, 0x1594),
        MODULE(soControllerModule, fn_27_2DA290, 0x15C4),
        MODULE(soCameraModule, fn_27_38B674, 0x15C8),
        MODULE(soWorkManageModule, fn_27_2DA854, 0x163C),
        fn_27_2DA2A8(object + 0x1BC2),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0x1670),
        MODULE(soStatusModule, fn_27_39265C, 0x1714),
        fn_27_2DA864(object + 0x1818),
        fn_27_2DA870(object + 0x1819),
        MODULE(soKineticModule, fn_27_2F3434, 0x181A),
        MODULE(soEventManageModule, fn_27_392664, 0),
        fn_27_2DA2B4(object + 0x18AC),
        MODULE(soEffectModule, fn_27_36B408, 0x18B0),
        fn_27_2DA2C0(object + 0x19FC),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x19FD),
        fn_27_2DA2D8(object + 0x19FE),
        fn_27_2DA2E4(object + 0x19FF),
        fn_27_2DA2F0(object + 0x1A00),
        fn_27_2DA2FC(object + 0x1A01),
        MODULE(soShadowModule, fn_27_30204C, 0x1A04),
        MODULE(soItemManageModule, fn_27_2DA314, 0x1A4C),
        MODULE(soColorBlendModule, fn_27_2F563C, 0x1A50),
        fn_27_2DA32C(object + 0x1BA4),
        fn_27_2DA338(object + 0x1BA5),
        MODULE(soSlowModule, fn_27_2DA890, 0x1BA8),
        fn_27_3203B0(object + 0x1BC0),
        fn_27_2DA898(object + 0x570),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x588),
        fn_27_2F1A54(object + 0x1BC1));

    fn_27_2DA8A4(object + 0x570, buildData->slot27(),
                 buildData->slot28(), buildData->slot29(),
                 buildData->slot30());
    fn_27_2DA8D4(object + 0x588, ACCESSER);

    int resourceGroup = buildData->slot2();
    fn_27_1E107C(object + 0x598, buildData->slot0(),
                 buildData->slot1(),
                 static_cast<unsigned char>(resourceGroup), ACCESSER);

    fn_27_39266C(object + 0x5C8, ACCESSER,
                 buildData->slot18(), buildData->slot24(),
                 fn_27_2815A0());
    fn_27_392758(object + 0x774, ACCESSER, buildData->slot4());
    fn_27_2DAC38(object + 0x98C, ACCESSER, fn_27_2815A0());
    fn_27_1E38AC(object + 0xA40, ACCESSER, buildData->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(ACCESSER) + 8)->slot7();
    fn_27_2E2190(object + 0xAE8, ACCESSER,
                 static_cast<short>(taskId), situationHeap);

    fn_27_1E1524(object + 0xB24, buildData->slot3(), ACCESSER);
    fn_27_3929FC(object + 0xB88, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0x137C, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0x137D, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0x137E, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0x137F, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0x1380, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0x1381, ACCESSER,
                 fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA36C(object + 0x1382, ACCESSER, fn_27_2815A0());
    fn_27_2DA370(object + 0x1383, ACCESSER);
    fn_27_2DA374(object + 0x1384, ACCESSER);
    fn_27_2DA378(object + 0x1385, ACCESSER);
    fn_27_2DA37C(object + 0x1386, ACCESSER);
    fn_27_1E15A4(object + 0x1388, ACCESSER, buildData->slot5());
    fn_27_2DB024(object + 0x1394, ACCESSER,
                 buildData->slot31(), fn_27_2815A0());
    fn_27_38BA1C(object + 0x13FC, ACCESSER);
    fn_27_3022F4(object + 0x1594, ACCESSER, buildData->slot6());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(ACCESSER) + 8)->slot7();
    fn_27_2DA384(object + 0x15C4, ACCESSER,
                 static_cast<short>(controllerTaskId));
    fn_27_37BFD0(object + 0x15C8, ACCESSER,
                 buildData->slot21(), buildData->slot22(),
                 fn_27_2815A0());
    fn_27_2DB098(object + 0x163C, ACCESSER, buildData->slot19());

    int animTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(ACCESSER) + 8)->slot7();
    fn_27_1E16CC(object + 0x1670, static_cast<short>(animTaskId));

    fn_27_392C08(object + 0x1714, ACCESSER,
                 buildData->slot7(), buildData->slot26());
    fn_27_2DB554(object + 0x1818);
    fn_27_2DB558(object + 0x1819);
    fn_27_2F3440(object + 0x181A, ACCESSER);
    fn_27_392E48(object + 0x181C);
    fn_27_2DA38C(object + 0x18AC, ACCESSER);
    fn_27_36B838(object + 0x18B0, ACCESSER,
                 buildData->slot9(), buildData->slot10(),
                 buildData->slot11(), buildData->slot12(),
                 fn_27_2815A0());
    fn_27_2DA390(object + 0x19FC, ACCESSER);

    int areaHeap = fn_27_2815A0();
    int areaCategory = buildData->slot20();
    fn_27_2DA394(object + 0x19FD, ACCESSER,
                 static_cast<unsigned char>(areaCategory), areaHeap);
    fn_27_2DA398(object + 0x19FE, ACCESSER,
                 buildData->slot13(), buildData->slot14());
    fn_27_2DA39C(object + 0x19FF, ACCESSER, buildData->slot15());
    fn_27_2DA3A0(object + 0x1A00, ACCESSER, buildData->slot16());
    buildData->slot32();
    fn_27_2DA3A4(object + 0x1A01, ACCESSER);
    fn_27_3026DC(object + 0x1A04, ACCESSER);
    fn_27_2DA3AC(object + 0x1A4C, ACCESSER, buildData->slot23());
    fn_27_2F5D2C(object + 0x1A50, ACCESSER);
    fn_27_2DA3B4(object + 0x1BA4, ACCESSER, buildData->slot25());
    fn_27_2DA3B8(object + 0x1BA5, ACCESSER);
    fn_27_2DBB0C(object + 0x1BA8, ACCESSER);
    fn_27_3203BC(object + 0x1BC0, ACCESSER);
    fn_27_2F1A60(object + 0x1BC1, ACCESSER);
    fn_27_2DA3BC(object + 0x1BC2, ACCESSER, fn_27_2815A0());

    if (!fn_27_392ED4(object + 0x181C)->isNull()) {
        ModuleNullableInterface* listener = fn_27_392ED4(object + 0x181C);
        fn_27_2DA3C0(fn_27_3918B0(self))->add(1, listener);
    }

    return self;
}
