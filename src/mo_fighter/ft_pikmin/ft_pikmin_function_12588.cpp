#pragma force_active on
extern "C" {
void fn_27_15FBC8(int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* self, unsigned long a, unsigned long b);
}

struct FighterObj {
    char pad[0x78];
    float m_value;
};

struct LocalFlag {
    unsigned char flag;
};

extern "C" void fn_113_12588(int a, FighterObj* obj, int c, void* accesser)
{
    fn_27_15FBC8(0);
    LocalFlag local = {0};
    obj->m_value = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfac, 0);
}
