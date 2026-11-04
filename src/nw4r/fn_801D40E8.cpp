#include <types.h>
#pragma force_active on

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
char* fn_801CC2E4();
void fn_801CC818(void*, void*);
void* fn_801BE7BC();
void fn_801BE8D0(void*, void*);
void fn_801BE8A0(void*, void*);
void fn_801D4AA8(void*);
void fn_801BE2D4(void*);
void fn_801BE7A4(void*);
void fn_801D4040(void*, int, int, int);
}

extern "C" int fn_801D40E8(void* self, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    OSLockMutex((void*)((char*)fn_801CC2E4() + 0x354));
    if (*(u8*)((char*)self + 0x8c) != 0) {
        OSLockMutex((void*)((char*)fn_801CC2E4() + 0x354));
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
        OSLockMutex((void*)((char*)fn_801CC2E4() + 0x354));
        void* d4 = *(void**)((char*)self + 0xd4);
        int flag = 0;
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
        OSUnlockMutex((void*)((char*)fn_801CC2E4() + 0x354));
        OSUnlockMutex((void*)((char*)fn_801CC2E4() + 0x354));
    }
    fn_801D4040(self, arg5, arg6, arg7);
    *(int*)((char*)self + 0xa8) = arg1;
    void* ptr = self;
    *(int*)((char*)self + 0xac) = arg2;
    *(int*)((char*)self + 0xb0) = arg3;
    *(int*)((char*)self + 0xb4) = arg4;
    if (self != NULL) {
        ptr = (void*)((char*)self + 0x74);
    }
    fn_801BE8A0(fn_801BE7BC(), ptr);
    *(u8*)((char*)self + 0x8c) = 1;
    OSUnlockMutex((void*)((char*)fn_801CC2E4() + 0x354));
    return 1;
}
