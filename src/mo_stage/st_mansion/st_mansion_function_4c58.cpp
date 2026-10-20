#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int w;
} StObj;

extern "C" {
int fn_47_4C58(StObj *p)
{
    int v = (int)(p->w << 2) & 0xE0000000;
    return v >> 30;
}
}
