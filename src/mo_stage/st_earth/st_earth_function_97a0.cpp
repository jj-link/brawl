#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" int fn_66_97A0(FnObj *obj)
{
    return (obj->flags >> 25) & 1;
}
