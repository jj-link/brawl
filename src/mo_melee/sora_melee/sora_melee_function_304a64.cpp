#include <new>
#include <so/so_module_accesser.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class soModuleAccesserBuildData {
public:
    virtual int fn_27_1DC6F4() const;
    virtual int fn_27_1DC700() const;
    virtual int fn_27_1DC70C() const;
    virtual int fn_27_1DC868() const;
    virtual int fn_27_1DC714() const;
    virtual int fn_27_1DC764() const;
    virtual int fn_27_1DC72C() const;
    virtual int fn_27_1DC720() const;
    virtual int fn_27_1DC774() const;
    virtual int getEffectNodeData() const;
    virtual int fn_27_1DC76C() const;
    virtual int fn_27_1DC788() const;
    virtual int getEffectScreenData() const;
    virtual int getTerritoryParam() const;
    virtual int getTerritoryRect() const;
    virtual int getTargetSearchParam() const;
    virtual int getIkData() const;
    virtual int getModelLayerType() const;
    virtual float getModelScale() const;
    virtual int fn_27_1DC738() const;
    virtual int fn_27_1DC740() const;
    virtual int fn_27_1DC748() const;
    virtual int fn_27_1DC75C() const;
    virtual int fn_27_1DC860() const;
    virtual int getModelExtendNodeTable() const;
    virtual int fn_27_1DC780() const;
    virtual int getPreCheckAnimCmdData() const;
    virtual int fn_27_1DC858() const;
    virtual int fn_27_1DC850() const;
    virtual int fn_27_1DC848() const;
    virtual int getHeapSlotNo() const;
    virtual int getSoundIdExchanger() const;
    virtual float getSlopeAngleLimit() const;
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
DECL_GET(fn_27_2E6C48);
DECL_GET(fn_27_2E6C50);
DECL_GET(fn_27_2ED368);
DECL_GET(fn_27_3055C4);
DECL_GET(fn_27_3055D4);
#undef DECL_GET

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_2E6C74(void*, void*, float, int, int);
void fn_27_2E6D5C(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_1E38AC(void*, void*, int);
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
void fn_27_3055D0(void*, void*, int, int);
void fn_27_1E1648(void*, void*);
void fn_27_2E21FC(void*, void*, int);
void fn_27_2DA384(void*, void*, short);
void fn_27_2DA388(void*, void*, int, int, int);
void fn_27_2DB098(void*, void*, int);
void fn_27_1E16CC(void*, short);
void fn_27_3055DC(void*, void*, int, int);
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
void* fn_27_304A5C(void*);
ModuleRegistryInterface* fn_27_2DA3C0(void*);
}

#define MODULE(type, function, offset) \
    static_cast<type*>(function(object + offset))
#define accesser (object + 0x478)

extern "C" void* fn_27_304A64(
    void* self, StageObject* stageObject, soModuleAccesserBuildData* buildData)
{
    unsigned char* object = static_cast<unsigned char*>(self);

    fn_27_2DA1F0(self);
    fn_27_2ECD14(self);

    new (object + 0x478) soModuleAccesser(
        stageObject,
        MODULE(soResourceModule, fn_27_2DA804, 0x580),
        MODULE(soModelModule, fn_27_2E6C48, 0x5B0),
        MODULE(soMotionModule, fn_27_2E6C50, 0x6C0),
        MODULE(soPostureModule, fn_27_2DA81C, 0x84C),
        MODULE(soGroundModule, fn_27_2DA824, 0x900),
        MODULE(soSituationModule, fn_27_2E1E40, 0x9A8),
        fn_27_2DA82C(object + 0x9E4),
        MODULE(soCollisionAttackModule, fn_27_2DA834, 0xA48),
        MODULE(soCollisionHitModule, fn_27_2DA200, 0xC0C),
        MODULE(soCollisionShieldModule, fn_27_2DA20C, 0xC0D),
        MODULE(soCollisionShieldModule, fn_27_2DA218, 0xC0E),
        MODULE(soCollisionShieldModule, fn_27_2DA224, 0xC0F),
        fn_27_2DA230(object + 0xC10),
        MODULE(soCollisionSearchModule, fn_27_2DA23C, 0xC11),
        MODULE(soDamageModule, fn_27_2DA248, 0xC12),
        fn_27_2DA254(object + 0xC13),
        fn_27_2DA260(object + 0xC14),
        MODULE(soStopModule, fn_27_2E1E44, 0xC18),
        fn_27_2DA278(object + 0xC3C),
        fn_27_2DA83C(object + 0xC40),
        MODULE(soSoundModule, fn_27_3055C4, 0xC4C),
        MODULE(soLinkModule, fn_27_2DA84C, 0xC50),
        MODULE(soVisibilityModule, fn_27_2E1E48, 0xDB4),
        MODULE(soControllerModule, fn_27_2DA290, 0xDC8),
        MODULE(soCameraModule, fn_27_2DA29C, 0xDC9),
        MODULE(soWorkManageModule, fn_27_2DA854, 0xDCC),
        fn_27_2DA2A8(object + 0x1338),
        MODULE(soAnimCmdModule, fn_27_2DA858, 0xE00),
        MODULE(soStatusModule, fn_27_3055D4, 0xEA4),
        fn_27_2DA864(object + 0x1014),
        fn_27_2DA870(object + 0x1015),
        MODULE(soKineticModule, fn_27_2DA87C, 0x1018),
        static_cast<soEventManageModule*>(fn_27_2ED368(object)),
        fn_27_2DA2B4(object + 0x1128),
        MODULE(soEffectModule, fn_27_2DA888, 0x112C),
        fn_27_2DA2C0(object + 0x12BC),
        MODULE(soAreaModule, fn_27_2DA2CC, 0x12BD),
        fn_27_2DA2D8(object + 0x12BE),
        fn_27_2DA2E4(object + 0x12BF),
        fn_27_2DA2F0(object + 0x12C0),
        fn_27_2DA2FC(object + 0x12C1),
        MODULE(soShadowModule, fn_27_2DA308, 0x12C2),
        MODULE(soItemManageModule, fn_27_2DA314, 0x12C3),
        MODULE(soColorBlendModule, fn_27_2DA320, 0x12C4),
        fn_27_2DA32C(object + 0x12C5),
        fn_27_2DA338(object + 0x12C6),
        MODULE(soSlowModule, fn_27_2DA890, 0x12C8),
        fn_27_2DA894(object + 0x12E0),
        fn_27_2DA898(object + 0x558),
        MODULE(soParamCustomizeModule, fn_27_2DA89C, 0x570),
        fn_27_2DA8A0(object + 0x1320));

    fn_27_2DA8A4(object + 0x558, buildData->fn_27_1DC858(),
                 buildData->fn_27_1DC850(), buildData->fn_27_1DC848(),
                 buildData->getHeapSlotNo());
    fn_27_2DA8D4(object + 0x570, accesser);

    int resourceGroup = buildData->fn_27_1DC70C();
    fn_27_1E107C(object + 0x580, buildData->fn_27_1DC6F4(),
                 buildData->fn_27_1DC700(),
                 static_cast<unsigned char>(resourceGroup), accesser);
    fn_27_2E6C74(object + 0x5B0, accesser, buildData->getModelScale(),
                 buildData->getModelExtendNodeTable(), fn_27_2815A0());
    fn_27_2E6D5C(object + 0x6C0, accesser, buildData->fn_27_1DC714());
    fn_27_2DAC38(object + 0x84C, accesser, fn_27_2815A0());
    fn_27_1E38AC(object + 0x900, accesser, buildData->fn_27_1DC774());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2E2190(object + 0x9A8, accesser,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0x9E4, buildData->fn_27_1DC868(), accesser);
    fn_27_2DAD80(object + 0xA48, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA354(object + 0xC0C, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)),
                 fn_27_2815A0());
    fn_27_2DA358(object + 0xC0D, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA35C(object + 0xC0E, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA360(object + 0xC0F, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA364(object + 0xC10, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA368(object + 0xC11, accesser, fn_27_2815F4(stageObject),
                 static_cast<unsigned char>(fn_27_2815FC(stageObject)));
    fn_27_2DA36C(object + 0xC12, accesser, fn_27_2815A0());
    fn_27_2DA370(object + 0xC13, accesser);
    fn_27_2DA374(object + 0xC14, accesser);
    fn_27_2E21CC(object + 0xC18, accesser);
    fn_27_2DA37C(object + 0xC3C, accesser);
    fn_27_1E15A4(object + 0xC40, accesser, buildData->fn_27_1DC764());
    fn_27_3055D0(object + 0xC4C, accesser,
                 buildData->getSoundIdExchanger(), fn_27_2815A0());
    fn_27_1E1648(object + 0xC50, accesser);
    fn_27_2E21FC(object + 0xDB4, accesser, buildData->fn_27_1DC72C());

    int controllerTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_2DA384(object + 0xDC8, accesser,
                 static_cast<short>(controllerTaskId));
    fn_27_2DA388(object + 0xDC9, accesser, buildData->fn_27_1DC748(),
                 buildData->fn_27_1DC75C(), fn_27_2815A0());
    fn_27_2DB098(object + 0xDCC, accesser, buildData->fn_27_1DC738());

    int animCmdTaskId = reinterpret_cast<ModuleTaskInterface*>(
        fn_27_2DA348(accesser) + 8)->slot7();
    fn_27_1E16CC(object + 0xE00, static_cast<short>(animCmdTaskId));
    fn_27_3055DC(object + 0xEA4, accesser, buildData->fn_27_1DC720(),
                 buildData->getPreCheckAnimCmdData());
    fn_27_2DB554(object + 0x1014);
    fn_27_2DB558(object + 0x1015);
    fn_27_2DB55C(object + 0x1018, accesser);
    fn_27_1E1774(object + 0x10CC);
    fn_27_2DA38C(object + 0x1128, accesser);
    fn_27_2DB778(object + 0x112C, accesser, buildData->getEffectNodeData(),
                 buildData->fn_27_1DC76C(), buildData->fn_27_1DC788(),
                 buildData->getEffectScreenData(), fn_27_2815A0());
    fn_27_2DA390(object + 0x12BC, accesser);

    int areaHeap = fn_27_2815A0();
    int areaCategory = buildData->fn_27_1DC740();
    fn_27_2DA394(object + 0x12BD, accesser,
                 static_cast<unsigned char>(areaCategory), areaHeap);
    fn_27_2DA398(object + 0x12BE, accesser, buildData->getTerritoryParam(),
                 buildData->getTerritoryRect());
    fn_27_2DA39C(object + 0x12BF, accesser, buildData->getTargetSearchParam());
    fn_27_2DA3A0(object + 0x12C0, accesser, buildData->getIkData());
    buildData->getSlopeAngleLimit();
    fn_27_2DA3A4(object + 0x12C1, accesser);
    fn_27_2DA3A8(object + 0x12C2, accesser);
    fn_27_2DA3AC(object + 0x12C3, accesser, buildData->fn_27_1DC860());
    fn_27_2DA3B0(object + 0x12C4, accesser);
    fn_27_2DA3B4(object + 0x12C5, accesser, buildData->fn_27_1DC780());
    fn_27_2DA3B8(object + 0x12C6, accesser);
    fn_27_2DBB0C(object + 0x12C8, accesser);
    fn_27_2DBB3C(object + 0x12E0, accesser);
    fn_27_2DBB70(object + 0x1320, accesser);
    fn_27_2DA3BC(object + 0x1338, accesser, fn_27_2815A0());

    if (!fn_27_2DBBA0(object + 0x10CC)->isNull()) {
        ModuleNullableInterface* listener = fn_27_2DBBA0(object + 0x10CC);
        fn_27_2DA3C0(fn_27_304A5C(self))->add(1, listener);
    }

    return self;
}
