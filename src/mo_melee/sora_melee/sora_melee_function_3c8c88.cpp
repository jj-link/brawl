#include <so/so_module_accesser.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual int slot0(); virtual int slot1(); virtual int slot2(); virtual int slot3();
    virtual int slot4(); virtual int slot5(); virtual int slot6(); virtual int slot7();
    virtual int slot8(); virtual int slot9(); virtual int slot10(); virtual int slot11();
    virtual int slot12(); virtual int slot13(); virtual int slot14(); virtual int slot15();
    virtual int slot16(); virtual int slot17(); virtual int slot18(); virtual int slot19();
    virtual unsigned char slot20(); virtual int slot21(); virtual int slot22(); virtual int slot23();
    virtual int slot24(); virtual int slot25(); virtual int slot26(); virtual int slot27();
    virtual int slot28(); virtual int slot29(); virtual int slot30(); virtual int slot31();
    virtual int slot32();
};

class TaskInterface {
public:
    virtual int slot0(); virtual int slot1(); virtual int slot2(); virtual int slot3();
    virtual int slot4(); virtual int slot5(); virtual int slot6(); virtual int getTaskId();
};

class NullableInterface {
public:
    virtual bool isNull();
    virtual void slot1(); virtual void slot2(); virtual void slot3();
};

class RegistryInterface {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void add(int, NullableInterface*);
};

extern "C" {
void __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
    void*, StageObject*, soResourceModule*, soModelModule*, soMotionModule*,
    soPostureModule*, soGroundModule*, soSituationModule*, void*,
    soCollisionAttackModule*, soCollisionHitModule*, soCollisionShieldModule*,
    soCollisionShieldModule*, soCollisionShieldModule*, void*,
    soCollisionSearchModule*, soDamageModule*, void*, void*, soStopModule*,
    void*, void*, soSoundModule*, soLinkModule*, soVisibilityModule*,
    soControllerModule*, soCameraModule*, soWorkManageModule*, void*,
    soAnimCmdModule*, soStatusModule*, void*, void*, soKineticModule*,
    soEventManageModule*, void*, soEffectModule*, void*, soAreaModule*,
    void*, void*, void*, void*, soShadowModule*, soItemManageModule*,
    soColorBlendModule*, void*, void*, soSlowModule*, void*, void*,
    soParamCustomizeModule*, void*);

void fn_27_2DA1F0(void*);
void* fn_27_2DA3CC(void*);
#define GETTER(n) void* n(void*)
GETTER(fn_27_2F1A54); GETTER(fn_27_2DA89C); GETTER(fn_27_2DA898);
GETTER(fn_27_3203B0); GETTER(fn_27_2DA890); GETTER(fn_27_2DA338);
GETTER(fn_27_2DA32C); GETTER(fn_27_2F563C); GETTER(fn_27_2DA314);
GETTER(fn_27_2DA308); GETTER(fn_27_2DA2FC); GETTER(fn_27_2DA2F0);
GETTER(fn_27_2DA2E4); GETTER(fn_27_2DA2D8); GETTER(fn_27_2DA2CC);
GETTER(fn_27_2DA2C0); GETTER(fn_27_2DA888); GETTER(fn_27_2DA2B4);
GETTER(fn_27_2DA880); GETTER(fn_27_2F3434); GETTER(fn_27_2DA870);
GETTER(fn_27_2DA864); GETTER(fn_27_2DA85C); GETTER(fn_27_2DA858);
GETTER(fn_27_2DA2A8); GETTER(fn_27_2DA854); GETTER(fn_27_2DA29C);
GETTER(fn_27_2DA290); GETTER(fn_27_2E1E48); GETTER(fn_27_2DA84C);
GETTER(fn_27_2DA844); GETTER(fn_27_2DA83C); GETTER(fn_27_2DA278);
GETTER(fn_27_2E1E44); GETTER(fn_27_2DA260); GETTER(fn_27_2DA254);
GETTER(fn_27_2DA248); GETTER(fn_27_2DA23C); GETTER(fn_27_2DA230);
GETTER(fn_27_2DA224); GETTER(fn_27_2DA218); GETTER(fn_27_2DA20C);
GETTER(fn_27_2DA200); GETTER(fn_27_2F4FC0); GETTER(fn_27_2DA82C);
GETTER(fn_27_2E1E40); GETTER(fn_27_2F4FB4); GETTER(fn_27_2DA81C);
GETTER(fn_27_3206AC); GETTER(fn_27_2DA80C); GETTER(fn_27_2DA804);
#undef GETTER

void fn_27_2DA8A4(void*, int, int, int, int);
void fn_27_2DA8D4(void*, void*);
void fn_27_1E107C(void*, int, int, unsigned char, void*);
void fn_27_1E10E0(void*, void*, int, int);
void fn_27_3206C0(void*, void*, int);
void fn_27_2DAC38(void*, void*, int);
void fn_27_2F4FCC(void*, void*, int);
void fn_27_2E2190(void*, void*, short, int);
void fn_27_1E1524(void*, int, void*);
int fn_27_2815A0();
int fn_27_2815F4(StageObject*);
unsigned char fn_27_2815FC(StageObject*);
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
void fn_27_2DB0C8(void*, void*, int, int);
void fn_27_2DB554(void*);
void fn_27_2DB558(void*);
void fn_27_2F3440(void*, void*);
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
void fn_27_2F5D2C(void*, void*);
void fn_27_2DA3B4(void*, void*, int);
void fn_27_2DA3B8(void*, void*);
void fn_27_2DBB0C(void*, void*);
void fn_27_3203BC(void*, void*);
void fn_27_2F1A60(void*, void*);
void fn_27_2DA3BC(void*, void*, int);
void* fn_27_2DA348(void*);
void* fn_27_2DBBA0(void*);
void* fn_27_3C8C80(void*);
void* fn_27_2DA3C0(void*);
}

#define GET(n, o) n(object + (o))
#define AS(T, n, o) static_cast<T*>(GET(n, o))

extern "C" void* fn_27_3C8C88(void* self, StageObject* stage, Object_vptr_0* data) {
    char* object = static_cast<char*>(self);

    fn_27_2DA1F0(self);
    fn_27_2DA3CC(self);

    __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
        object + 0x7F8, stage,
        AS(soResourceModule, fn_27_2DA804, 0x900),
        AS(soModelModule, fn_27_2DA80C, 0x930),
        AS(soMotionModule, fn_27_3206AC, 0xB10),
        AS(soPostureModule, fn_27_2DA81C, 0xD58),
        AS(soGroundModule, fn_27_2F4FB4, 0xE0C),
        AS(soSituationModule, fn_27_2E1E40, 0xE10),
        GET(fn_27_2DA82C, 0xE4C),
        AS(soCollisionAttackModule, fn_27_2F4FC0, 0xEB0),
        AS(soCollisionHitModule, fn_27_2DA200, 0xEB1),
        AS(soCollisionShieldModule, fn_27_2DA20C, 0xEB2),
        AS(soCollisionShieldModule, fn_27_2DA218, 0xEB3),
        AS(soCollisionShieldModule, fn_27_2DA224, 0xEB4),
        GET(fn_27_2DA230, 0xEB5),
        AS(soCollisionSearchModule, fn_27_2DA23C, 0xEB6),
        AS(soDamageModule, fn_27_2DA248, 0xEB7),
        GET(fn_27_2DA254, 0xEB8),
        GET(fn_27_2DA260, 0xEB9),
        AS(soStopModule, fn_27_2E1E44, 0xEBC),
        GET(fn_27_2DA278, 0xEE0),
        GET(fn_27_2DA83C, 0xEE4),
        AS(soSoundModule, fn_27_2DA844, 0xEF0),
        AS(soLinkModule, fn_27_2DA84C, 0xF58),
        AS(soVisibilityModule, fn_27_2E1E48, 0x10BC),
        AS(soControllerModule, fn_27_2DA290, 0x10D0),
        AS(soCameraModule, fn_27_2DA29C, 0x10D1),
        AS(soWorkManageModule, fn_27_2DA854, 0x10D4),
        GET(fn_27_2DA2A8, 0x16D6),
        AS(soAnimCmdModule, fn_27_2DA858, 0x1108),
        AS(soStatusModule, fn_27_2DA85C, 0x11AC),
        GET(fn_27_2DA864, 0x1368),
        GET(fn_27_2DA870, 0x1369),
        AS(soKineticModule, fn_27_2F3434, 0x136A),
        AS(soEventManageModule, fn_27_2DA880, 0),
        GET(fn_27_2DA2B4, 0x13C8),
        AS(soEffectModule, fn_27_2DA888, 0x13CC),
        GET(fn_27_2DA2C0, 0x155C),
        AS(soAreaModule, fn_27_2DA2CC, 0x155D),
        GET(fn_27_2DA2D8, 0x155E),
        GET(fn_27_2DA2E4, 0x155F),
        GET(fn_27_2DA2F0, 0x1560),
        GET(fn_27_2DA2FC, 0x1561),
        AS(soShadowModule, fn_27_2DA308, 0x1562),
        AS(soItemManageModule, fn_27_2DA314, 0x1563),
        AS(soColorBlendModule, fn_27_2F563C, 0x1564),
        GET(fn_27_2DA32C, 0x16B8),
        GET(fn_27_2DA338, 0x16B9),
        AS(soSlowModule, fn_27_2DA890, 0x16BC),
        GET(fn_27_3203B0, 0x16D4),
        GET(fn_27_2DA898, 0x8D8),
        AS(soParamCustomizeModule, fn_27_2DA89C, 0x8F0),
        GET(fn_27_2F1A54, 0x16D5));

    fn_27_2DA8A4(object + 0x8D8, data->slot27(), data->slot28(),
                  data->slot29(), data->slot30());
    fn_27_2DA8D4(object + 0x8F0, object + 0x7F8);

    int resourceGroup = data->slot2();
    fn_27_1E107C(object + 0x900, data->slot0(), data->slot1(),
                 static_cast<unsigned char>(resourceGroup), object + 0x7F8);
    int modelData;
    int modelHeap;
    modelHeap = fn_27_2815A0();
    modelData = data->slot24();
    data->slot18();
    fn_27_1E10E0(object + 0x930, object + 0x7F8, modelData, modelHeap);
    fn_27_3206C0(object + 0xB10, object + 0x7F8, data->slot4());
    fn_27_2DAC38(object + 0xD58, object + 0x7F8, fn_27_2815A0());
    fn_27_2F4FCC(object + 0xE0C, object + 0x7F8, data->slot8());

    int situationHeap = fn_27_2815A0();
    int taskId = reinterpret_cast<TaskInterface*>(
        static_cast<char*>(fn_27_2DA348(object + 0x7F8)) + 8)->getTaskId();
    fn_27_2E2190(object + 0xE10, object + 0x7F8,
                 static_cast<short>(taskId), situationHeap);
    fn_27_1E1524(object + 0xE4C, data->slot3(), object + 0x7F8);

    fn_27_2F4FD0(object + 0xEB0, object + 0x7F8, fn_27_2815F4(stage),
                  static_cast<unsigned char>(fn_27_2815FC(stage)), fn_27_2815A0());
    fn_27_2DA354(object + 0xEB1, object + 0x7F8, fn_27_2815F4(stage),
                  static_cast<unsigned char>(fn_27_2815FC(stage)), fn_27_2815A0());
    fn_27_2DA358(object + 0xEB2, object + 0x7F8, fn_27_2815F4(stage), static_cast<unsigned char>(fn_27_2815FC(stage)));
    fn_27_2DA35C(object + 0xEB3, object + 0x7F8, fn_27_2815F4(stage), static_cast<unsigned char>(fn_27_2815FC(stage)));
    fn_27_2DA360(object + 0xEB4, object + 0x7F8, fn_27_2815F4(stage), static_cast<unsigned char>(fn_27_2815FC(stage)));
    fn_27_2DA364(object + 0xEB5, object + 0x7F8, fn_27_2815F4(stage), static_cast<unsigned char>(fn_27_2815FC(stage)));
    fn_27_2DA368(object + 0xEB6, object + 0x7F8, fn_27_2815F4(stage), static_cast<unsigned char>(fn_27_2815FC(stage)));
    fn_27_2DA36C(object + 0xEB7, object + 0x7F8, fn_27_2815A0());
    fn_27_2DA370(object + 0xEB8, object + 0x7F8);
    fn_27_2DA374(object + 0xEB9, object + 0x7F8);
    fn_27_2E21CC(object + 0xEBC, object + 0x7F8);
    fn_27_2DA37C(object + 0xEE0, object + 0x7F8);
    fn_27_1E15A4(object + 0xEE4, object + 0x7F8, data->slot5());
    fn_27_2DB024(object + 0xEF0, object + 0x7F8, data->slot31(), fn_27_2815A0());
    fn_27_1E1648(object + 0xF58, object + 0x7F8);
    fn_27_2E21FC(object + 0x10BC, object + 0x7F8, data->slot6());

    taskId = reinterpret_cast<TaskInterface*>(
        static_cast<char*>(fn_27_2DA348(object + 0x7F8)) + 8)->getTaskId();
    fn_27_2DA384(object + 0x10D0, object + 0x7F8, static_cast<short>(taskId));
    fn_27_2DA388(object + 0x10D1, object + 0x7F8,
                  data->slot21(), data->slot22(), fn_27_2815A0());
    fn_27_2DB098(object + 0x10D4, object + 0x7F8, data->slot19());

    taskId = reinterpret_cast<TaskInterface*>(
        static_cast<char*>(fn_27_2DA348(object + 0x7F8)) + 8)->getTaskId();
    fn_27_1E16CC(object + 0x1108, static_cast<short>(taskId));
    fn_27_2DB0C8(object + 0x11AC, object + 0x7F8, data->slot7(), data->slot26());

    fn_27_2DB554(object + 0x1368);
    fn_27_2DB558(object + 0x1369);
    fn_27_2F3440(object + 0x136A, object + 0x7F8);
    fn_27_1E1774(object + 0x136C);
    fn_27_2DA38C(object + 0x13C8, object + 0x7F8);
    fn_27_2DB778(object + 0x13CC, object + 0x7F8, data->slot9(),
                  data->slot10(), data->slot11(), data->slot12(),
                  fn_27_2815A0());

    fn_27_2DA390(object + 0x155C, object + 0x7F8);
    fn_27_2DA394(object + 0x155D, object + 0x7F8,
                  data->slot20(), fn_27_2815A0());
    fn_27_2DA398(object + 0x155E, object + 0x7F8, data->slot13(), data->slot14());
    fn_27_2DA39C(object + 0x155F, object + 0x7F8, data->slot15());
    fn_27_2DA3A0(object + 0x1560, object + 0x7F8, data->slot16());
    data->slot32();
    fn_27_2DA3A4(object + 0x1561, object + 0x7F8);
    fn_27_2DA3A8(object + 0x1562, object + 0x7F8);
    fn_27_2DA3AC(object + 0x1563, object + 0x7F8, data->slot23());
    fn_27_2F5D2C(object + 0x1564, object + 0x7F8);
    fn_27_2DA3B4(object + 0x16B8, object + 0x7F8, data->slot25());
    fn_27_2DA3B8(object + 0x16B9, object + 0x7F8);
    fn_27_2DBB0C(object + 0x16BC, object + 0x7F8);
    fn_27_3203BC(object + 0x16D4, object + 0x7F8);
    fn_27_2F1A60(object + 0x16D5, object + 0x7F8);
    fn_27_2DA3BC(object + 0x16D6, object + 0x7F8, fn_27_2815A0());

    if (!reinterpret_cast<NullableInterface*>(fn_27_2DBBA0(object + 0x136C))->isNull()) {
        NullableInterface* listener =
            reinterpret_cast<NullableInterface*>(fn_27_2DBBA0(object + 0x136C));
        reinterpret_cast<RegistryInterface*>(fn_27_2DA3C0(fn_27_3C8C80(self)))
            ->add(1, listener);
    }
    return self;
}

#undef AS
#undef GET
