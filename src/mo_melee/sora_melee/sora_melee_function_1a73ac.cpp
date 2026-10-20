#pragma force_active on
extern "C" {

struct fn_27_1A73AC_struct {
    unsigned int a;
    unsigned int b;
    int c;
};

int fn_27_1A73AC(struct fn_27_1A73AC_struct* p) {
    return p->c >> 28;
}

}
