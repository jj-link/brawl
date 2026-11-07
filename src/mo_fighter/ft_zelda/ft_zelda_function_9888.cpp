#pragma force_active on
extern "C" void* fn_104_979C(void* p, int n);

extern "C" void* fn_104_9888(void* p, int n) {
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char*)p + 0x47c;
    case 2:
        return fn_104_979C(p, n);
    default:
        return fn_104_979C(p, n);
    }
}