#pragma force_active on
class grDxBigBlue {
public:
    ~grDxBigBlue();
};

extern "C" void __dt__11grDxBigBlueFv(grDxBigBlue*, int);
extern "C" void __dl__FPv(void*);

extern "C" grDxBigBlue* fn_81_69C8(grDxBigBlue* p, int flag) {
    if (p) {
        __dt__11grDxBigBlueFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
