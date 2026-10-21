#pragma force_active on
struct Quad {
    int a;
    int b;
    int c;
    int d;
};

extern "C" void fn_8005E898(Quad* q) {
    q->a = 0;
    q->b = 0;
    q->c = 0;
    q->d = 0;
}
