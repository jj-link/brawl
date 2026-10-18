#pragma force_active on
struct Obj {
    char pad[0x27c];
    unsigned char *p;
};

extern "C" {
void fn_73_5C98(Obj *o)
{
    if (o->p != 0) {
        o->p[0] = 5;
        o->p[1] = 5;
        o->p[2] = 5;
        o->p[3] = 5;
        o->p[4] = 5;
        o->p[5] = 5;
    }
}
}
