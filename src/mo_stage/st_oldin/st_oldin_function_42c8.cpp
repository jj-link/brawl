#pragma force_active on
struct S {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_53_42C8(S* s) {
    s->flags &= ~8;
}
