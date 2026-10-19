#pragma force_active on
struct S {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_54_3354(S* s) {
    s->flags &= ~8;
}
