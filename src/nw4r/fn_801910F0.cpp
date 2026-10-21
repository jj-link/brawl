#pragma force_active on
extern "C" void* fn_801910F0(void** arg0, void* arg1) {
    char* src = (char*)(*arg0);
    char* dst = (char*)arg1;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    *(int*)(dst + 4) = *(int*)(src + 4);
    return arg1;
}
