#pragma force_active on
struct Ring {
    int pad0;
    int pad4;
    int m8;
    int arr[3];
};

extern "C" void* fn_27_1B0F8C(Ring* r, int i) {
    int s = r->m8 >> 29;
    int j = s + i;
    if (j >= 2) {
        j -= 2;
    }
    return &r->arr[j];
}
