#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <nw4r/ut/ut_LinkList.h>
#include <nw4r/snd/snd_BasicSound.h>
#include <string.h>
#pragma force_active on
using namespace nw4r::ut;
using nw4r::snd::detail::BasicSound;
using nw4r::snd::SoundParam;
class ListAccess : public detail::LinkListImpl {
public:
    using detail::LinkListImpl::Insert;
};
extern "C" {
int fn_801CBD0C(char*, int, char*);
void* fn_801C0A0C(char*);
BasicSound* fn_801CF664(void*, char*);
void fn_8015C2BC(char*, LinkListNode**);
void fn_801CA970(char*);
void fn_801BD5C0(BasicSound*, BasicSound::AmbientParamUpdateCallback*, BasicSound::AmbientArgUpdateCallback*, BasicSound::AmbientArgAllocaterCallback*, void*);
void fn_801BF5B8(char*, BasicSound*);
}
static inline int priority(char* obj) {
    int a = *(unsigned char*)(obj + 0x74) + *(int*)(obj + 0x40);
    return a > 127 ? 127 : (a < 0 ? 0 : a);
}
static inline void assignHeap(char* self, BasicSound* sound) {
    OSMutex* mutex = (OSMutex*)(self + 0x48);
    OSLockMutex(mutex);
    if (*(int*)(self + 0x18) == 0) {
        OSUnlockMutex(mutex);
        return;
    }
    LinkListNode* node = *(LinkListNode**)(self + 0x1c);
    char* heap = (char*)node - 0x2c;
    fn_8015C2BC(self + 0x18, &node);
    *(BasicSound**)(heap + 0x34) = sound;
    sound->SetPlayerHeap((nw4r::snd::detail::PlayerHeap*)heap);
    fn_801CA970(heap);
    OSUnlockMutex(mutex);
}
static inline void ambient(BasicSound* sound, BasicSound::AmbientArgInfo* info) {
    if (info != 0) {
        void* arg = info->argAllocaterCallback->detail_AllocAmbientArg(info->argSize);
        if (arg != 0) {
            memcpy(arg, info->arg, info->argSize);
            fn_801BD5C0(sound, info->paramUpdateCallback, info->argUpdateCallback, info->argAllocaterCallback, arg);
        }
    }
}
static inline void insertSound(char* self, BasicSound* sound) {
    ((ListAccess*)self)->Insert(detail::LinkListImpl::Iterator((LinkListNode*)(self + 4)), (LinkListNode*)((char*)sound + 0xc0));
}
static inline void insertPriority(char* self, BasicSound* sound, OSMutex* mutex) {
    OSLockMutex(mutex);
    detail::LinkListImpl::Iterator it(*(LinkListNode**)(self + 0x10));
    while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(self + 0x10)))) {
        int x = priority((char*)it.operator->() - 0xc8);
        int y = priority((char*)sound);
        if (y < x) break;
        ++it;
    }
    ((ListAccess*)(self + 0xc))->Insert(it, (LinkListNode*)((char*)sound + 0xc8));
    OSUnlockMutex(mutex);
}
static inline void allocSound(BasicSound*& sound, char* pool, int currentPriority) {
    OSMutex* poolMutex = (OSMutex*)(pool + 0x10);
    OSLockMutex(poolMutex);
    sound = 0;
    while (sound == 0) {
        void* buffer = fn_801C0A0C(pool);
        if (buffer != 0) {
            sound = (BasicSound*)buffer;
            if (buffer != 0) sound = fn_801CF664(buffer, pool);
        } else {
            BasicSound* lowest;
            if (*(int*)(pool + 4) == 0) lowest = 0;
            else lowest = (BasicSound*)(*(char**)(pool + 8) - 0xb8);
            if (lowest == 0) {
                OSUnlockMutex(poolMutex);
                sound = 0; return;
            }
            if (currentPriority < priority((char*)lowest)) {
                OSUnlockMutex(poolMutex);
                sound = 0; return;
            }
            OSUnlockMutex((OSMutex*)(pool + 0x10));
            lowest->Stop(0);
            OSLockMutex((OSMutex*)(pool + 0x10));
        }
    }
    {
        detail::LinkListImpl::Iterator it(*(LinkListNode**)(pool + 8));
        while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(pool + 8)))) {
            if (currentPriority < priority((char*)it.operator->() - 0xb8)) break;
            ++it;
        }
        ((ListAccess*)(pool + 4))->Insert(it, (LinkListNode*)((char*)sound + 0xb8));
    }
    OSUnlockMutex(poolMutex);
}
extern "C" BasicSound* fn_801CB4F4(char* self, u32 pri, int basePriority, BasicSound::AmbientArgInfo* info, char* ext, u32 id, char* pool) {
    SoundParam param;
    OSMutex* mutex = (OSMutex*)(self + 0x48);
    OSLockMutex(mutex);
    if (pool == 0) {
        OSUnlockMutex(mutex);
        return 0;
    }
    int ambientPriority = 0;
    if (info != 0) {
        info->paramUpdateCallback->detail_Update(&param, id, 0, info->arg, 8);
        ambientPriority = param.priority;
    }
    int sum = basePriority + ambientPriority;
    unsigned int currentPriority = sum > 127 ? 127 : (sum < 0 ? 0 : sum);
    if (!fn_801CBD0C(self, currentPriority, ext)) {
        OSUnlockMutex(mutex);
        return 0;
    }
    BasicSound* sound;
    allocSound(sound, pool, currentPriority);
    if (sound == 0) {
        OSUnlockMutex(mutex);
        return 0;
    }
    assignHeap(self, sound);
    if (info != 0) ambient(sound, info);
    sound->SetPriority(pri);
    *(int*)((char*)sound + 0x40) = ambientPriority;
    insertSound(self, sound);
    sound->SetSoundPlayer((nw4r::snd::SoundPlayer*)self);
    if (ext != 0) fn_801BF5B8(ext, sound);
    pri = (u32)(self + 0x48);
    insertPriority(self, sound, (OSMutex*)pri);
    OSUnlockMutex(mutex);
    return sound;
}
