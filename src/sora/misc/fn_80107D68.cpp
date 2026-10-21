#pragma force_active on
extern "C" void fn_8010C52C(char* obj, int idx);

extern "C" int fn_80107D68(char* self) {
    int n = *(int*)(self + 0x10C);
    if (n <= 0) {
        return 0;
    }
    int* p = (int*)(self + 0x104);
    int obj = *p;
    n--;
    *(int*)(self + 0x10C) = n;
    if (obj != 0) {
        fn_8010C52C((char*)obj, n);
    }
    return 1;
}
