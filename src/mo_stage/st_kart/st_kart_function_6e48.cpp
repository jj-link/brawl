#pragma force_active on
extern "C" {

typedef struct {
    int a;
    int b;
    unsigned c : 2;
    unsigned d : 2;
    unsigned e : 28;
} Foo;

void fn_49_6E48(Foo *p, unsigned v) {
    p->d = v;
}

}
