#pragma force_active on
#pragma opt_common_subs off

extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);

struct Entry {
    char pad[8];
    short count;
    char rest[0x5A];
};

struct State {
    Entry entries[64];
    char rest[0x20];

    void initialize() {
        int zero = 0;
        Entry* it = entries;
        do {
            it->count = zero;
            it = it + 1;
        } while (it < entries + 64);
    }
};

extern "C" void* fn_27_217590(State* p) {
    p->initialize();
    gfMemFill__FPvUcUl(p, 0, 0x1920);
    return p;
}
