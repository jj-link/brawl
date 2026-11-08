#pragma force_active on

struct ObjVptr0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, unsigned long);
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern const char g_ftCommonDataAccesser[];
extern const float lbl_95_rodata_118;
}

extern "C" void fn_95_14378(void* self, char* obj) {
    ObjVptr0* work = *(ObjVptr0**)(*(char**)(obj + 0xd8) + 0x64);
    char* data = (char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 4);
    char* ft = *(char**)(data + 0x88);
    float f = lbl_95_rodata_118 * *(float*)(ft + 0x5c);
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xdb2, 0);
    f = f - *(float*)(ft + 0x60) * c;
    work->slot13(f, 0x21000004);
}
