#pragma force_active on
extern "C" void* fn_112_16B24(void* base, int index)
{
    char* p = static_cast<char*>(base);

    if (index == 9) return p + 0x13D4C;
    if (index == 8) return p + 0x11A10;
    if (index == 7) return p + 0xF6D4;
    if (index == 6) return p + 0xD398;
    if (index == 5) return p + 0xB05C;
    if (index == 4) return p + 0x8D20;
    if (index == 3) return p + 0x69E4;
    if (index == 2) return p + 0x46A8;
    if (index == 1) return p + 0x236C;
    if (index == 0) return p + 0x30;
    return 0;
}
