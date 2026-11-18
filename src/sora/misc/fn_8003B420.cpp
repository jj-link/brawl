#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>
#include <string.h>
#pragma force_active on

extern "C" {
u8 fn_8004EAD4(void* a);
u64 fn_8014FC84(void);
u8 fn_8014F9A8(void);
int fn_800305FC(char* buf);
}
extern void* g_GameGlobal;
extern OSMutex* lbl_8059C6D4;
extern u16 lbl_805A00A8;
extern char lbl_8059C6DC[5];
extern char lbl_8059C708[2];
extern const char* lbl_80423560[];
extern const char* lbl_804235B8[];

struct Args {
    int unk0;
    int unk4;
    int index;
};

extern "C" s32 fn_8003B420(u8* self, Args* arg) {
    char path[0x40];
    char buf[0x40];
    int ok;

    if (!((fn_8004EAD4(g_GameGlobal) >> 3) & 1)) {
        return 0;
    }
    int result = 0;
    s64 t0 = (s64)fn_8014FC84();
    s64 t1 = OSGetTime();
    u64 h = fn_8014F9A8();
    u64 freq = *(u32*)0x800000F8 / 4;
    if (t0 + (s64)((s64)h * 3600LL * freq) < t1) {
        int idx = arg->index;
        strcpy(path, lbl_8059C6DC);
        strcat(path, lbl_80423560[idx]);
        strcat(path, lbl_8059C708);
        strcat(path, lbl_804235B8[arg->index]);
        OSLockMutex(lbl_8059C6D4);
        if (lbl_805A00A8 == 0 && (fn_800305FC(buf), ((gfFileIOHandle*)(self + 0x4C))->mountVF(0, buf))) {
            while (!((gfFileIOHandle*)(self + 0x4C))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x4C))->getReturnStatus() != 0) {
                OSUnlockMutex(lbl_8059C6D4);
                ok = 0;
            } else {
                goto vf_inc;
            }
        } else {
vf_inc:
            lbl_805A00A8 = lbl_805A00A8 + 1;
            OSUnlockMutex(lbl_8059C6D4);
            ok = 1;
        }
        if (ok != 0) {
            while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x44))->checkFileRequest(path)) {
                while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() == 0 && ((gfFileIOHandle*)(self + 0x44))->del(path)) {
                    while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() == 0) {
                        result = 1;
                    }
                }
            }
            OSLockMutex(lbl_8059C6D4);
            if (lbl_805A00A8 != 0) {
                lbl_805A00A8 = lbl_805A00A8 - 1;
                if (lbl_805A00A8 == 0 && ((gfFileIOHandle*)(self + 0x4C))->unmountVF(0)) {
                    while (!((gfFileIOHandle*)(self + 0x4C))->isReady()) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    ((gfFileIOHandle*)(self + 0x4C))->getReturnStatus();
                    lbl_805A00A8 = 0;
                }
            }
            OSUnlockMutex(lbl_8059C6D4);
        }
    }
    return result;
}
