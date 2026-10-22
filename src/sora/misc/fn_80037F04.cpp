#pragma force_active on
extern "C" {
    void OSResumeThread(void*);

    int fn_80037F04(char* arg0, unsigned long arg1, unsigned long arg2, unsigned long arg3) {
        if (*(unsigned char*)(arg0 + 0x370) != 0) {
            return 0;
        }
        if (arg1 == 0) {
            return 0;
        }
        if (arg1 & 0x1F) {
            return 0;
        }
        *(unsigned long*)(arg0 + 0x360) = arg1;
        *(unsigned long*)(arg0 + 0x364) = arg2;
        *(unsigned long*)(arg0 + 0x368) = arg3;
        *(unsigned long*)(arg0 + 0x36C) = 1;
        OSResumeThread(arg0 + 8);
        return 1;
    }
}
