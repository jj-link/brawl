#include <sr/sr_common.h>
#include <types.h>

struct PeachClassInfo;
struct PeachFighter;

extern "C" {
PeachFighter* fn_103_70(PeachFighter* fighter, s32 entryId, HeapType instanceHeap,
                      HeapType modelHeap, HeapType motionHeap);

PeachFighter* fn_103_D0C0(const PeachClassInfo* info, s32 entryId, HeapType instanceHeap,
                         HeapType modelHeap, HeapType motionHeap) {
    PeachFighter* fighter = static_cast<PeachFighter*>(::operator new(0x18710, instanceHeap));
    if (fighter != nullptr) {
        return fn_103_70(fighter, entryId, instanceHeap, modelHeap, motionHeap);
    }
    return fighter;
}
}
