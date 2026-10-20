#pragma force_active on
struct S { char pad[0x3c]; unsigned short flags; };
extern "C" void fn_41_28578(S* s, unsigned short m) {
    s->flags &= ~m;
}
