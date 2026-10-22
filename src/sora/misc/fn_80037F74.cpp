#pragma force_active on
extern "C" {
    void OSResumeThread(void*);

    int fn_80037F74(void* arg0, unsigned int arg1, unsigned int arg2, int arg3) {
        if (*(unsigned char*)((char*)arg0 + 0x370) != 0) {
            return 0;
        }
        if (arg1 == 0) {
            return 0;
        }
        if (arg2 < 0x10 || (arg2 & 0x0F) != 0) {
            return 0;
        }
        if (arg1 & 0x1F) {
            return 0;
        }
        *(int*)((char*)arg0 + 0x360) = arg1;
        *(int*)((char*)arg0 + 0x364) = arg2;
        *(int*)((char*)arg0 + 0x368) = arg3;
        *(int*)((char*)arg0 + 0x36C) = 2;
        OSResumeThread((char*)arg0 + 8);
        return 1;
    }
}
