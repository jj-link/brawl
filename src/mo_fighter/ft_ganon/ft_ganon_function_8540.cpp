#pragma force_active on
extern "C" void* fn_109_8454(void* p, int n);

extern "C" void* fn_109_8540(char* p, int n) {
    switch (n) {
    case 0:
        return p;
    case 1:
        return p + 0x494;
    case 2:
        return fn_109_8454(p, n);
    default:
        return fn_109_8454(p, n);
    }
}
