#pragma force_active on
typedef struct C { char pad[0x54]; void *f54; } C;
typedef struct B { char pad[0xd8]; C *fd8; } B;
typedef struct A { char pad[0x60]; B *f60; } A;

extern "C" {
void *fn_27_8CD94(A *p)
{
    return p->f60->fd8->f54;
}
}
