#pragma force_active on
class grYakumono {
};

extern "C" {
void __dt__10grYakumonoFv(void* p, int flag);
void __dl__FPv(void* p);

grYakumono* fn_78_17D0(grYakumono* p, int flag) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
