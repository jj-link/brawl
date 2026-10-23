#pragma force_active on
typedef int s32;

extern "C" void* fn_802DB6E4(void* arg0, char* arg1) {
    s32 n = *(s32*)((char*)arg0 + 0x1C);
    char* base = arg1 + ((n * 6) << 3);
    return (char*)((s32)base + ((n + 3) & ~3));
}
