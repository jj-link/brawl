#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

class grYakumono {
public:
    ~grYakumono();
};

extern "C" {
grYakumono* fn_47_18F4(grYakumono* p, int flag) {
    if (p) {
        if (p) {
            __dt__10grYakumonoFv(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
