#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" {
char* fn_801CC2E4();
void fn_801CC7B0(void* self, void* node);
void* fn_801CFA14(void);
void fn_801CFB8C(char* a, char* b, int c);

int fn_801CD5E8(void* self, void* a1, void* a2, void* a3, void* a4) {
    char* s = (char*)self;
    char* node;
    char* task;
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    *(void**)(s + 0x7BC) = a1;
    *(void**)(s + 0x7C8) = a2;
    *(void**)(s + 0x100) = a3;
    *(void**)(s + 0x104) = a4;
    s[0xBC] = 0;
    s[0xBD] = 0;
    s[0xBE] = 0;
    s[0xB9] = 1;
    node = s;
    if (self != 0) {
        node = s + 0x74;
    }
    fn_801CC7B0(fn_801CC2E4(), node);
    task = s + 0x108;
    *(void**)(task + 0x10) = self;
    *(void**)(task + 0x14) = *(void**)(s + 0x7BC);
    *(void**)(task + 0x18) = *(void**)(s + 0x100);
    *(void**)(task + 0x1C) = *(void**)(s + 0x104);
    fn_801CFB8C((char*)fn_801CFA14(), task, 1);
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    return 1;
}
}