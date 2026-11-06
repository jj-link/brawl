#pragma force_active on
typedef unsigned long u32;

struct soModuleAccesser;

struct ModuleInfoBase { char pad[0x3C]; };
class ModuleInfo : public ModuleInfoBase {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual u32 getKind();
};

struct soModuleAccesser {
    char pad[8];
    ModuleInfo* info;
};

struct ConstantSub_base { char pad[8]; };
class ConstantSub : public ConstantSub_base {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual float getConstantFloat(soModuleAccesser*, u32, u32);
    virtual int getConstantInt(soModuleAccesser*, u32, u32);
};

struct ValueAccesser_base { char pad[4]; };
class ValueAccesser : public ValueAccesser_base {
public:
    virtual ConstantSub* getSub(soModuleAccesser*);
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual float getConstantFloat(soModuleAccesser*, u32, u32);
    virtual int getConstantInt(soModuleAccesser*, u32, u32);
};

extern "C" {
extern ValueAccesser* lbl_27_bss_1B00[5];
}

class soValueAccesser {
public:
    static int getConstantInt(soModuleAccesser* module, u32 variable, u32 index);
};

int soValueAccesser::getConstantInt(soModuleAccesser* module, u32 variable, u32 index)
{
    if ((int)variable > 0x5dbf) {
        return lbl_27_bss_1B00[module->info->getKind()]->getSub(module)
            ->getConstantInt(module, variable, index);
    }
    return lbl_27_bss_1B00[module->info->getKind()]->getConstantInt(
        module, variable, index);
}
