#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} StObj;

extern "C" {
void fn_71_A074(StObj *p)
{
    p->flags &= 0xFDFFFFFF;
}
}
