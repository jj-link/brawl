#pragma force_active on
extern "C" {

struct S {
    int a;
    int b;
    unsigned x : 18;
    unsigned y : 9;
};

void fn_48_B644(struct S* s, int v) {
    s->y = v;
}

}
