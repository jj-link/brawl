#pragma force_active on
typedef struct {
    int pad[2];
    struct {
        unsigned int a : 4;
        unsigned int b : 2;
        unsigned int c : 26;
    } flags;
} FlagObj;

extern "C" {
void fn_79_5B74(FlagObj *obj, unsigned int v)
{
    obj->flags.b = v;
}
}
