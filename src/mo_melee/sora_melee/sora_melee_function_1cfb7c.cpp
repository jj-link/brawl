#pragma force_active on
struct _S {
    int _a;
    int _b;
    unsigned _pad : 18;
    unsigned _val : 1;
    unsigned _rest : 13;
};

extern "C" unsigned fn_27_1CFB7C(const _S* p) {
    return p->_val;
}
