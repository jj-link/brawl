#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} S;

void fn_79_5C78(S *s, unsigned int v)
{
    s->b = v;
}
}
