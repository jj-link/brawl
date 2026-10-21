#pragma force_active on
extern "C" void fn_801526D8(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    char* base = (char*)arg0;
    *(int*)(base + 0x64) = arg2;
    *(int*)(base + 0x68) = arg3;
    *(int*)(base + 0x6C) = arg4;
    *(int*)(base + 0x70) = arg5;
    *(int*)(base + 0x60) = *(int*)(base + arg1 * 4 + 0x64);
    *(int*)(base + 0x74) = arg6;
}
