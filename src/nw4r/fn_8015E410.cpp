#pragma force_active on

#include <nw4r/ut/ut_ResFontBase.h>

using namespace nw4r::ut;
using namespace nw4r::ut::detail;

extern "C" u16 fn_8015E410(const void* self, const FontCodeMap* pMap, u16 ch) {
    u16 ret = 0xFFFF;
    switch (pMap->mappingMethod) {
    case FONT_MAPMETHOD_DIRECT:
        ret = (u16)(pMap->mapInfo[0] + (ch - pMap->ccodeBegin));
        break;
    case FONT_MAPMETHOD_TABLE:
        ret = pMap->mapInfo[ch - pMap->ccodeBegin];
        break;
    case FONT_MAPMETHOD_SCAN: {
        const u8* base = (const u8*)pMap->mapInfo;
        const u32* lo = (const u32*)(base + 2);
        const u32* hi = (const u32*)(base + 2 + (*(const u16*)base - 1) * 4);
        while (lo <= hi) {
            const u32* mid = lo + (hi - lo) / 2;
            u16 key = *(const u16*)mid;
            if ((u32)key < (u32)ch) {
                lo = mid + 1;
            } else if ((u32)ch < (u32)key) {
                hi = mid - 1;
            } else {
                ret = *((const u16*)mid + 1);
                break;
            }
        }
        break;
    }
    }
    return ret;
}
