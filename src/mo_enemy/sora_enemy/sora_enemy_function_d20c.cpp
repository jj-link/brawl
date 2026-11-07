#include <types.h>
#include <snd/snd_system.h>
#pragma force_active on

struct gfArchive;

enum emKind { emKind_Invalid = -1 };

class emManager {
public:
    int _0;
    int _4;
    int _8;
    int _c;
    int _10;
    int _14;
    u32 getPreloadArchiveCountFromKind(emKind kind);
    int preloadArchive(gfArchive*, gfArchive*, gfArchive*, gfArchive*, emKind, bool);
};

class emInfoBase {
public:
    virtual void* _v0();
    virtual u32 isInvalidKind(int kind);
};

extern "C" emInfoBase* getInstance__6emInfoFv();
extern "C" int fn_41_D644(emManager*);
extern "C" void* fn_41_D5A0(emManager*, int);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_41_D8D4(void*, gfArchive*, gfArchive*, gfArchive*, gfArchive*, emKind);
extern "C" int getSEId__6emInfoF6emKind(void*, int);
extern "C" void fn_41_D1A4(void*, void*, emKind, int, int);

int emManager::preloadArchive(gfArchive* a, gfArchive* b, gfArchive* c, gfArchive* d, emKind kind, bool snd) {
    int oldId;
    void* entry2;
    void* entry;
    u32 seId;
    int soundResult;
    int idx;
    if (getInstance__6emInfoFv()->isInvalidKind(kind) == 1)
        return -2;
    if (getPreloadArchiveCountFromKind(kind) >= 1)
        return -1;
    idx = fn_41_D644(this);
    if (idx < 0)
        return -3;
    entry = fn_41_D5A0(this, idx);
    if (entry == 0)
        return -3;
    oldId = this->_14;
    this->_14 = oldId + 1;
    entry2 = __nw__FUlQ25Heaps8HeapType(0x18, 0x25);
    if (entry2 != 0) {
        entry2 = fn_41_D8D4(entry2, a, b, c, d, kind);
    }
    if (entry2 == 0)
        return -4;
    seId = (u32)getSEId__6emInfoF6emKind(getInstance__6emInfoFv(), kind);
    soundResult = -2;
    if (seId != 0xFFFFFFFF) {
        soundResult = g_sndSystem->loadSoundGroup((SndGroupID)seId, 0xc, snd);
        if (soundResult == -2)
            return -4;
    }
    fn_41_D1A4(entry, entry2, kind, oldId, soundResult);
    return oldId;
}
