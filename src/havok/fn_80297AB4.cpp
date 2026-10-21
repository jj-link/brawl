#pragma force_active on
typedef int s32;

extern "C" char* fn_80297AB4(void* arg0, char* arg1) {
    s32 n = *(s32*)((char*)arg0 + 4);
    char* t = arg1 + (((n * 4) - n) * 0x30);
    return t + (n * 0x90);
}
