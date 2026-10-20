#pragma force_active on
extern "C" {
struct T {
    int a;
    int b;
    struct {
        unsigned: 10;
        signed f: 10;
    } c;
};
int fn_27_1A6958(T* self) { return self->c.f; }
}
