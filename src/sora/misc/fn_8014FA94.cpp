#pragma force_active on
typedef unsigned long long u64;

extern void* g_GameGlobal;

extern "C" void fn_8014FA94(u64 arg0) {
    char* p = *(char**)((char*)g_GameGlobal + 0x34);
    p[0x77] = (char)(arg0 >> 56);
    p[0x78] = (char)(arg0 >> 48);
    p[0x79] = (char)(arg0 >> 40);
    p[0x7A] = (char)(arg0 >> 32);
    p[0x7B] = (char)(arg0 >> 24);
    p[0x7C] = (char)(arg0 >> 16);
    p[0x7D] = (char)(arg0 >> 8);
    p[0x7E] = (char)arg0;
}
