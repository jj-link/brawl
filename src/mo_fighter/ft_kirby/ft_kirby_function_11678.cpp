#pragma force_active on
struct Obj {
    int a;
    int b;
    int c;
};

struct Arg {
    unsigned char pad[0x88];
};

extern "C" int fn_96_11678(Obj* self, Arg* obj) {
    typedef unsigned int (*Fn)(Arg*);
    Fn fn = *(Fn*)self;
    unsigned int result = fn((Arg*)((char*)obj + 0x88));

    if (result == 1) {
        self->b++;
    } else {
        self->c++;
    }

    return 1;
}
