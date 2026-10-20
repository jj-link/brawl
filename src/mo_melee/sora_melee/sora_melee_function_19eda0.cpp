#pragma force_active on
extern "C" {
struct X {
    unsigned a;
    unsigned b;
    unsigned c : 15;
    unsigned flag : 1;
};
int fn_27_19EDA0(X* obj) {
    return obj->flag;
}
}
