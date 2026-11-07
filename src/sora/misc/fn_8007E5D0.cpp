#include <mv/mv_THPPlayer.h>
#include <revolution/OS/OSThread.h>
#include <types.h>
#pragma force_active on

struct Message {
    void* data;
    int frame;
    char pad[16];
};
extern "C" int fn_8007E70C(Message*);
extern char* lbl_805A0208;

extern "C" void fn_8007E5D0(void* arg) {
    Message msg;
    u32 size = g_thpObject.unkBC;
    int frame = 0;
    int skip = 0;
    msg.data = arg;
    while (true) {
        if (g_thpObject.unkA7[0]) {
            while (skip--) {
                ++*(u32*)((char*)&g_thpObject + 0xD8);
                u32 pos = (frame + g_thpObject.unkC0) % g_thpObject.unk50;
                if (pos == g_thpObject.unk50 - 1) {
                    if (g_thpObject.unkA6 & 1) {
                        size = *(u32*)msg.data;
                        msg.data = g_thpObject.unkB4;
                    } else {
                        break;
                    }
                } else {
                    u32 next = *(u32*)msg.data;
                    msg.data = (char*)msg.data + size;
                    size = next;
                }
                ++frame;
            }
        }
        msg.frame = frame;
        skip = fn_8007E70C(&msg);
        u32 pos = (frame + g_thpObject.unkC0) % g_thpObject.unk50;
                if (pos == g_thpObject.unk50 - 1) {
            if (g_thpObject.unkA6 & 1) {
                size = *(u32*)msg.data;
                msg.data = g_thpObject.unkB4;
            } else {
                OSSuspendThread((OSThread*)(lbl_805A0208 + 8));
            }
        } else {
            u32 next = *(u32*)msg.data;
            msg.data = (char*)msg.data + size;
            size = next;
        }
        ++frame;
    }
}