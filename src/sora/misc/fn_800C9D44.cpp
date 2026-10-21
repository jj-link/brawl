#pragma force_active on
extern char g_Network[];

extern "C" {
unsigned long long fn_800C9D44(void) {
    char* net = *(char**)(g_Network + 0x30);
    if (net != 0) {
        return *(unsigned long long*)(net + 0x3440);
    }
    return 0;
}
}
