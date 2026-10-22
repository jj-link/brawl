#pragma force_active on
extern "C" {
void fn_801CD370(void* self, int flags);
void __dl__FPv(void* arr);

void* fn_801CF810(void* a, int b) {
    if (a) {
        fn_801CD370((char*)a + 0xD8, -1);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
}
