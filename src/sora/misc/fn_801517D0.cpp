#pragma force_active on

typedef unsigned int u32;
typedef long long s64;

extern "C" int fn_801E0720(void*);
extern "C" int fn_803560A4(int, int, int);
extern "C" void fn_80151A0C(void*);
extern "C" void netReport__FPCce(const char*, ...);
extern "C" char lbl_80461304[];
extern "C" void OSSleepTicks(s64);
extern "C" int OSResumeThread(void*);

struct FileIO {
    unsigned char pad[8];
    unsigned char thread[0x338];
    int state;
    int f344;
    int f348;
    unsigned char pad34C;
    unsigned char pad34D;
    unsigned char ready;
    unsigned char pad34F;
    int value;

    bool isSuspended() {
        return fn_801E0720(thread) == 1;
    }

    int isReady() {
        return state == 0 && isSuspended();
    }
};

extern "C" int fn_801517D0(FileIO* p, int value, int a, int b, int c) {
    if (value == 0) return 0;
    if (p->ready == 0) return 0;

    goto test;
sleep:
    OSSleepTicks((s64)15 * ((*(u32*)0x800000F8 / 4) / 1000));
test:
    if (!p->isReady()) goto sleep;

    if (fn_803560A4(a, b, c) == 0) {
        netReport__FPCce(lbl_80461304);
        fn_80151A0C(p);
        return 0;
    }

    p->pad34C = 0;
    p->value = value;
    p->state = 3;
    p->f344 = 0;
    p->f348 = 0;
    OSResumeThread(p->thread);
    return 1;
}
