#include <string.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern "C" int fn_80145828(void* self, int idx, void** out, int a, int b, int c);
extern "C" void fn_8014BC24(int* p);
extern "C" void fn_800D2894(char* base, int idx);

extern "C" const float lbl_805A2B50;
extern "C" unsigned int g_NtAIDBitmap;
extern "C" int* lbl_805A0434;
extern "C" char* g_muWifiInterfaceTask;

union FlagByte {
    unsigned char flag;
    unsigned char bits : 8;
};

struct Entry {
    FlagByte fb;
    unsigned char b1;
    unsigned char b2;
    unsigned char pad0;
    float value;
    unsigned short w8;
    unsigned short pad1[3];
    unsigned short w10;
    unsigned short pad2;
    int w14;
    int w18;
    unsigned char data[0xE30];
    unsigned char tail[4];
};

struct Object {
    unsigned char prefix[0x44];
    Entry entries[4];
};

extern "C" void fn_80143D80(unsigned char* self, int idx) {
    unsigned char* entry = NULL;
    Entry* e = &((Object*)self)->entries[idx];
    void* out1;
    void* out2;
    int mask;

    e->fb.bits = 0;
    e->b1 = 0;
    e->b2 = 0;
    e->value = lbl_805A2B50;
    e->w8 = 0;
    e->w10 = 0;
    e->w18 = 0;
    e->w14 = e->w18;
    memset(e->data, 0, sizeof(e->data));

    mask = 1;
    e->fb.bits = mask;
    e->w10 = (unsigned short)(OSGetTick() % 10000);
    mask <<= idx;

    if (g_NtAIDBitmap & mask) {
        if (fn_80145828(self, idx, &out1, 0, 0, 6) != 0) {
            if (3 - ((e->w18 + 4 - e->w14) % 4) < 1) {
                entry = NULL;
            } else {
                entry = &e->data[e->w18 * 0x38C];
            }
            if (entry != NULL) {
                e->w18 = (*(int*)((char*)e + 0x18) + 1) % 4;
            }
        }
    }

    if (g_NtAIDBitmap & mask) {
        if (fn_80145828(self, idx, &out2, 0, 0, 6) != 0) {
            unsigned char* p;
            if (3 - ((e->w18 + 4 - e->w14) % 4) < 1) {
                p = NULL;
            } else {
                p = &e->data[e->w18 * 0x38C];
            }
            if (p != NULL) {
                e->w18 = (1 + *(int*)((char*)e + 0x18)) % 4;
            }
        }
    }

    fn_8014BC24(lbl_805A0434);
    fn_800D2894(g_muWifiInterfaceTask, idx);
}
