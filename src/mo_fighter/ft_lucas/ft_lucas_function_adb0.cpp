#pragma force_active on

extern "C" void* fn_114_ACC4(void);

extern "C" void* fn_114_ADB0(void* p, int i) {
    switch (i) {
    case 0: return p;
    case 1: return (char*)p + 0x494;
    case 2: return fn_114_ACC4();
    default: return fn_114_ACC4();
    }
}
