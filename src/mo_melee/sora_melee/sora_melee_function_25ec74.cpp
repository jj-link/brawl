#pragma force_active on
extern "C" int fn_27_25EF4C(void* self, int a, int b);

extern "C" void fn_27_25EC74(char* self, int* src) {
    int idx = fn_27_25EF4C(self, -1, -1);
    if (idx >= 0) {
        *(int*)(self + idx * 12 + 0xC) = *src;
    }
}
