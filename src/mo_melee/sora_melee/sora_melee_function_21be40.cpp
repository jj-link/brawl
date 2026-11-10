#pragma force_active on
#pragma opt_common_subs off
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);
struct Entry { char pad[4]; unsigned char id; char pad5; short count; char rest[0x1c]; };
struct State {
    Entry entries[32]; char rest[4];
    void initialize() {
        int zero = 0;
        Entry* it = entries;
        do { it->count = zero; it = it + 1; } while (it < entries + 32);
    }
};
extern "C" void* fn_27_21BE40(State* p) {
    p->initialize();
    gfMemFill__FPvUcUl(p, 0, 0x484);
    for (int i = 0; i < 32; i++) p->entries[i].id = i;
    return p;
}