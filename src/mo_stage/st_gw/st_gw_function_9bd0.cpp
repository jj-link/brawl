#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} StObj;

extern "C" {
unsigned int fn_63_9BD0(StObj *obj)
{
    return (obj->flags >> 19) & 1;
}
}
