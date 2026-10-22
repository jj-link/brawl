#pragma force_active on
extern "C" {
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int);
void* memset(void*, int, unsigned long);
}

extern "C" void fn_801CC9D8(unsigned int* p, unsigned int a, unsigned int b, unsigned int c) {
    if (c != 0) {
        int level = OSDisableInterrupts();
        p[0] = a;
        p[1] = b;
        p[2] = b / c;
        p[3] = c;
        p[4] = 0;
        memset((char*)p + 0x14, 0, 4);
        OSRestoreInterrupts(level);
    }
}
