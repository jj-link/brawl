#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int flags;
} StNorfairObj;

extern "C" int fn_54_6650(StNorfairObj *obj)
{
    return (int)((obj->flags << 4) & 0xE0000000) >> 30;
}
