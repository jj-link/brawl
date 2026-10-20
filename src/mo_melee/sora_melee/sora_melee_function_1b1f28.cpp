#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int flags;
} FtFlagsHolder;

extern "C" {
int fn_27_1B1F28(FtFlagsHolder *p)
{
    unsigned int x = p->flags;
    unsigned int r = (x << 10) | (x >> 22);
    return (int)(r & 0xFC000000u) >> 27;
}
}
