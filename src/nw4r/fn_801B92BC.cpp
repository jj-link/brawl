#pragma force_active on
extern "C" {
void fn_801FF6C8(int arg);

void fn_801B92BC(int *p) {
    int v = *p;
    if (v != 0) {
        fn_801FF6C8(v);
    }
}
}
