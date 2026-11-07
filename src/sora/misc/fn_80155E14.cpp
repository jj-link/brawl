#pragma force_active on
extern "C" int OSIsThreadTerminated(void*);
extern "C" void OSResumeThread(void*);

extern "C" int fn_80155E14(void* self) {
    char* base = (char*)self;
    int t = (OSIsThreadTerminated(base + 8) - 1) == 0;
    if (t) {
        return 0;
    }
    if (*(int*)(base + 0x350) != 0x64) {
        return 0;
    }
    *(int*)(base + 0x350) = 1;
    OSResumeThread(base + 8);
    return 1;
}