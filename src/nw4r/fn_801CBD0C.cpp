#include <nw4r/snd/snd_BasicSound.h>
#include <nw4r/ut.h>
#include <revolution/OS.h>
#include <types.h>
#pragma force_active on

using nw4r::snd::detail::BasicSound;
using nw4r::snd::detail::BasicSoundPlayerPrioList;

extern "C" void* fn_801BF63C(void* list);

class SoundOwner {
public:
    s32 mCount;                    // at 0x0
    u8 pad_04[0x10 - 0x4];
    nw4r::ut::LinkListNode* mHead; // at 0x10
    u8 pad_14[0x24 - 0x14];
    u16 mMax;                      // at 0x24
    u8 pad_26[0x48 - 0x26];
    OSMutex mMutex;                // at 0x48
};

class ListOwner {
public:
    s32 mCount; // at 0x0
    u8 pad_04[0x8];
    u16 mMax;   // at 0xC
};

extern "C" bool fn_801CBD0C(SoundOwner* self, s32 priority, ListOwner* list) {
    OSMutex* mutex = &self->mMutex;
    OSLockMutex(mutex);
    if (self->mMax == 0) {
        OSUnlockMutex(mutex);
        return 0;
    }
    while (self->mCount >= self->mMax) {
        BasicSound* p = BasicSoundPlayerPrioList::GetPointerFromNode(self->mHead);
        if (p == NULL) {
            OSUnlockMutex(mutex);
            return 0;
        }
        if (priority < p->CalcCurrentPlayerPriority()) {
            OSUnlockMutex(mutex);
            return 0;
        }
        p->Shutdown();
    }
    if (list != NULL) {
        if (list->mMax == 0) {
            OSUnlockMutex(mutex);
            return 0;
        }
        while (list->mCount >= list->mMax) {
            BasicSound* q = (BasicSound*)fn_801BF63C(list);
            if (q == NULL) {
                OSUnlockMutex(mutex);
                return 0;
            }
            if (priority < q->CalcCurrentPlayerPriority()) {
                OSUnlockMutex(mutex);
                return 0;
            }
            q->Shutdown();
        }
    }
    OSUnlockMutex(mutex);
    return 1;
}
