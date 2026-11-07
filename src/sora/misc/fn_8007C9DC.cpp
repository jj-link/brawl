#include <mv/mv_THPPlayer.h>
#include <mv/mv_THPRead.h>
#include <mv/mv_THPAudioDecode.h>
#include <revolution/OS/OSMessage.h>
#pragma force_active on

struct Work {
    char pad[0x7c0];
    OSMessageQueue queue;
    char pad2[0x7f4 - 0x7c0 - sizeof(OSMessageQueue)];
    int value;
    int* first;
    int* second;
};
extern Work* lbl_805A01F8;
extern "C" int fn_801E8078(int);
extern "C" int fn_801FB0F8(void*);
extern "C" void fn_8007E4C4();
extern "C" void fn_80207BC0(int*);
extern "C" void fn_801FF4CC(void*);

extern "C" void fn_8007C9DC() {
    if (*(int*)&g_thpObject.unk80[0x20] && g_thpObject.unk80[0x24]) {
        g_thpObject.unk80[0x25] = 0;
        g_thpObject.unk80[0x24] = 0;
        fn_801E8078(lbl_805A01F8->value);
        if (!*(int*)&g_thpObject.unkAC[4]) {
            fn_801FB0F8(&g_thpObject);
            ReadThreadCancel();
        }
        fn_8007E4C4();
        if (g_thpObject.unkA7[0]) {
            if (lbl_805A01F8->first) {
                fn_80207BC0(lbl_805A01F8->first);
                fn_801FF4CC(lbl_805A01F8->first);
                lbl_805A01F8->first = 0;
            }
            if (lbl_805A01F8->second) {
                fn_80207BC0(lbl_805A01F8->second);
                fn_801FF4CC(lbl_805A01F8->second);
                lbl_805A01F8->second = 0;
            }
            AudioDecodeThreadCancel();
        }
        OSMessage msg;
        void* result;
        do {
            if (OSReceiveMessage(&lbl_805A01F8->queue, &msg, 0) == 1)
                result = msg;
            else
                result = 0;
        } while (result);
        g_thpObject.unkA8 = 0;
        *(int*)&g_thpObject.unkAC[0] = 0;
    }
}