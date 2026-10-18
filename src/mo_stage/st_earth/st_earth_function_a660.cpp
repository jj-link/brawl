#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} StFlagObj;

int fn_66_A660(StFlagObj *obj)
{
    return (obj->flags >> 19) & 1;
}
}
