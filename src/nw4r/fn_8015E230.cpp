#pragma force_active on

#include <types.h>
#include <nw4r/ut/ut_ResFontBase.h>

using namespace nw4r::ut;

extern "C" u16 fn_8015E410(void*, void*, u16);

static const CharWidths& GetCharWidthsFromIndex(void* self, u16 index) {
    const FontWidth* pWidth =
        ((const FontInformation*)*(void* const*)((const char*)self + 0x14))->pWidth;
    const CharWidths* pWidths;

    while (pWidth != 0) {
        if (pWidth->indexBegin <= index && index <= pWidth->indexEnd) {
            pWidths = &pWidth->widthTable[index - pWidth->indexBegin];
            goto done;
        }
        pWidth = pWidth->pNext;
    }
    pWidths = &((const FontInformation*)*(void* const*)((const char*)self + 0x14))
                   ->defaultWidth;
done:
    return *pWidths;
}

extern "C" CharWidths fn_8015E230(void* arg0, u16 arg1) {
    void* node;
    unsigned int val;

    if (arg1 == *(u16*)((char*)arg0 + 0x18)) {
        val = *(u16*)((char*)arg0 + 0x1A);
        goto have_val;
    }

    *(u16*)((char*)arg0 + 0x18) = arg1;
    node = *(void**)((char*)arg0 + 0x14);
    node = *(void**)((char*)node + 0x10);
    goto check_node;

search_node:
    if (*(u16*)node <= arg1 && arg1 <= *(u16*)((char*)node + 2)) {
        val = (u16)fn_8015E410(arg0, node, arg1);
        *(u16*)((char*)arg0 + 0x1A) = val;
        goto have_val;
    }
    node = *(void**)((char*)node + 8);

check_node:
    if (node != 0) {
        goto search_node;
    }
    val = 0xFFFF;
    *(u16*)((char*)arg0 + 0x1A) = val;
    val &= 0xFFFF;

have_val:
    val = (val != 0xFFFF) ? val
                          : *(u16*)((char*)*(void**)((char*)arg0 + 0x14) + 2);

    return GetCharWidthsFromIndex(arg0, (u16)val);
}
