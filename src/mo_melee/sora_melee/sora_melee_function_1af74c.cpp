#pragma force_active on
struct Obj
{
    int pad[2];
    int value;
    int items[309];
};

extern "C" int *fn_27_1AF74C(Obj *obj, int index)
{
    int adjustment = obj->value >> 22;
    int result = adjustment + index;

    if (result >= 0x135)
        result -= 0x135;

    return reinterpret_cast<int *>(
        reinterpret_cast<char *>(obj) + 0x0C + result * 4);
}
