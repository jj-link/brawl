// fn_121_185DC returns one integer from the ToonLink article-integer accesser
// record: a pointer row is read from the record's table at +0x28, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words at .text[0x185DC,0x185FC)
// are 80030014 7C002850 5400103A 7C630214 80630028 54C0103A 7C63002E 4E800020,
// i.e. lwz r0, 0x14(r3); subf r0, r0, r5; slwi r0, r0, 2; add r3, r3, r0;
// lwz r3, 0x28(r3); slwi r0, r6, 2; lwzx r3, r3, r0; blr.
//
// This is the integer accesser counterpart of the Diddy unit fn_115_17450
// (table at +0x44) and the Dedede unit fn_117_17EE4 (table at +0x88); here the
// row table sits at +0x28, immediately after the 0x18-byte prefix, which is why
// the record is much more compact.
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

// TU-local view of the article-integer accesser record covering exactly the
// fields this unit touches, kept in an anonymous namespace so it cannot
// conflict with any caller's own view of the same record. This unit reads the
// +0x14 base index and the +0x28 pointer table; per-TU views of one record
// follow the established repository convention (cf. DiddyArticleIntegerAccesser).
namespace {
struct ToonLinkArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    u8 unused[0x28 - 0x18];
    int* rows[9];                // +0x28: rows[index - firstIndex]
};
static_assert(sizeof(ToonLinkArticleIntegerAccesser) == 0x4C, "Integer accesser view");
} // namespace

extern "C" int fn_121_185DC(ToonLinkArticleIntegerAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
