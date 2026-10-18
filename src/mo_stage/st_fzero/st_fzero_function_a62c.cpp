#pragma force_active on
struct FzeroObj {
    int pad[2];
    int value;
};

extern "C" int fn_61_A62C(FzeroObj *obj)
{
    return obj->value >> 30;
}
