#pragma force_active on
extern "C" void* fn_117_893C(void* p, int n);

extern "C" void* fn_117_8A28(void* p, int n) {
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char*)p + 0x4f4;
    case 2:
        return fn_117_893C(p, n);
    default:
        return fn_117_893C(p, n);
    }
}
