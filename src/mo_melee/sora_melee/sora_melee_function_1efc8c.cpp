#include <gf/gf_heap_manager.h>
#pragma force_active on
#pragma fp_contract off

struct Target {
    char padding00[0x3e];
    unsigned char playerMask;
    char padding3f;
    unsigned int flags;
};

struct TargetManager {
    char padding00[0x350];
    unsigned short count;
};

extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void free__13gfHeapManagerFPv(void*);
int fn_27_1EFE3C(TargetManager*, Target*, Target*, int, float, float, float);
Target* fn_27_1EFC8C(TargetManager*, Target*, Target*, Target**, int,
                     float, float, float);
}

extern "C" Target* fn_27_1EFC8C(TargetManager* manager, Target* current,
    Target* excluded, Target** targets, int player, float x, float y, float z)
{
    Target** rd;
    Target** it;
    Target** out;
    int found;
    int i;
    Target** outBase;
    Target* result;
    int j;

    found = 0;
    outBase = static_cast<Target**>(
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(12, manager->count * 4));
    if (!outBase) {
        return current;
    }
    it = targets;
    out = outBase;
    i = 0;
    while (i < manager->count) {
        if (*it) {
            int valid = fn_27_1EFE3C(manager, *it, excluded, player, x, y, z);
            if (valid) {
                if (*it == current) {
                    if (outBase)
                        free__13gfHeapManagerFPv(outBase);
                    return excluded;
                }
                *out = *it;
                ++out;
                ++found;
                *it = 0;
            }
        }
        ++it;
        ++i;
    }
    if (found == 0) {
        if (outBase)
            free__13gfHeapManagerFPv(outBase);
        return current;
    }
    rd = outBase;
    j = 0;
    while (j < found) {
        result = fn_27_1EFC8C(manager, current, *rd, targets, player, x, y, z);
        if (result != current) {
            if (outBase)
                free__13gfHeapManagerFPv(outBase);
            return result;
        }
        ++rd;
        ++j;
    }
    if (outBase)
        free__13gfHeapManagerFPv(outBase);
    return current;
}
