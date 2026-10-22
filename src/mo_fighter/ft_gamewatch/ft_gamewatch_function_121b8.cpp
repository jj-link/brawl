#pragma force_active on

struct soModuleAccesser {
    char pad00[0xd8];
    struct {
        char pad00[0x7c];
        void* kinetic;
    }* modules;
};

struct KineticModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void setEnergy(int, void*);
};

struct MotionEnergy {
    char pad00[0x14];
    float unk14;
    char pad18[4];
    float unk1c;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern const char g_ftCommonDataAccesser[];
extern const char lbl_107_data_8E64[], lbl_107_data_3B18[];
}

extern "C" void fn_107_121B8(void*, soModuleAccesser* accesser) {
    KineticModule* kinetic =
        static_cast<KineticModule*>(accesser->modules->kinetic);
    const char* data = static_cast<const char*>(
        getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12));
    const char* scalePtr =
        *reinterpret_cast<const char* const*>(data + 0x84);
    kinetic->setEnergy(0, accesser);
    MotionEnergy* energy = static_cast<MotionEnergy*>(__dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_107_data_8E64, lbl_107_data_3B18, 1));
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xbd0, 0);
    float scale = *reinterpret_cast<const float*>(scalePtr + 0xc);
    float value = c * scale;
    energy->unk1c = value;
    energy->unk14 = value;
}
