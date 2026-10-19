#pragma force_active on
extern "C" void* fn_95_D10C(char* base, int index) {
    if (index == 3) return base + 0x600c;
    if (index == 2) return base + 0x4010;
    if (index == 1) return base + 0x2014;
    if (index == 0) return base + 0x18;
    return 0;
}
