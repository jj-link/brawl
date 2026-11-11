#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>
#include <sr/sr_getappname.h>
#include <string.h>
#pragma force_active on

extern "C" {
int fn_800305FC(char*);
void fn_8003CFD0(void*);
int fn_8003D0F4(void*, unsigned int, unsigned int, int);
void fn_8003D054(void*, int);
int fn_8003C4E4(void*, int, int, int);
int sprintf(char*, const char*, ...);
}
extern OSMutex lbl_80497768;
extern OSMutex* lbl_8059C6D4;
extern OSMutex* lbl_8059C6D8;
extern u16 lbl_805A00A8;
extern u16 lbl_805A00AA;
extern char lbl_8059C6DC[5];
extern char lbl_8059C6E4[4];
extern char lbl_8059C700[6];
extern char lbl_80406920[];
extern const char* lbl_80423560[];

struct Args {
    int unk0;
    int mode;
    int index;
    char name[0x80];
    void* data;
    int length;
    u8 flag;
};

extern "C" int fn_8003A6F0(u8* self, Args* arg) {
    int result = 3;
    u32 locked = (u32)(-arg->mode | arg->mode) >> 31;
    int vf;
    int sd;
    char path[0x20];
    char buf2[0x40];
    char buf[0x40];
    char thread[0x371];

    if (locked != 0) OSLockMutex(&lbl_80497768);
    vf = 0;
    sd = 0;
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
        {
            int index = arg->index;
            strcpy(path, lbl_8059C6DC);
            strcat(path, lbl_80423560[index]);
        }
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
        {
            int index = arg->index;
            strcpy(path, lbl_8059C6E4);
            strcat(path, lbl_80406920);
            strcat(path, srGetAppGamename());
            strcat(path, lbl_80423560[index]);
        }
    }
    if (!((gfFileIOHandle*)(self + 0x44))->checkDirRequest(path)) {
        result = 3;
    } else {
        while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
            OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
        }
        if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() == 0x12) {
            if (((gfFileIOHandle*)(self + 0x44))->createDirRequest(path)) {
                while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() != 0) goto cleanup;
            } else {
                goto cleanup;
            }
        }
        sprintf(buf2, lbl_8059C700, path, arg->name);
        if (arg->flag != 0 && ((gfFileIOHandle*)(self + 0x44))->checkFileRequest(buf2)) {
            while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() == 0) {
                if (((gfFileIOHandle*)(self + 0x44))->del(buf2)) {
                    while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() != 0) goto cleanup;
                } else {
                    goto cleanup;
                }
            }
        }
        if (arg->mode == 0) {
            if (((gfFileIOHandle*)(self + 0x44))->writeRequest(buf2, arg->data, arg->length, 0)) {
                goto final_loop;
            } else {
                goto cleanup;
            }
        } else {
            fn_8003CFD0(thread);
            *(u8*)(thread + 0x370) = 1;
            if (fn_8003D0F4(thread, (unsigned int)arg->data, (unsigned int)arg->length, *(int*)(self + 0x50)) != 0) {
                while (*(u8*)(thread + 0x360) == 0) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                if (*(int*)(thread + 0x364) != 0) {
                    fn_8003D054(thread, -1);
                    goto cleanup;
                }
                if (((gfFileIOHandle*)(self + 0x44))->writeRequest(buf2, *(void**)(thread + 0x368), *(int*)(thread + 0x36c), 0) == 0) {
                    fn_8003D054(thread, -1);
                    goto cleanup;
                } else {
                    goto d054_c;
                }
            } else {
                fn_8003D054(thread, -1);
                goto cleanup;
            }
d054_c:
            fn_8003D054(thread, -1);
        }
final_loop:
        while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
            OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
        }
        if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() == 0) {
            result = 0;
            fn_8003C4E4(self, 0, 0, 1);
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
    if (locked != 0) OSUnlockMutex(&lbl_80497768);
    return result;
}