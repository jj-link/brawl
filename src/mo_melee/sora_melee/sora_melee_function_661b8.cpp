#pragma force_active on
struct FnObj27 {
    char pad[0x18];
    unsigned int f18;
    int f1c;
    float f20;
};

extern "C" void fn_27_661B8(FnObj27 *obj, unsigned int a, int b, float c)
{
    obj->f18 = a;
    obj->f1c = b;
    obj->f20 = c;
}
