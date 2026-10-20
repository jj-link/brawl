#pragma force_active on
struct Target {
    int a;
    int b;
    void* ptr;
};

struct Source {
    int a;
    int b;
    int c;
    Target* p1;
    Target* p2;
};

extern "C" {
void fn_27_124830(Source* s, void* v) {
    if (s->p1) {
        s->p1->ptr = v;
    }
    if (s->p2) {
        s->p2->ptr = v;
    }
}
}
