#pragma force_active on
extern "C" {
void OSResumeThread(void*);
int fn_8003D0F4(void* arg0, unsigned int arg1, unsigned int arg2, int arg3) {
    if (*(unsigned char*)((char*)arg0 + 0x360) != 0) {
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    *(int*)((char*)arg0 + 0x350) = arg1;
    *(int*)((char*)arg0 + 0x354) = arg2;
    *(int*)((char*)arg0 + 0x358) = arg3;
    *(int*)((char*)arg0 + 0x35C) = 1;
    OSResumeThread((char*)arg0 + 8);
    return 1;
}
}