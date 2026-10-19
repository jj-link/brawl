#pragma force_active on
extern "C" {
void fn_27_CB410(void*, int, int);
void fn_27_B215C(void*, void*, void*, void*, void*, void*);

void* fn_108_8CE0(void* a, void* b, void* c, void* d, void* e) {
    fn_27_CB410(a, 1, 0);
    fn_27_B215C((char*)a + 0x50, b, a, c, d, e);
    return a;
}
}
