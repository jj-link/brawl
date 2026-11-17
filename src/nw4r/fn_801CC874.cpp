#include <types.h>
#include <revolution/OS.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

extern "C" {
void* fn_801BB188(void);
void fn_801BBA40(void);
void* fn_801B77F8(void);
void fn_801B7ABC(void);
void fn_801BD6A0(void);
void fn_801BD994(void);
void fn_801D3674(void);
void fn_801D2AD0(void);
void fn_801D2FC8(void);
}

class FrameCb {
public:
    nw4r::ut::LinkListNode node;
    virtual ~FrameCb();
    virtual void OnBegin();
    virtual void OnEnd();
};

class PlayerCb {
public:
    nw4r::ut::LinkListNode node;
    virtual ~PlayerCb();
    virtual void OnUpdateFrame();
    virtual void OnUpdateVoice();
    virtual void OnShutdown();
};

typedef nw4r::ut::LinkList<FrameCb, 0> FrameCbList;
typedef nw4r::ut::LinkList<PlayerCb, 0> PlayerCbList;

struct SoundThreadMirror {
    char pad0[0x320];
    OSMessageQueue mMsgQueue;
    char pad1[0x354 - 0x340];
    OSMutex mMutex;
    char pad2[0x378 - 0x36C];
    FrameCbList mFrameList;
    PlayerCbList mPlayerList;
    u32 mProcessTick;
};

extern "C" void fn_801CC874(SoundThreadMirror* self) {
    while (true) {
        OSMessage msg;
        OSReceiveMessage(&self->mMsgQueue, &msg, 1);

        if ((u32)msg == 1) {
            OSMutex* mutex = &self->mMutex;
            OSLockMutex(mutex);

            for (FrameCbList::Iterator impl = self->mFrameList.GetBeginIter(); impl != self->mFrameList.GetEndIter();) {
                FrameCbList::Iterator it = impl++;
                it->OnBegin();
            }

            u32 tick = OSGetTick();

            fn_801BB188();
            fn_801BBA40();
            fn_801B77F8();
            fn_801B7ABC();
            if (*(u8*)((char*)fn_801B77F8() + 0x1A) == 0) {
                for (PlayerCbList::Iterator impl = self->mPlayerList.GetBeginIter(); impl != self->mPlayerList.GetEndIter();) {
                    PlayerCbList::Iterator it = impl++;
                    it->OnUpdateFrame();
                }
                fn_801BD6A0();
                fn_801BD994();
            }
            fn_801D3674();
            fn_801D2AD0();
            fn_801D2FC8();

            self->mProcessTick = OSGetTick() - tick;

            for (FrameCbList::Iterator impl = self->mFrameList.GetBeginIter(); impl != self->mFrameList.GetEndIter();) {
                FrameCbList::Iterator it = impl++;
                it->OnEnd();
            }
            OSUnlockMutex(mutex);
        } else if ((u32)msg == 2) {
            for (PlayerCbList::Iterator impl = self->mPlayerList.GetBeginIter(); impl != self->mPlayerList.GetEndIter();) {
                PlayerCbList::Iterator it = impl++;
                it->OnShutdown();
            }
            return;
        }
    }
}
