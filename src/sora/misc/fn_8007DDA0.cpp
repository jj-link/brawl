#include <types.h>
#include <revolution/OS/OSCache.h>
#pragma force_active on

struct AudioState {
    u32 active;
    char pad[0x7F4];
    u8* voice;
    u8* voice2;
    u32 left;
    u32 right;
    u64 marks[5];
    s32 readIndex;
    s32 writeIndex;
    u32 previous;
    u32 pad83c;
    u64 position;
};

extern char g_thpObject[];
extern AudioState* lbl_805A01F8;
extern f32 lbl_805A1B40;
extern f32 lbl_805A1B44;
extern "C" void fn_8007DC88(void*, void*, u32);

inline void fillAudio(u32 half) {
    void* a;
    void* b;
    u32 samples;
    u32 n = ((u32)(lbl_805A1B40 + (f32)(*(u32*)(g_thpObject + 0x90) * 40) / lbl_805A1B44) + 31) & ~31;
    samples = n >> 1;
    a = (void*)(lbl_805A01F8->left + half * n);
    b = (void*)(lbl_805A01F8->right + half * n);
    if (*(u32*)(g_thpObject + 0x8C) == 2) {
        fn_8007DC88(a, b, samples);
        DCFlushRange(a, samples * 2);
        DCFlushRange(b, samples * 2);
    } else {
        fn_8007DC88(a, 0, samples);
        DCFlushRange(a, samples * 2);
    }
}
extern "C" void fn_8007DDA0() {
    u32 current;
    u32 midpoint;
    if (lbl_805A01F8 && lbl_805A01F8->active) {
        s32 is2 = (*(u8*)(g_thpObject + 0xA5) == 2);
        s32 flag = (lbl_805A01F8->voice != 0 || lbl_805A01F8->voice2 != 0);
        if (is2 & flag) {
            u32 size = ((u32)(lbl_805A1B40 + (f32)(*(u32*)(g_thpObject + 0x90) * 40) / lbl_805A1B44) + 31) & ~31;
            current = ((u32)*(u16*)(lbl_805A01F8->voice + 0xA2) << 16) | *(u16*)(lbl_805A01F8->voice + 0xA4);
            u32 delta;
            if (current >= lbl_805A01F8->previous) {
                delta = current - lbl_805A01F8->previous;
            } else {
                char* base = (char*)((lbl_805A01F8->left + 0x80000000) >> 1);
                delta = base + size - (char*)lbl_805A01F8->previous;
                delta += (char*)current - base;
            }
            u64 pos = lbl_805A01F8->position + delta;
            lbl_805A01F8->position = pos;
            while (lbl_805A01F8->readIndex != lbl_805A01F8->writeIndex) {
                if (pos < lbl_805A01F8->marks[lbl_805A01F8->readIndex]) {
                    break;
                }
                lbl_805A01F8->readIndex++;
                if (lbl_805A01F8->readIndex >= 5) {
                    lbl_805A01F8->readIndex = 0;
                }
                (*(s32*)(g_thpObject + 0xE4))++;
            }
            midpoint = ((lbl_805A01F8->left + 0x80000000) >> 1) + (size >> 1);
            if (current < lbl_805A01F8->previous) {
                fillAudio(1);
            }
            if (current >= midpoint && lbl_805A01F8->previous < midpoint) {
                fillAudio(0);
            }
            lbl_805A01F8->previous = current;
        }
    }
}
