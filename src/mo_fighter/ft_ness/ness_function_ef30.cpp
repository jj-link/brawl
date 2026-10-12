// Select one of the sixteen embedded article controllers. Unknown indices
// return null; the descending checks preserve the original dispatch order.
extern "C" void* fn_101_EF30(void* object, int index) {
    char* bytes = static_cast<char*>(object);
    if (index == 15) return bytes + 0x1A574;
    if (index == 14) return bytes + 0x18960;
    if (index == 13) return bytes + 0x16D4C;
    if (index == 12) return bytes + 0x15138;
    if (index == 11) return bytes + 0x13524;
    if (index == 10) return bytes + 0x11910;
    if (index == 9) return bytes + 0xFCFC;
    if (index == 8) return bytes + 0xE0E8;
    if (index == 7) return bytes + 0xC4D4;
    if (index == 6) return bytes + 0xA8C0;
    if (index == 5) return bytes + 0x8CAC;
    if (index == 4) return bytes + 0x7098;
    if (index == 3) return bytes + 0x5484;
    if (index == 2) return bytes + 0x3870;
    if (index == 1) return bytes + 0x1C5C;
    if (index == 0) return bytes + 0x48;
    return 0;
}
