#pragma force_active on
typedef struct St {
    int a;
    int b;
    unsigned int c;
} St;

extern "C" {
int fn_62_F038(St *s)
{
    unsigned int r = (s->c << 4) | (s->c >> 28);
    return (int)(r & 0xE0000000) >> 30;
}
}
