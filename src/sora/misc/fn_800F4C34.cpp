#include <gf/gf_task.h>
#include <types.h>
#include <string.h>
#pragma force_active on
extern "C" {
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
extern char lbl_8045BDF0[];
extern const f32 lbl_805A2610;
extern const f32 lbl_805A2614;
}
inline void clearWords(int* p, int* e) {
    do { *p = 0; ++p; } while (p < e);
}
extern "C" void* fn_800F4C34(void* self, const char* name, int a, int b, int c) {
    char* s = (char*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib((gfTask*)self, name, gfTask::Category_Info, 14, 6, true);
    *(int*)(s + 0x40) = a;
    *(char**)(s + 0x3c) = lbl_8045BDF0;
    clearWords((int*)(s + 0x44), (int*)(s + 0x84));
    *(int*)(s + 0x84) = 0;
    *(int*)(s + 0x88) = 0;
    *(int*)(s + 0x90) = 0;
    *(int*)(s + 0x94) = c;
    *(u8*)(s + 0x98) = 0;
    *(u8*)(s + 0x99) = 0;
    *(u8*)(s + 0xec) = b;
    *(int*)(s + 0xf0) = -1;
    *(int*)(s + 0xf4) = -1;
    *(u8*)(s + 0xf8) = 0;
    *(int*)(s + 0xfc) = 0;
    *(int*)(s + 0x100) = 1;
    *(int*)(s + 0x9c) = 0;
    *(u8*)(s + 0xa0) = 0;
    *(int*)(s + 0xa4) = 0;
    *(u8*)(s + 0xa8) = 0;
    *(int*)(s + 0xac) = 0;
    *(u8*)(s + 0xb0) = 0;
    *(int*)(s + 0xb4) = 0;
    *(u8*)(s + 0xb8) = 0;
    *(int*)(s + 0xbc) = 0;
    *(u8*)(s + 0xc0) = 0;
    *(int*)(s + 0xc4) = 0;
    *(u8*)(s + 0xc8) = 0;
    *(int*)(s + 0xcc) = 0;
    *(u8*)(s + 0xd0) = 0;
    *(int*)(s + 0xd4) = 0;
    *(u8*)(s + 0xd8) = 0;
    *(int*)(s + 0xdc) = 0;
    *(u8*)(s + 0xe0) = 0;
    *(int*)(s + 0xe4) = 0;
    *(int*)(s + 0xe8) = 0;
    memset(s + 0x104, 0x300, 0);
    *(int*)(s + 0x404) = 0;
    *(int*)(s + 0x408) = -1;
    *(f32*)(s + 0x410) = lbl_805A2610;
    *(f32*)(s + 0x40c) = lbl_805A2614;
    *(int*)(s + 0x414) = -1;
    *(int*)(s + 0x418) = -1;
    *(int*)(s + 0x41c) = -1;
    *(f32*)(s + 0x420) = lbl_805A2610;
    *(int*)(s + 0x424) = 4;
    return self;
}