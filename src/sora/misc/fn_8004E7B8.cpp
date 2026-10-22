#pragma force_active on
struct S { int a[9]; char* p; };
extern "C" {
char* fn_8004E7B8(S* arg0, int arg1) {
    return arg0->p + arg1 + 0x2E8;
}
}
