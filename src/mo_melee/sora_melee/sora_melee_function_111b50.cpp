#pragma force_active on
struct S {
    char _pad[0x4e4];
    float _4e4;
};

extern "C" void fn_27_111B50(S** pp, float val) {
    (*pp)->_4e4 = val;
}
