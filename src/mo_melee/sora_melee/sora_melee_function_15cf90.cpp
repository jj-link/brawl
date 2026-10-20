#pragma force_active on
struct Obj
{
    char pad[0x3c];
    float value;
};

extern "C" void fn_27_15CF90(Obj *obj, float scale)
{
    obj->value *= scale;
}
