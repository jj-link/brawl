#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
extern "C" int fn_801E0720(void*);
extern "C" int fn_80355D0C(char*, char*);
extern "C" void fn_80151A0C(void*);
extern "C" void OSSleepTicks(s64);
extern "C" int OSResumeThread(void*);
struct FileIO {
    unsigned char pad[8];
    unsigned char thread[0x338];
    int state;
    unsigned char pad344[9];
    unsigned char disabled;
    unsigned char ready;
    unsigned char pad34F;
    int value;
    bool isSuspended() { return fn_801E0720(thread) == 1; }
    int isReady() { return state == 0 && isSuspended(); }
};
extern "C" int fn_801515B4(FileIO* p, int value, char* a, char* b) {
    if (p->disabled) return 1;
    if (value == 0) return 0;
    if (p->ready == 0) return 0;
    goto test;
sleep:
    OSSleepTicks((s64)15 * ((*(u32*)0x800000F8 / 4) / 1000));
test:
    if (!p->isReady()) goto sleep;
    if (fn_80355D0C(a, b) == 0) {
        fn_80151A0C(p);
        return 0;
    }
    p->value = value;
    p->state = 1;
    OSResumeThread(p->thread);
    return 1;
}