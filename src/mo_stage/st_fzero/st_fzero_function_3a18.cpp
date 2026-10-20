#pragma force_active on
typedef struct {
    char pad[0x6c];
    unsigned char flags;
} St;

extern "C" {
void fn_61_3A18(St *p)
{
    p->flags = p->flags & 0xFFFFFFF7;
}
}
