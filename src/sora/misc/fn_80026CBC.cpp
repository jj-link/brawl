#include <types.h>
#pragma force_active on
extern "C" {
int isReady__14gfFileIOHandleCFv(const void*);
int getReturnStatus__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
u32 getSize__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void* create__8gfModuleFPvPvUl(void*, void*, u32);
void* fn_80026828(void*, void*, u32);
void free__13gfHeapManagerFPv(void*);
void fn_80026CBC(s32 arg0) {
    struct Loop { char* e; s32 i; } loop;
    loop.e = (char*)(arg0 + 8);
    loop.i = 0;
    do {
        u8 f = *(u8*)(loop.e + 0x19);
        if (((f >> 7) & 1) && !((f >> 4) & 1) && isReady__14gfFileIOHandleCFv(loop.e + 0x14) != 0 &&
            getReturnStatus__14gfFileIOHandleCFv(loop.e + 0x14) == 0) {
            *(u8*)(loop.e + 0x19) = *(u8*)(loop.e + 0x19) | 0x20;
            *(void**)(loop.e + 0x4) = getBuffer__14gfFileIOHandleCFv(loop.e + 0x14);
            *(u32*)(loop.e + 0x8) = getSize__14gfFileIOHandleCFv(loop.e + 0x14);
            if ((*(u8*)(loop.e + 0x19) >> 6) & 1) {
                void* b = *(void**)(loop.e + 0x4);
                if (*(s32*)(loop.e + 0xC) == 0) {
                    *(void**)loop.e = create__8gfModuleFPvPvUl(*(void**)(loop.e + 0x10), b, *(u32*)(loop.e + 0x8));
                    *(u8*)(loop.e + 0x19) = *(u8*)(loop.e + 0x19) | 0x4;
                } else {
                    *(void**)loop.e = fn_80026828(*(void**)(loop.e + 0xC), b, *(u32*)(loop.e + 0x8));
                    *(u8*)(loop.e + 0x19) = *(u8*)(loop.e + 0x19) & ~0x4;
                }
                {
                    u8* obj = *(u8**)loop.e;
                    if (!((obj[8] >> 7) & 1)) {
                        obj[8] = obj[8] | 0x80;
                        void** p3 = *(void***)obj;
                        typedef void* (*F)(void*);
                        ((F)p3[0x34 / 4])(p3);
                    }
                }
                free__13gfHeapManagerFPv(*(void**)(loop.e + 0x4));
                *(void**)(loop.e + 0x4) = 0;
            }
            release__14gfFileIOHandleFv(loop.e + 0x14);
            *(u8*)(loop.e + 0x19) = *(u8*)(loop.e + 0x19) | 0x10;
        }
        loop.i++;
        loop.e += 0x3C;
    } while (loop.i < 0x10);
}
}