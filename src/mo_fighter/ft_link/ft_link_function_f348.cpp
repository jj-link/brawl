#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on
#pragma optimize_for_size on
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
struct Fn93Count {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int get(unsigned long);
};
struct Fn93Value {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void set(float);
};
extern "C" float lbl_93_rodata_40;
extern "C" double lbl_93_rodata_48;
extern "C" void fn_93_F348(void* unused, soModuleAccesser* accesser) {
    char* base = (char*)accesser;
    char* enumeration = *(char**)(base + 0xD8);
    int current = (*(Fn93Count**)(enumeration + 0x64))->get(0x20000000);
    int maximum = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5DC0, 0);
    float result = ((getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFA4, 0) - lbl_93_rodata_40) * ((float)current / (float)maximum)) + lbl_93_rodata_40;
    Fn93Value* value = *(Fn93Value**)(*(char**)(base + 0xD8) + 0x1C);
    value->set(result);
}
