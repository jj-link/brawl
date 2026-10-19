#pragma force_active on
extern "C" void* fn_105_F58C(void* ptr, int index) {
    char* base = static_cast<char*>(ptr);
    if (index == 2) return base + 0x3eb4;
    if (index == 1) return base + 0x1f64;
    if (index == 0) return base + 0x14;
    return 0;
}
