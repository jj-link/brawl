#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <sr/sr_getappname.h>
#include <string.h>
#pragma force_active on

extern "C" {
int fn_800305FC(char*);
void* fn_8003CFD0(void*);
int fn_8003D154(void*, void*, unsigned int, int);
void* fn_8003D054(void*, int);
void fn_80153488(void*);
void fn_80153498(void*, int);
int fn_80153504(void*, void*);
int fn_80153CF4(void*);
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

extern "C" int fn_8003AD48(u8* self, Args* arg) {
    char path[0x40];
    char buf[0x40];
    char thread[0x380];
    char sp8[8];
    int result = 4;
    bool locked;
    int vf;
    int sd;

    *(int*)(self + 0xEC) = 0;
    locked = arg->mode != 0;
    if (locked) OSLockMutex(&lbl_80497768);
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
        int index = arg->index;
        strcpy(path, lbl_8059C6DC);
        strcat(path, lbl_80423560[index]);
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
        int index = arg->index;
        strcpy(path, lbl_8059C6E4);
        strcat(path, lbl_80406920);
        strcat(path, srGetAppGamename());
        strcat(path, lbl_80423560[index]);
    }
    strcat(path, lbl_8059C708);
    strcat(path, arg->name);

    if (((gfFileIOHandle*)(self + 0x44))->checkFileRequest(path)) {
        while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
            OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
        }
        if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() != 0) {
            *(void**)(self + 0xE4) = 0;
            *(int*)(self + 0xE8) = 0;
            goto cleanup;
        }
        if ((u32)((gfFileIOHandle*)(self + 0x44))->getSize() > 0x64000) {
            *(void**)(self + 0xE4) = 0;
            *(int*)(self + 0xE8) = 0;
            goto cleanup;
        }
        if (((gfFileIOHandle*)(self + 0x44))->readRequest(path, *(Heaps::HeapType*)(self + 0x50), 0, 0)) {
            while (!((gfFileIOHandle*)(self + 0x44))->isReady()) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            if (((gfFileIOHandle*)(self + 0x44))->getReturnStatus() != 0) {
                *(void**)(self + 0xE4) = 0;
                *(int*)(self + 0xE8) = 0;
                goto cleanup;
            }
            if (arg->mode == 0) {
                *(void**)(self + 0xE4) = ((gfFileIOHandle*)(self + 0x44))->getBuffer();
                *(int*)(self + 0xE8) = ((gfFileIOHandle*)(self + 0x44))->getSize();
                goto block_48;
            }
            fn_8003CFD0(thread);
            {
                unsigned int size = ((gfFileIOHandle*)(self + 0x44))->getSize();
                if (fn_8003D154(thread, ((gfFileIOHandle*)(self + 0x44))->getBuffer(), size, *(int*)(self + 0x50)) != 0) {
                    while (*(u8*)(thread + 0x360) == 0) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    if (*(int*)(thread + 0x364) != 0) {
                        gfHeapManager::free(((gfFileIOHandle*)(self + 0x44))->getBuffer());
                        *(void**)(self + 0xE4) = 0;
                        *(int*)(self + 0xE8) = 0;
                        fn_8003D054(thread, -1);
                        goto cleanup;
                    }
                    gfHeapManager::free(((gfFileIOHandle*)(self + 0x44))->getBuffer());
                    *(void**)(self + 0xE4) = *(void**)(thread + 0x368);
                    *(int*)(self + 0xE8) = *(int*)(thread + 0x36C);
                    goto thread_done;
                }
                gfHeapManager::free(((gfFileIOHandle*)(self + 0x44))->getBuffer());
                *(void**)(self + 0xE4) = 0;
                *(int*)(self + 0xE8) = 0;
                fn_8003D054(thread, -1);
                goto cleanup;
            }
        }
        goto cleanup;
    }
    goto cleanup;

thread_done:
    fn_8003D054(thread, -1);
block_48:
    fn_80153488(sp8);
    if (fn_80153504(sp8, *(void**)(self + 0xE4)) == 0) {
        if (*(void**)(self + 0xE4) != 0) {
            gfHeapManager::free(*(void**)(self + 0xE4));
        }
        *(void**)(self + 0xE4) = 0;
        result = 6;
        *(int*)(self + 0xE8) = 0;
        fn_80153498(sp8, -1);
    } else {
        int kind = 0;
        switch (fn_80153CF4(sp8)) {
        case 1:
            kind = 1;
            break;
        case 2:
            kind = 2;
            break;
        case 3:
            kind = 3;
            break;
        }
        if (kind == 0 || arg->index != kind) {
            if (*(void**)(self + 0xE4) != 0) {
                gfHeapManager::free(*(void**)(self + 0xE4));
            }
            *(void**)(self + 0xE4) = 0;
            result = 6;
            *(int*)(self + 0xE8) = 0;
            fn_80153498(sp8, -1);
        } else {
            fn_80153498(sp8, -1);
            switch (arg->index) {
            case 1:
                *(int*)(self + 0xEC) = 1;
                break;
            case 2:
                *(int*)(self + 0xEC) = 2;
                break;
            case 3:
                *(int*)(self + 0xEC) = 3;
                break;
            }
            result = 0;
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
