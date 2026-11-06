#pragma force_active on
#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#include <gf/gf_file_io_handle.h>

extern "C" {
extern char lbl_80423738[];
extern void* lbl_80497780[10];
void fn_8014CD7C(void*, int);
void __dt__8gfThreadFv(void*, short);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern OSMutex* lbl_8059C6D4;
extern OSMutex* lbl_8059C6D8;
extern u16 lbl_805A00A8;
extern u16 lbl_805A00AA;

inline bool terminated(void* thread) {
    return OSIsThreadTerminated((OSThread*)((u8*)thread + 8)) == 1;
}

extern "C" void* fn_80038AC8(u8* self, int flag) {
    if (self != 0) {
        *(char**)self = lbl_80423738;
        *(char**)(self + 0x40) = lbl_80423738 + 0xC;
        for (int i = 0; i < 10; i++) {
            if (lbl_80497780[i] == self) {
                lbl_80497780[i] = 0;
                break;
            }
        }
        if (*(void**)(self + 0x188) != 0) {
            while (!terminated(*(void**)(self + 0x188))) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            void* t = *(void**)(self + 0x188);
            if (t != 0) {
                __dt__8gfThreadFv(t, 0);
                __dl__FPv(t);
            }
            *(void**)(self + 0x188) = 0;
        }
        if (*(void**)(self + 0x58) != 0) {
            while (!terminated(*(void**)(self + 0x58))) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            __dt__8gfThreadFv(*(void**)(self + 0x58), 1);
            *(void**)(self + 0x58) = 0;
        }
        if (*(void**)(self + 0x54) != 0) {
            fn_8014CD7C(*(void**)(self + 0x54), 1);
            *(void**)(self + 0x54) = 0;
        }
        OSLockMutex(lbl_8059C6D4);
        if (lbl_805A00A8 != 0) {
            lbl_805A00A8 = lbl_805A00A8 - 1;
            if (((gfFileIOHandle*)(self + 0x4c))->unmountVF(0)) {
                while (!((gfFileIOHandle*)(self + 0x4c))->isReady()) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                ((gfFileIOHandle*)(self + 0x4c))->getReturnStatus();
                lbl_805A00A8 = 0;
            }
        }
        OSUnlockMutex(lbl_8059C6D4);
        OSLockMutex(lbl_8059C6D8);
        if (lbl_805A00AA != 0) {
            lbl_805A00AA = lbl_805A00AA - 1;
            if (((gfFileIOHandle*)(self + 0x48))->unmountSD()) {
                while (!((gfFileIOHandle*)(self + 0x48))->isReady()) {
                    OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                }
                ((gfFileIOHandle*)(self + 0x48))->getReturnStatus();
                lbl_805A00AA = 0;
            }
        }
        OSUnlockMutex(lbl_8059C6D8);
        __dt__14gfFileIOHandleFv(self + 0x4c, -1);
        __dt__14gfFileIOHandleFv(self + 0x48, -1);
        __dt__14gfFileIOHandleFv(self + 0x44, -1);
        __dt__6gfTaskFv(self + 4, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
