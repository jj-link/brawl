#pragma force_active on
extern "C" void __dl__FPv(void*);

struct emTmp {
    ~emTmp() { }
};

extern "C" {
emTmp* fn_95_FAC4(emTmp* p, short flag) {
    if (p != 0) {
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
