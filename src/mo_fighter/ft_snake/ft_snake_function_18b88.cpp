#pragma force_active on
extern "C" bool fn_122_18B88(void *self)
{
    struct Flags {
        unsigned char a : 1;
        unsigned char b : 1;
        unsigned char c : 6;
    };
    struct Obj {
        unsigned char pad[0xa4];
        Flags f;
    };
    Obj *o = (Obj *)self;
    return o->f.b;
}
