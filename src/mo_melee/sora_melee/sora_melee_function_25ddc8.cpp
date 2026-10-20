#pragma force_active on
struct FnObj27 {
    char pad[0x10];
    int value;
};

extern "C" void fn_27_25DDC8(FnObj27 *obj, int delta)
{
    obj->value += delta;
}
