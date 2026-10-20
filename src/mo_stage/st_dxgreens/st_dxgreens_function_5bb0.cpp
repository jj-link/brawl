#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} Flags;

typedef struct {
    int pad[2];
    Flags f;
} Obj;

void fn_79_5BB0(Obj *p, unsigned char v)
{
    p->f.b = v;
}
}
