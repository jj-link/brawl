#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int value;
} FnObj;

extern "C" {
int fn_54_10124(FnObj *obj)
{
    unsigned int u = obj->value;
    return (int)((u << 6 | u >> 26) & 0xFE000000) >> 26;
}
}
