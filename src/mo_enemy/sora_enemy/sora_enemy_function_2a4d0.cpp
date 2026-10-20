#pragma force_active on
struct Inner { char pad[0x14]; unsigned char val; };
struct Outer { Inner* inner; unsigned char val; };

extern "C" void fn_41_2A4D0(Outer* p) {
    p->val = p->inner->val;
}
