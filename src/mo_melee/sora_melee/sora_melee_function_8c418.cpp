#pragma force_active on
typedef unsigned long u32;
struct soModuleAccesser;
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual u32 slot39();
};
struct soModuleAccesser { char pad[8]; Object_vptr_3c* info; };
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual int fn_27_7AD2C(soModuleAccesser*, u32, u32);
};
struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual Class_90D8* slot0(soModuleAccesser*);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int slot7(soModuleAccesser*, u32, u32);
};
extern "C" {
extern Object_vptr_4* lbl_27_bss_1B00[5];
int getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser* module, u32 variable, u32 index)
{
    if ((int)variable > 0xabdf) {
        return lbl_27_bss_1B00[module->info->slot39()]->slot0(module)
            ->fn_27_7AD2C(module, variable, index);
    }
    return lbl_27_bss_1B00[module->info->slot39()]->slot7(module, variable, index);
}
}