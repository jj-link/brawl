#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} S;

void fn_52_7674(void *p)
{
    ((S *)p)->flags &= ~0x00080000u;
}
}
