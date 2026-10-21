#pragma force_active on
extern "C" {
void fn_801D7718(void* p, int v);
void fn_801D7774(void* p, int v);

void fn_80190A74(void** self, int flag) {
    void* p = self[0];
    if (flag != 0) {
        fn_801D7718(p, 0xa0);
    } else {
        fn_801D7774(p, 0xa0);
    }
}
}
