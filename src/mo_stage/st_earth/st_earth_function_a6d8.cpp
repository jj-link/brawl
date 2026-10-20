#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FlagHolder;

extern "C" {
int fn_66_A6D8(FlagHolder *obj)
{
    unsigned int x = obj->flags;
    unsigned int r = (x << 4) | (x >> 28);
    return ((int)(r & 0xF8000000)) >> 28;
}
}
