#include <revolution/OS/OSCache.h>
#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_804C1A80[0x100];
void fn_801FFF54(int*, int*);
void fn_801FFF68(int*, int*);
void fn_801FFF7C(int*, int*);
void fn_801FFE28(int, int);
void fn_801FFE8C(int, int);
void fn_801FFEF0(int, int);
void fn_801B8034();
int fn_802010D8(void (*)());
}

struct Obj {
    char pad0[4];
    void* buffer;
    char pad8[0xc];
    int callback;
    unsigned char initialized;
    char pad19[0xbf];
    int a, b, c, d, e, f;
};

extern "C" void fn_801B78D4(Obj* self) {
    if (self->initialized == 0) {
        memset(lbl_804C1A80, 0, 0x100);
        DCFlushRange(lbl_804C1A80, 0x100);
        self->buffer = lbl_804C1A80;
        BOOL enabled = OSDisableInterrupts();
        fn_801FFF54(&self->a, &self->d);
        fn_801FFF68(&self->b, &self->e);
        fn_801FFF7C(&self->c, &self->f);
        fn_801FFE28(0, 0);
        fn_801FFE8C(0, 0);
        fn_801FFEF0(0, 0);
        self->callback = fn_802010D8(fn_801B8034);
        self->initialized = 1;
        OSRestoreInterrupts(enabled);
    }
}