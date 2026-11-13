#include <gf/gf_module.h>
#pragma force_active on

u32 gfModuleHeader::getTextSectionAddr() {
    u32 v;
    u32 result = 0;
    u32* p;
    u32 absolute = 0;
    u32 count = numSections;

    if ((u32)this < sectionInfoOffset) {
        absolute = 1;
        p = (u32*)sectionInfoOffset;
    } else {
        p = (u32*)((u32)this + sectionInfoOffset);
    }

    for (u32 i = 0; i < count; i++) {
        v = *p;
        if (v & 1) {
            result = v & ~1;
            if (!absolute) {
                result += (u32)this;
            }
            break;
        }
        p += 2;
    }

    return result;
}
