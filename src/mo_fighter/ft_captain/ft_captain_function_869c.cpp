#pragma force_active on
extern "C" {
extern char lbl_100_data_1B64[];
}

extern "C" void fn_100_869C(void* self, int a, int b, int c) {
    int* p = reinterpret_cast<int*>(self);
    p[0] = reinterpret_cast<int>(lbl_100_data_1B64);
    p[4] = a;
    p[5] = b;
    p[6] = c;
}
