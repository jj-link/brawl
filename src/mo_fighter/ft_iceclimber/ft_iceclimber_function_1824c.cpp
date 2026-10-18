#pragma force_active on
extern "C" void __dl__FPv(void*);

class ftIceObj {
public:
    ~ftIceObj() {}
};

extern "C" {
ftIceObj* fn_105_1824C(ftIceObj* p, short flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
