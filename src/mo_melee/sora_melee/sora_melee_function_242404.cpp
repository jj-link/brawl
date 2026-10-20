#pragma force_active on
struct fn_27_242404_obj {
    char pad[0x5c];
    char a;
    char pad2[1];
    char b;
};

extern "C" {
void fn_27_242404(fn_27_242404_obj* p) {
    p->a = 1;
    p->b = 0;
}
}
