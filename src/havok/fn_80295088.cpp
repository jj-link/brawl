#pragma force_active on
struct S {
    unsigned char pad[0xC];
    float val;
};

extern "C" void fn_80295088(S* s, float f) {
    s->val = f * s->val;
}
