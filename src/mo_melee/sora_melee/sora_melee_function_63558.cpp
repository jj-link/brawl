#pragma force_active on

struct Pair {
    unsigned int a, b;
};

struct Sub {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

struct Holder {
    char pad[0x14];
    Sub* sub;
};

struct Module {
    char pad[0xD8];
    Holder* holder;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Module*, unsigned long, unsigned long);

extern "C" void fn_27_60AF4(
    Module*, int, int, Pair*, int,
    float, float, float, float, float, float);

extern "C" void fn_27_63558(
    Module* self, int arg, const Pair* input, float a, float b)
{
    Pair value = *input;
    Sub* sub = self->holder->sub;
    float s;
    float r;
    float q;
    float p;

    p = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0x7D7, 0);
    q = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0x7D9, 0);
    r = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0x7D8, 0);
    s = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0x7D6, 0);

    fn_27_60AF4(self, arg, sub->vf3(), &value, 0, a, b, s, r, q, p);
}
