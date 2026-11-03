#include <types.h>
#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" char* fn_801CC2E4();
extern "C" void fn_801CC818(void*, void*);
extern "C" char* fn_801BE7BC();
extern "C" void fn_801BE8D0(void*, void*);
extern "C" void fn_801D4AA8(void*);
extern "C" void fn_801BE2D4(void*);
extern "C" void fn_801BE7A4(void*);

extern "C" void fn_801D44E0(void* self, u32 arg1, u32 arg2) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    if (*(u8*)((char*)self + 0x8c) != 0) {
        u32 val = *(u32*)((char*)self + 0xa8);
        if (arg1 <= val && val <= arg2) {
            OSLockMutex(fn_801CC2E4() + 0x354);
            if (*(u8*)((char*)self + 0x8d) != 0) {
                void* ptr = self;
                if (self != NULL) {
                    ptr = (void*)((char*)self + 0x80);
                }
                fn_801CC818(fn_801CC2E4(), ptr);
                *(u8*)((char*)self + 0x8d) = 0;
            }
            if (*(u8*)((char*)self + 0x8c) != 0) {
                void* ptr = self;
                if (self != NULL) {
                    ptr = (void*)((char*)self + 0x74);
                }
                fn_801BE8D0(fn_801BE7BC(), ptr);
                *(u8*)((char*)self + 0x8c) = 0;
            }
            OSLockMutex(fn_801CC2E4() + 0x354);
            void* d4 = *(void**)((char*)self + 0xd4);
            s32 flag = 0;
            if (d4 != NULL && *(u8*)((char*)d4 + 0x32) != 0) {
                flag = 1;
            }
            if (flag != 0) {
                fn_801D4AA8(self);
                fn_801BE2D4(*(void**)((char*)self + 0xd4));
            }
            if (*(void**)((char*)self + 0xd4) != NULL) {
                fn_801BE7A4(*(void**)((char*)self + 0xd4));
            }
            *(void**)((char*)self + 0xd4) = NULL;
            OSUnlockMutex(fn_801CC2E4() + 0x354);
            OSUnlockMutex(fn_801CC2E4() + 0x354);
        }
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}