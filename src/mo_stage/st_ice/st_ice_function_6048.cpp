#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} FlagsObj;

extern "C" void fn_62_6048(FlagsObj *obj, unsigned int v)
{
    obj->b = v;
}
