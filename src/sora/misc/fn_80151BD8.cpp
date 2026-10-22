#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
int fn_80358890(int, int, int, int, int);
extern char lbl_8049ED08[0x18];
extern char lbl_8059E7F8[2];
extern char lbl_804613FC[0xD4];
}
struct Object {
    char padding[0x48];
    unsigned char initialized;
    unsigned char active;
};
struct Guard {
    void* mutex;
    unsigned char flag : 8;
};
extern "C" int fn_80151BD8(Object* self, int a, int b, int c, int d) {
    if (self->initialized) return 1;
    Guard g;
    Guard* p = &g;
    p->flag = 1;
    p->mutex = lbl_8049ED08;
    if (p->flag != 0) OSLockMutex(lbl_8049ED08);
    if (fn_80358890(b, 0x67A, c, a, d)) {
        if (p->flag != 0) OSUnlockMutex(p->mutex);
        return 0;
    }
    self->active = 1;
    if (p->flag != 0) OSUnlockMutex(p->mutex);
    OSReport(lbl_8059E7F8);
    OSReport(lbl_804613FC);
    OSReport(lbl_8059E7F8);
    self->initialized = 1;
    return 1;
}
