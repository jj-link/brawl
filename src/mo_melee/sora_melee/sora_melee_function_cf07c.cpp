#pragma force_active on
struct Obj27 {
    int a;
    int b;
    unsigned int pad : 18;
    unsigned int value : 1;
    unsigned int rest : 13;
};

extern "C" {
int fn_27_CF07C(Obj27 *obj) {
    return obj->value;
}
}
