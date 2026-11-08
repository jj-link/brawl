#include <types.h>
#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
void fn_8020D38C(char*);
s32 fn_8020B5A0(char*, char*);
s32 fn_8020B834(char*, char*);
unsigned int strlen(const char*);
char* strncpy(char*, const char*, unsigned int);
char* strcat(char*, const char*);
int strncmp(const char*, const char*, unsigned int);
extern char lbl_80494910[0x18];
extern char lbl_8059C57C[5];
extern char lbl_804215D8[];
extern char lbl_804215F8[];
struct Lock {
    void* mutex;
    bool locked : 8;
    Lock(void* m, bool l = true) { mutex = m; locked = l; if (locked) OSLockMutex(mutex); }
    void release() { if (locked) OSUnlockMutex(mutex); }
};
}
extern "C" int fn_800208E8(const char* name, int arg1) {
    if (name == 0 || arg1 == 0)
        return 0;
    char buf_name[0x80];
    char buf_path[0x80];
    char buf_tmp[0x80];
    Lock lock(lbl_80494910);
    char arg2[8];
    unsigned int len = strlen(name);
    const char* p = name;
    unsigned int i;
    for (i = 0; i < len; i++) {
        if (*p == ':') {
            strncpy(buf_name, p + 1, 0x80);
            goto copied;
        }
        p++;
    }
    strncpy(buf_name, name, 0x80);
copied:
    buf_path[0] = 0;
    if (strncmp(buf_name, lbl_8059C57C, 4) == 0) {
        strcat(buf_path, buf_name);
    } else {
        fn_8020D38C(buf_tmp);
        strncpy(buf_path, buf_tmp, 0x40);
        strcat(buf_path, buf_name);
    }
    int r = fn_8020B5A0(buf_path, arg2);
    if (r != 0) {
        OSReport(lbl_804215D8, r, buf_path);
        Lock* lp = &lock;
        lp->release();
        return 0;
    }
    arg2[7] = (char)arg1;
    r = fn_8020B834(buf_path, arg2);
    if (r != 0) {
        OSReport(lbl_804215F8, r, buf_path);
        Lock* lp = &lock;
        lp->release();
        return 0;
    }
    Lock* lp = &lock;
    lp->release();
    return 1;
}