#pragma force_active on
extern "C" {

struct Foo {
    unsigned int a;
    unsigned int b;
    int c;
};

int fn_27_1E7ED4(Foo *obj) {
    return obj->c >> 28;
}

}
