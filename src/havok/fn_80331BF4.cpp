#pragma force_active on
extern "C" signed char* fn_80331BF4(int arg0, int* arg1) {
    signed char* start = (signed char*)(arg0 + *arg1);
    signed char* p = start;
    int n = 0;

    while (*p != 0) {
        ++n;
        ++p;
    }

    while (n & 3) {
        ++n;
    }

    *arg1 += n;
    return start;
}
