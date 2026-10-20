#pragma force_active on
struct X {
    int a;
    int b;
    unsigned int c : 4;
    unsigned int d : 2;
    unsigned int : 26;
};

extern "C" void fn_61_A6E4(X* obj, int val) {
    obj->d = val;
}
