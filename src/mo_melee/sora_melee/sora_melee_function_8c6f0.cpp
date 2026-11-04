#pragma force_active on

typedef unsigned int u32;
typedef int s32;
struct soValueAccesser;
struct Module {
    unsigned char pad[0x3C];
    virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
    virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
    virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual u32 getKind();
};
struct DirectMethods {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int slot4(u32);
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual float slot12(u32);
};
struct Returned {
    unsigned char pad[8];
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4();
    virtual int slot5(soValueAccesser*, u32, u32);
};
struct ValueAccesserBase {
    unsigned char pad[4];
    virtual Returned* getVariant(soValueAccesser*);
    virtual void slot1(); virtual void slot2();
    virtual int getVariableInt(soValueAccesser*, u32, u32);
    virtual void slot4(); virtual void slot5();
    virtual int getVariableInt2(soValueAccesser*, u32, u32);
};
struct ValueAccesser : ValueAccesserBase {};
struct soValueAccesser {
    unsigned char pad0[8];
    Module* module;
    unsigned char padC[0xCC];
    struct ValueData { unsigned char pad[0x64]; DirectMethods* methods; }* data;
};
extern "C" ValueAccesser* lbl_27_bss_1B00[5];
extern "C" float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soValueAccesser*, u32, u32);

extern "C" s32 getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soValueAccesser* self, u32 id, u32 index)
{
    s32 top = (s32)(id >> 28);
    s32 flag = 0;
    if (top > 0 && top < 3)
        flag = 1;
    if (flag != 0) {
        s32 type = (s32)((id >> 24) & 0xF);
        if (type == 1) {
            float value = self->data->methods->slot12(id);
            return (s32)value;
        }
        return self->data->methods->slot4(id);
    }

    s32 sid = (s32)id;
    if (sid < 0x4E1F) {
        float value = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, id, index);
        return (s32)value;
    } else if (sid < 0x55EF) {
        u32 kind = self->module->getKind();
        return lbl_27_bss_1B00[kind]->getVariableInt(self, id, index);
    } else if (sid > 0x5DBF) {
        u32 kind = self->module->getKind();
        Returned* returned = lbl_27_bss_1B00[kind]->getVariant(self);
        return returned->slot5(self, id, index);
    } else {
        u32 kind = self->module->getKind();
        return lbl_27_bss_1B00[kind]->getVariableInt2(self, id, index);
    }
}
