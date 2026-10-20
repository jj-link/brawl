#pragma force_active on
typedef struct {
    unsigned int pad[2];
    struct {
        unsigned int a : 4;
        unsigned int b : 4;
        unsigned int c : 24;
    } flags;
} StRec;

extern "C" void fn_47_4F28(StRec *s, unsigned int v)
{
    s->flags.b = v;
}
