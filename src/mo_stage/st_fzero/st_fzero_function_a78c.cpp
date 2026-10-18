#pragma force_active on
extern "C" {

struct S {
    int a;
    int b;
    int c;
};

int fn_61_A78C(S *p) {
    return p->c >> 28;
}

}
