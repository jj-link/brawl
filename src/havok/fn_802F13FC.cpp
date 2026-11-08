#pragma force_active on
extern "C" void __dl__FPv(void*);
extern char lbl_8059F018;

struct Ent {
    const char* name;
    unsigned int t;
    unsigned int pad;
};

struct Log {
    int a;
    Ent* cur;
    int b;
    Ent* end;
    int c;
    int d;
};

extern Log lbl_80532448;

extern "C" {
void* __dt__14Class_802F13FCFv(void* arg0, int arg1) {
    if (arg0 != 0) {
        Log* l = &lbl_80532448;
        if ((signed char)(l->cur < l->end) != 0) {
            Ent* e = l->cur;
            e->name = &lbl_8059F018;
            register unsigned int t;
            asm {
                mftb t, 268
            }
            e->t = t;
            l->cur = e + 1;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
