#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int top : 6;
    unsigned int rest : 26;
} FlagHolder;

extern "C" void fn_48_BDA0(FlagHolder *obj, unsigned int v)
{
    obj->top = v;
}
