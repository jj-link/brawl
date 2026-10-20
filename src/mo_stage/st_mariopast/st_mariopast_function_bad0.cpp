#pragma force_active on
extern "C" {

struct S {
    int a;
    int b;
    unsigned int : 6;
    unsigned int c : 6;
    unsigned int : 20;
};

void fn_48_BAD0(struct S* p, int v) {
    p->c = v;
}

}
