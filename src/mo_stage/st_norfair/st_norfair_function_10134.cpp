#pragma force_active on
struct S { unsigned char pad[8]; unsigned int flags; };

extern "C" {
unsigned int fn_54_10134(S *arg0) {
    return (arg0->flags << 18) >> 31;
}
}
