#pragma force_active on
typedef struct {
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char pad[7];
    signed char a;
    signed char b;
} Obj;

extern "C" void fn_27_25EB9C(Obj* p) {
    p->flag = 0;
    p->a = -1;
    p->b = -1;
}
