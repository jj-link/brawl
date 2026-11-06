#pragma force_active on
typedef unsigned long u32;
typedef float f32;

struct soModuleAccesser;

struct ModuleBase { char pad[0x3C]; };
class Module : public ModuleBase {
public:
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7();
    virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
    virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
    virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
    virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35();
    virtual void u36(); virtual void u37(); virtual void u38();
    virtual unsigned long getKind();
};

struct DirectMethods {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int s4(unsigned long);
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11();
    virtual f32 s12(unsigned long);
};

struct ValueData {
    char pad[0x64];
    DirectMethods* methods;
};

struct SubBase { char pad[8]; };
class Sub : public SubBase {
public:
    virtual void s0(soModuleAccesser*);
    virtual void s1(soModuleAccesser*);
    virtual void s2(soModuleAccesser*);
    virtual void s3(soModuleAccesser*);
    virtual f32 getFloat(soModuleAccesser*, unsigned long, unsigned long);
};

struct ValueAccesserBase { char pad[4]; };
class ValueAccesser : public ValueAccesserBase {
public:
    virtual Sub* getSub(soModuleAccesser*);
    virtual void v1(soModuleAccesser*);
    virtual f32 getVarFloat(soModuleAccesser*, unsigned long, unsigned long);
    virtual void v3(soModuleAccesser*);
    virtual void v4(soModuleAccesser*);
    virtual f32 getDefFloat(soModuleAccesser*, unsigned long, unsigned long);
};

struct soModuleAccesser {
    char pad[8];
    Module* module;
    char padC[0xCC];
    ValueData* data;
};

extern "C" ValueAccesser* lbl_27_bss_1B00[5];
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" f32 getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser* self, unsigned long id, unsigned long index)
{
    int kind = (int)(id >> 28);
    int flag = 0;
    if (kind > 0 && kind < 3)
        flag = 1;
    if (flag != 0) {
        int type = (int)((id >> 24) & 0xF);
        if (type == 0) {
            int result = self->data->methods->s4(id);
            return (f32)result;
        }
        return self->data->methods->s12(id);
    }

    int sv = (int)id;
    if (sv > 0x4e1f) {
        int result = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self, id, index);
        return (f32)result;
    }
    if (sv < 0x7cf) {
        unsigned long k = self->module->getKind();
        return lbl_27_bss_1B00[k]->getVarFloat(self, id, index);
    }
    if (sv > 0xf9f) {
        unsigned long k = self->module->getKind();
        Sub* sub = lbl_27_bss_1B00[k]->getSub(self);
        return sub->getFloat(self, id, index);
    }
    {
        unsigned long k = self->module->getKind();
        return lbl_27_bss_1B00[k]->getDefFloat(self, id, index);
    }
}