#pragma force_active on
struct Inner {
    char pad[0x40];
    unsigned int a;
    int pad1;
    int b;
};

struct Outer {
    char pad[8];
    Inner* p;
    char pad2[0x10];
    int code;
    int counter;
};

extern "C" int fn_1_1D2FC(Outer* o)
{
    Inner* in = o->p;
    int r = o->code;

    switch (in->a) {
    case 2:
        r = 2;
        o->counter = in->b + 1;
        break;
    case 3:
        r = 7;
        break;
    case 4:
        r = 8;
        break;
    case 5:
        r = 4;
        o->counter = in->b + 1;
        break;
    case 6:
        r = 6;
        o->counter = in->b + 1;
        break;
    case 8:
        r = 9;
        o->counter = in->b + 1;
        break;
    case 9:
        r = 10;
        break;
    case 7:
        r = 11;
        o->counter = in->b + 1;
        break;
    case 10:
        r = 12;
        o->counter = in->b + 1;
        break;
    }

    return r;
}
