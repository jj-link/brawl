#pragma force_active on
extern "C" {

struct Element {
    union {
        int raw;
        struct {
            unsigned f0 : 4;
            unsigned f1 : 2;
            unsigned f2 : 26;
        } bits;
    } x;
    unsigned char pad[68];
};
struct Container {
    int a;
    int b;
    int c;
    Element* elements;
};

void fn_800B940C(Container* obj, int index) {
    Element* e = obj->elements + index;
    e->x.bits.f1 = 1;
}

}
