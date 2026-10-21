#pragma force_active on
struct Pair {
    int a;
    int b;
};

extern "C" void fn_80051F28(Pair*);

extern "C" Pair fn_80052250() {
    Pair p;
    fn_80051F28(&p);
    return p;
}
