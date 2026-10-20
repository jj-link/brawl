#pragma force_active on
extern "C" {

struct Foo {
    unsigned int x;
    unsigned int y;
    signed int z;
};

signed int fn_27_14F24C(Foo *p) {
    return p->z >> 25;
}

}
