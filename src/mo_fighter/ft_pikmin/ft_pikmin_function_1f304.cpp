#pragma force_active on
extern "C" {
void fn_113_1F154(unsigned char* p);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* mod, unsigned long a, unsigned long b);
}

struct FighterVals {
    char pad[0x58];
    float value;
};

struct Flags {
    unsigned char b;
    unsigned char a;
};

extern "C" void fn_113_1F304(int unused, FighterVals* self, void* mod)
{
    unsigned char zero = 0;
    Flags f;
    f.a = zero;
    fn_113_1F154(&f.a);
    f.b = zero;
    self->value = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0xfd3, 0);
}
