#pragma force_active on
class ModuleBase {
public:
    virtual void vf2(); virtual void vf3(); virtual void vf4();
    virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual void vf9();
    virtual void vf10();
    virtual bool queryFlag(int id);
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15(); virtual void vf16();
    virtual void vf17();
    virtual void setPtrParam(int id, void* p, int b);
    virtual void vf19(); virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27(); virtual void vf28();
    virtual void vf29(); virtual void vf30(); virtual void vf31(); virtual void vf32(); virtual void vf33();
    virtual void vf34(); virtual void vf35(); virtual void vf36(); virtual void vf37(); virtual void vf38();
    virtual void vf39(); virtual void vf40(); virtual void vf41(); virtual void vf42(); virtual void vf43();
    virtual void vf44(); virtual void vf45(); virtual void vf46(); virtual void vf47(); virtual void vf48();
    virtual void vf49(); virtual void vf50(); virtual void vf51(); virtual void vf52(); virtual void vf53();
    virtual void vf54(); virtual void vf55(); virtual void vf56(); virtual void vf57(); virtual void vf58();
    virtual void vf59(); virtual void vf60(); virtual void vf61(); virtual void vf62(); virtual void vf63();
    virtual void vf64(); virtual void vf65(); virtual void vf66(); virtual void vf67(); virtual void vf68();
    virtual void vf69(); virtual void vf70(); virtual void vf71(); virtual void vf72(); virtual void vf73();
    virtual void vf74(); virtual void vf75(); virtual void vf76(); virtual void vf77(); virtual void vf78();
    virtual void vf79(); virtual void vf80(); virtual void vf81(); virtual void vf82(); virtual void vf83();
    virtual void vf84(); virtual void vf85(); virtual void vf86(); virtual void vf87(); virtual void vf88();
    virtual void vf89(); virtual void vf90(); virtual void vf91(); virtual void vf92(); virtual void vf93();
    virtual void vf94(); virtual void vf95(); virtual void vf96(); virtual void vf97(); virtual void vf98();
    virtual void vf99(); virtual void vf100();
    virtual void setValue(int id, bool a, bool b);
};

struct FighterModuleAccesser {
    char pad_00[0x54];
    ModuleBase* module;
};

struct Fighter {
    char pad_00[0xd8];
    FighterModuleAccesser* accesser;
};

struct ParamBlock {
    int value;
    char flag;
};

extern "C" void fn_105_13CC4(Fighter* fighter);

extern "C" void fn_105_13BC0(void* unused, Fighter* fighter, int param) {
    ModuleBase* mod = fighter->accesser->module;
    if (mod->queryFlag(6) == true) {
        mod = fighter->accesser->module;
        mod->setValue(6, false, false);
    }
    fn_105_13CC4(fighter);
    mod = fighter->accesser->module;
    if (mod->queryFlag(6) == true) {
        if (param != 0 && param != 0x10 && param != 0x117 && param != 0x120 && param != 0x11a) {
            ParamBlock p;
            p.value = 0x458;
            p.flag = 0;
            mod = fighter->accesser->module;
            mod->setPtrParam(6, &p, 0);
        }
    }
}
