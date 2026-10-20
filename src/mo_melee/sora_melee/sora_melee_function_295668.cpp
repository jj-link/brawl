#pragma force_active on
extern "C" {

struct X {
    int a;
    int b;
    unsigned c : 5;
    signed d : 5;
};

int fn_27_295668(struct X* x) {
    return x->d;
}

}
