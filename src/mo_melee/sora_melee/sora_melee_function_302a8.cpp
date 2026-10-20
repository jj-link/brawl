#pragma force_active on
struct FnObj {
    char pad[0x20];
    float f20;
    float f24;
    float f28;
};

extern "C" void fn_27_302A8(FnObj *obj, float a, float b, float c)
{
    obj->f20 = a;
    obj->f24 = b;
    obj->f28 = c;
}
