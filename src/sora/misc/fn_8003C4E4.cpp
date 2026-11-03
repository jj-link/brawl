#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

extern "C" {
u8 fn_8004EAD4(void* a);
int fn_800305FC(char* buf);
int fn_8001BCFC(void);
int fn_8001BCBC(void);
}

extern void* g_GameGlobal;
extern OSMutex* lbl_8059C6D4;
extern OSMutex* lbl_8059C6D8;
extern OSMutex lbl_80497768;
extern u16 lbl_805A00A8;
extern u16 lbl_805A00AA;
extern char lbl_8059C714;
extern char lbl_8059C71C;

struct FileState {
    u8 unk0;
    u8 pad1[3];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};
extern FileState lbl_80423690;

extern "C" s32 fn_8003C4E4(u8* self, void* unused, gfFileIOHandle* arg2, u32 mode) {
    char buf[0x40];
    s32 size;
    s32 state;

    size = 0;
    state = 1;
    if (arg2 == 0) {
        arg2 = (gfFileIOHandle*)(self + 0x44);
    }
    if ((fn_8004EAD4(g_GameGlobal) >> 3) & 1) {
        if (lbl_80423690.unkC == 0 || mode == 1) {
            s32 ok;
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
                if (arg2->checkFreeSize(&lbl_8059C714)) {
                    while (!arg2->isReady()) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    if (arg2->getReturnStatus() == 0) {
                        lbl_80423690.unkC = arg2->getSize();
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
    } else {
        lbl_80423690.unkC = 0;
    }
    if (fn_8001BCFC() != 0) {
        if (lbl_80423690.unk4 != (state = 0) || mode == 1) {
            s32 ok2;
            OSLockMutex(&lbl_80497768);
            OSLockMutex(lbl_8059C6D8);
            if (lbl_805A00AA == 0 && ((gfFileIOHandle*)(self + 0x48))->mountSD()) {
                while (!((gfFileIOHandle*)(self + 0x48))->isReady()) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                if (((gfFileIOHandle*)(self + 0x48))->getReturnStatus() != 0) {
                    OSUnlockMutex(lbl_8059C6D8);
                    ok2 = 0;
                } else {
                    goto sd_inc;
                }
            } else {
sd_inc:
                lbl_805A00AA = lbl_805A00AA + 1;
                OSUnlockMutex(lbl_8059C6D8);
                ok2 = 1;
            }
            if (ok2 != 0) {
                if (fn_8001BCBC() != 0) {
                    state = 2;
                }
                if (arg2->checkFreeSize(&lbl_8059C71C)) {
                    while (!arg2->isReady()) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    if (arg2->getReturnStatus() == 0) {
                        size = arg2->getSize();
                    }
                }
                OSLockMutex(lbl_8059C6D8);
                if (lbl_805A00AA != 0) {
                    lbl_805A00AA = lbl_805A00AA - 1;
                    if (lbl_805A00AA == 0 && ((gfFileIOHandle*)(self + 0x48))->unmountSD()) {
                        while (!((gfFileIOHandle*)(self + 0x48))->isReady()) {
                            OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                        }
                        ((gfFileIOHandle*)(self + 0x48))->getReturnStatus();
                        lbl_805A00AA = 0;
                    }
                }
                OSUnlockMutex(lbl_8059C6D8);
            } else {
                state = 3;
            }
            OSUnlockMutex(&lbl_80497768);
        }
    }
    if (lbl_80423690.unk4 != state || mode == 1) {
        lbl_80423690.unk8 = size;
        lbl_80423690.unk4 = state;
    }
    lbl_80423690.unk0 = 1;
    return 0;
}
