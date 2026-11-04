#include <gf/gf_file_io.h>
#include <revolution/FA.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" {
int fn_803EBE4C(void);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern OSMutex lbl_80494910;
extern char lbl_8059C598[4];
}

struct Lock {
    OSMutex* mutex;
    bool locked : 8;
    Lock(OSMutex* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked) OSLockMutex(mutex);
    }
    void release() {
        if (locked) OSUnlockMutex(mutex);
    }
};

int gfFileIO::checkFileSD(gfFileIORequest* request) {
    Lock lock(&lbl_80494910);
    FAStat st;
    char path[0x80];
    char* name = request->m_pFilepath;
    int result = 0x11;

    request->m_readLen = 0;
    strcpy(path, lbl_8059C598);
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);
    if (FAFstat(path, &st) != 0) {
        if (fn_803EBE4C() != 2) {
            fn_803EBE4C();
        }
    } else {
        result = 0;
        request->m_readLen = st.filesize;
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
