#pragma force_active on
extern void* g_GameGlobal;

extern "C" void fn_8014F958(unsigned long long value) {
    char* p = *(char**)((char*)g_GameGlobal + 0x34);
    p[0x38] = (char)(value >> 56);
    p[0x39] = (char)(value >> 48);
    p[0x3A] = (char)(value >> 40);
    p[0x3B] = (char)(value >> 32);
    p[0x3C] = (char)(value >> 24);
    p[0x3D] = (char)(value >> 16);
    p[0x3E] = (char)(value >> 8);
    p[0x3F] = (char)value;
}
