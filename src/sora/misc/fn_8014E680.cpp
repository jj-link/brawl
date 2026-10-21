#pragma force_active on
typedef struct {
    int field1;
    int field2;
} Element;

typedef struct {
    char pad[0x30];
    Element elements[8];
    unsigned short count;
} Foo;

extern "C" void fn_8014E680(Foo *foo, int a1, int a2, int a3) {
    unsigned int c = foo->count;
    if (c < 8) {
        int np = c + 1;
        foo->count = np;
        Element *e = foo->elements + c;
        e->field2 = a3;
        e->field1 = a2;
    }
}
