#pragma force_active on
class UnkPoly {
public:
    virtual void foo() { }
};

extern "C" void fn_41_1569C(void* p, short n);

extern "C" UnkPoly* fn_41_156DC(UnkPoly* p, short n) {
    if (p != 0) {
        fn_41_1569C(p, 0);
        if (n > 0) {
            delete p;
        }
    }
    return p;
}
