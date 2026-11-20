#pragma force_active on
#include <types.h>
#include <string.h>
extern "C" void fn_8014BC24(int*);
extern "C" void fn_800D3BA4(char*, int);
extern "C" char* g_muWifiInterfaceTask;
extern "C" int* lbl_805A0434;
extern "C" const float lbl_805A2B50;
struct Entry {
    unsigned char flags : 8;
    unsigned char a, b, pad;
    float value;
    unsigned short c;
    char pad1[6];
    unsigned short d;
    char pad2[2];
    int e, f;
    char data[0xe30];
    char tail[4];
};
struct Object {
    char pad[0x44];
    Entry entries[4];
};
inline void clearEntry(Entry* e) {
    e->flags = 0;
    e->a = 0;
    e->b = 0;
    e->value = lbl_805A2B50;
    e->c = 0;
    e->d = 0;
    e->f = 0;
    e->e = 0;
    memset(e->data, 0, 0xe30);
}
extern "C" void fn_80143F7C(char* self, int idx) {
    clearEntry(&((Object*)self)->entries[idx]);
    u32 mask = ~(1U << idx);
    *(s32*)(self + 0x1c) &= mask;
    *(s32*)(self + 0x38) &= mask;
    *(u8*)(self + 0x4808) &= mask;
    fn_8014BC24(lbl_805A0434);
    fn_800D3BA4(g_muWifiInterfaceTask, idx);
}