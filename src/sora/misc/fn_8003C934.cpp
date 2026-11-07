#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>
#include <sr/sr_getappname.h>
#include <string.h>
#pragma force_active on

extern "C" {
int fn_800305FC(char*);
int fn_8003C4E4(void*, int, int, int);
}
extern OSMutex lbl_80497768;
extern OSMutex* lbl_8059C6D4;
extern OSMutex* lbl_8059C6D8;
extern u16 lbl_805A00A8;
extern u16 lbl_805A00AA;
extern char lbl_8059C6DC[5];
extern char lbl_8059C6E4[4];
extern char lbl_8059C708[2];
extern char lbl_80406920[];
extern const char* lbl_80423560[];

struct Args { int unk0; int mode; int index; char name[1]; };

extern "C" int fn_8003C934(u8* self, Args* arg) {
    char path[0x40];
    char buf[0x40];
    int result = 7;
    if (arg->mode == 0) {
        OSLockMutex(lbl_8059C6D4);
        int ok;
        if (lbl_805A00A8 == 0 && (fn_800305FC(buf), ((gfFileIOHandle*)(self + 0x4c))->mountVF(0, buf))) {
            while (!((gfFileIOHandle*)(self + 0x4c))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x4c))->getReturnStatus() != 0) {
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
        if (ok == 0) return 7;
        int index = arg->index;
        strcpy(path, lbl_8059C6DC);
        strcat(path, lbl_80423560[index]);
    } else {
        OSLockMutex(&lbl_80497768);
        OSLockMutex(lbl_8059C6D8);
        int ok;
        if (lbl_805A00AA == 0 && ((gfFileIOHandle*)(self + 0x48))->mountSD()) {
            while (!((gfFileIOHandle*)(self + 0x48))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x48))->getReturnStatus() != 0) {
                OSUnlockMutex(lbl_8059C6D8);
                ok = 0;
            } else {
                goto sd_inc;
            }
        } else {
sd_inc:
            lbl_805A00AA = lbl_805A00AA + 1;
            OSUnlockMutex(lbl_8059C6D8);
            ok = 1;
        }
        if (ok == 0) {
            OSUnlockMutex(&lbl_80497768);
            return 7;
        }
        int index = arg->index;
        strcpy(path, lbl_8059C6E4);
        strcat(path, lbl_80406920);
        strcat(path, srGetAppGamename());
        strcat(path, lbl_80423560[index]);
    }
    strcat(path, lbl_8059C708);
    strcat(path, arg->name);
    if (((gfFileIOHandle*)(self + 0x44))->del(path)) {
        while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
            OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
        }
        if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() == 0) {
            result = 0;
            fn_8003C4E4(self, 0, 0, 1);
        }
    }
    if (arg->mode == 0) {
        OSLockMutex(lbl_8059C6D4);
        if (lbl_805A00A8 != 0) {
            lbl_805A00A8 = lbl_805A00A8 - 1;
            if (lbl_805A00A8 == 0 && ((gfFileIOHandle*)(self + 0x4c))->unmountVF(0)) {
                while (!((gfFileIOHandle*)(self + 0x4c))->isReady()) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                ((gfFileIOHandle*)(self + 0x4c))->getReturnStatus();
                lbl_805A00A8 = 0;
            }
        }
        OSUnlockMutex(lbl_8059C6D4);
    } else {
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
        OSUnlockMutex(&lbl_80497768);
    }
    return result;
}
