#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 2;
    unsigned int rest : 30;
} FnObj;

extern "C" void fn_67_4FF4(FnObj *obj, unsigned int v)
{
    obj->hi = v;
}
