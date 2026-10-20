#pragma force_active on
extern "C" {
void* fn_27_1B1410(char* p, int idx) {
    int n = (*(int*)(p + 8) >> 27) + idx;
    if (n >= 10) {
        n -= 10;
    }
    return p + n * 20 + 12;
}
}
