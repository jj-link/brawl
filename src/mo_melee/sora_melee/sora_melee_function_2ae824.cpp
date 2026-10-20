#pragma force_active on
extern "C" int fn_27_2ACD20(void* self, int n, int v);

extern "C" void fn_27_2AE824(char* self, int n, int* p) {
    int idx = fn_27_2ACD20(self, n - 1, -1);
    if (idx >= 0) {
        *(int*)(self + idx * 12 + 0xc) = *p;
    }
}
