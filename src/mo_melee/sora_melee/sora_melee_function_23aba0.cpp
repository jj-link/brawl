#pragma force_active on
typedef struct SomeObj {
    char pad[0x44];
    unsigned char kind;
} SomeObj;

extern "C" int fn_27_23ABA0(SomeObj *obj)
{
    return obj->kind == 3;
}
