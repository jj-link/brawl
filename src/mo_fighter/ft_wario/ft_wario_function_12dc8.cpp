// fn_110_12DC8 returns one integer from the Wario article-integer accesser
// record: a pointer row is read from the record's table at +0xA4, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words at .text[0x12DC8,0x12E8)
// are 80030014 7C002850 5400103A 7C630214 806300A4 54C0103A 7C63002E 4E800020,
// i.e. lwz r0, 0x14(r3); subf r0, r0, r5; slwi r0, r0, 2; add r3, r3, r0;
// lwz r3, 0xa4(r3); slwi r0, r6, 2; lwzx r3, r3, r0; blr.
//
// This is the integer counterpart of the Diddy article-integer accesser
// fn_115_17450 and the Dedede article-integer accesser fn_117_17EE4, which
// read their pointer tables from +0x44 and +0x88 respectively but are
// otherwise identical in shape: base index at +0x14, row selected by
// (index - base), element selected by shifting the element index.
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

// TU-local view of the article-integer accesser record covering exactly the
// fields this unit touches, kept in an anonymous namespace so it cannot
// conflict with any caller's own global view of the same record. This unit
// additionally reads the +0x14 base index and the +0xa4 pointer table;
// per-TU views of one record follow the established repository convention
// (cf. DededeArticleIntegerAccesser).
namespace {
struct WarioArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    u8 unused[0xa4 - 0x18];
    int* rows[33];               // +0xa4: rows[index - firstIndex]
};
static_assert(sizeof(WarioArticleIntegerAccesser) == 0x128, "Integer accesser view");
} // namespace

extern "C" int fn_110_12DC8(WarioArticleIntegerAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
