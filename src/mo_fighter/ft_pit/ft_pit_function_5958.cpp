#pragma force_active on
extern "C" void __dl__FPv(void*);

struct ftPitBase {
    ~ftPitBase() {}
};

extern "C" void* fn_112_5958(ftPitBase* p, short flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
