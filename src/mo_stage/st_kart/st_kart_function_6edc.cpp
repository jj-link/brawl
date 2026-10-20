#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 4;
    unsigned int rest : 28;
} FnObj;

extern "C" void fn_49_6EDC(FnObj *obj, unsigned int value)
{
    obj->hi = value;
}
