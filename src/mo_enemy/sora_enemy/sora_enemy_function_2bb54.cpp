#pragma force_active on
struct Data { float a[11]; float b[11]; };
struct Obj { char pad[0x6c]; Data* data; };
struct Arg { char pad[0x30]; unsigned int flags; char pad34[4]; unsigned int flags2; };
extern "C" int fn_41_2BAD4(void*, int);
extern "C" bool fn_41_2B9D4(void*, unsigned int);
extern "C" const float lbl_41_rodata_DF4;
extern "C" float fn_41_2BB54(Obj* obj, Arg* arg, unsigned int value) {
    float result = lbl_41_rodata_DF4;
    if (!obj->data) return result;
    int index = fn_41_2BAD4(obj, arg->flags & 31);
    if (fn_41_2B9D4(obj, value) == 1)
        result = obj->data->b[index];
    else
        result = obj->data->a[index];
    if (!((arg->flags2 >> 15) & 1)) {
        if (fn_41_2B9D4(obj, value) == 1)
            result *= obj->data->b[10];
        else
            result *= obj->data->a[10];
    }
    return result;
}