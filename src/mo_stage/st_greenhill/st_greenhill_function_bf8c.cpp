#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
} FnObj;

extern "C" void fn_72_BF8C(FnObj *obj, unsigned int value)
{
    obj->b = value;
}
