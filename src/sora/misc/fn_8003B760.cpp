#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <sr/sr_getappname.h>
#include <string.h>
#pragma force_active on

extern "C" {
void fn_8003B420(void*);
int fn_800305FC(char*);
}
extern OSMutex lbl_80497768;
extern OSMutex* lbl_8059C6D4;
extern OSMutex* lbl_8059C6D8;
extern u16 lbl_805A00A8;
extern u16 lbl_805A00AA;
extern char lbl_8059C6DC[5];
extern char lbl_8059C6E4[4];
extern char lbl_80406920[];
extern const char* lbl_80423560[];
extern const char* lbl_80423680[];

struct Args { int unk0; int mode; int index; };

extern "C" int fn_8003B760(u8* self, Args* arg) {
    char path[0x40];
    char buf[0x40];
    int result = 4;
    fn_8003B420(self);
    bool locked = arg->mode != 0;
    if (locked) OSLockMutex(&lbl_80497768);
    int vf = 0;
    int sd = 0;
    if (arg->mode == 0) {
        OSLockMutex(lbl_8059C6D4);
        if (lbl_805A00A8 == 0 && (fn_800305FC(buf), ((gfFileIOHandle*)(self + 0x4c))->mountVF(0, buf))) {
            while (!((gfFileIOHandle*)(self + 0x4c))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x4c))->getReturnStatus() != 0) {
                OSUnlockMutex(lbl_8059C6D4);
                vf = 0;
            } else {
                goto vf_inc;
            }
        } else {
vf_inc:
            lbl_805A00A8 = lbl_805A00A8 + 1;
            OSUnlockMutex(lbl_8059C6D4);
            vf = 1;
        }
        if (lbl_805A00A8 == 0) goto cleanup;
    } else {
        OSLockMutex(lbl_8059C6D8);
        if (lbl_805A00AA == 0 && ((gfFileIOHandle*)(self + 0x48))->mountSD()) {
            while (!((gfFileIOHandle*)(self + 0x48))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x48))->getReturnStatus() != 0) {
                OSUnlockMutex(lbl_8059C6D8);
                sd = 0;
            } else {
                goto sd_inc;
            }
        } else {
sd_inc:
            lbl_805A00AA = lbl_805A00AA + 1;
            OSUnlockMutex(lbl_8059C6D8);
            sd = 1;
        }
        if (lbl_805A00AA == 0) goto cleanup;
    }
    {
        int index = arg->index;
        if (arg->mode == 0) {
            strcpy(path, lbl_8059C6DC);
            strcat(path, lbl_80423560[index]);
        } else {
            strcpy(path, lbl_8059C6E4);
            strcat(path, lbl_80406920);
            strcat(path, srGetAppGamename());
            strcat(path, lbl_80423560[index]);
        }
        strcat(path, lbl_80423680[index]);
        if (!((gfFileIOHandle*)(self + 0x44))->findfirstRequest(path, *(HeapType*)(self + 0x50))) {
            *(void**)(self + 0xe4) = 0;
            *(int*)(self + 0xe8) = 0;
        } else {
            while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            switch (((gfFileIOHandle*)(self + 0x44))->getReturnStatus()) {
            case 0:
                *(void**)(self + 0xe4) = ((gfFileIOHandle*)(self + 0x44))->getBuffer();
                *(int*)(self + 0xe8) = ((gfFileIOHandle*)(self + 0x44))->getSize();
                break;
            case 17:
                *(void**)(self + 0xe4) = 0;
                *(int*)(self + 0xe8) = 0;
                break;
            default:
                *(void**)(self + 0xe4) = 0;
                *(int*)(self + 0xe8) = 0;
                goto failed;
            }
            result = 0;
            *(int*)(self + 0xec) = 7;
failed:
            if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() != 0 &&
                ((gfFileIOHandle*)(self + 0x44))->getBuffer() != 0) {
                gfHeapManager::free(((gfFileIOHandle*)(self + 0x44))->getBuffer());
            }
        }
    }
cleanup:
    if (vf != 0) {
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
    }
    if (sd != 0) {
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
    }
    if (locked) OSUnlockMutex(&lbl_80497768);
    return result;
}