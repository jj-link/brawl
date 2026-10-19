#pragma force_active on
extern "C" {
void fn_27_CB410(void* a, int b, int c);
void fn_27_B215C(void* a, void* b, void* c, void* d, void* e, void* f);

void* fn_115_7404(void* a, void* b, void* c, void* d, void* e) {
    fn_27_CB410(a, 1, 0);
    fn_27_B215C((char*)a + 0x50, b, a, c, d, e);
    return a;
}
}
