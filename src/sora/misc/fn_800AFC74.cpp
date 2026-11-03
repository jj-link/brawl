#include <types.h>
#pragma force_active on

extern "C" {

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int heapType);
void* fn_801AC370(void* allocator, void* out, s32 a, s32 b, s32 c, s32 d);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void read__14gfFileIOHandleFPCcQ25Heaps8HeapTypei(void* self, const char* path, int heap, int offset);
void release__14gfFileIOHandleFv(void* self);
void fn_800AFF00(void* self);
void fn_800B00B0(void* self, void* handle);
char* strcpy(char* dst, const char* src);
char* strcat(char* dst, const char* src);
s32 strlen(const char* s);

extern void* g_GameGlobal;
extern char lbl_80455C9C[];
extern char lbl_80455C90[];

void* fn_800AFC74(void* self, const char* name, s32 arg2, const char* arg3, s32 arg4) {
    u8* s = (u8*)self;
    char buf[0x40];
    void* sp8;
    const char* path;
    s32 i;
    u8* p;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, name, 8, 0xF, 8, true);
    *(s32*)(s + 0x40) = 0;
    *(char**)(s + 0x3C) = lbl_80455C9C;
    *(s32*)(s + 0x44) = 0;
    *(s32*)(s + 0x48) = 0;
    *(s32*)(s + 0x4C) = 0;
    *(s32*)(s + 0x50) = 0;
    *(s32*)(s + 0x54) = 0;
    s[0x1A4] = 0;
    *(s32*)(s + 0x1A8) = 0;
    *(void**)(s + 0x48) = fn_801AC370(getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A), &sp8, arg2, arg2, 0x80, 0x80);
    *(const char**)(s + 0x0) = name;
    s[0x2C] &= 0xFFFFFFFD;
    if (arg3 != 0) {
        path = arg3;
        if (((*((u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28)) >> 7) & 1) {
            strcpy(buf, arg3);
            i = strlen(buf) - 1;
            p = (u8*)buf + i;
            for (; i >= 0; p--, i--) {
                if (*p == '.') {
                    break;
                }
            }
            buf[i] = 0;
            strcat(buf, lbl_80455C90);
            path = buf;
        }
        read__14gfFileIOHandleFPCcQ25Heaps8HeapTypei(s + 0x1A8, path, arg4, 0);
        fn_800B00B0(self, s + 0x1A8);
        s[0x1A4] = 1;
        release__14gfFileIOHandleFv(s + 0x1A8);
    }
    fn_800AFF00(self);
    return self;
}

}
