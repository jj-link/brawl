#pragma force_active on
extern "C" {
struct PikStruct {
    int a;
    int b;
    int c;
    int d;
    int e;
};
void fn_98_14EE4(PikStruct* s, int v) {
    s->e = v;
    s->d = v;
    s->c = v;
}
}
