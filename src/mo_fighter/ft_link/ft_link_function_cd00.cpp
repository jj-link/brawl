#pragma force_active on
extern "C" void* fn_93_CD00(void* base, int index) {
    if (index == 3) return (char*)base + 0x5fac;
    if (index == 2) return (char*)base + 0x3fd0;
    if (index == 1) return (char*)base + 0x1ff4;
    if (index == 0) return (char*)base + 0x18;
    return 0;
}
