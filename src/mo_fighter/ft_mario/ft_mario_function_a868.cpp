#pragma force_active on
extern "C" int fn_91_A868(unsigned char* self, int idx) {
    int* arr = *(int**)(self + 0xc);
    int old = arr[idx];
    arr[idx] = old - 1;
    return old;
}
