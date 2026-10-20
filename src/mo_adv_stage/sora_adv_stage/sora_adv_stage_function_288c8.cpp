#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 2;
    unsigned int mid : 2;
    unsigned int lo : 28;
} FlagObj;

extern "C" void fn_40_288C8(FlagObj *obj, unsigned int val)
{
    obj->mid = val;
}
