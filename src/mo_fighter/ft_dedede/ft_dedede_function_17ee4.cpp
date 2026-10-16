// fn_117_17EE4 returns one integer from the Dedede article-integer accesser
// record: a pointer row is read from the record's table at +0x88, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words at .text[0x17EE4,0x17F04)
// are 80030014 7C002850 5400103A 7C630214 80630088 54C0103A 7C63002E 4E800020,
// i.e. lwz r0, 0x14(r3); subf r0, r0, r5; slwi r0, r0, 2; add r3, r3, r0;
// lwz r3, 0x88(r3); slwi r0, r6, 2; lwzx r3, r3, r0; blr.
//
// No relocation hits [0x17EE4,0x17F04) in any import stream of ft_dedede.rel
// (m27/m117/m0), and no relocation with addend 0x17EE4 exists in any stream:
// the only reference to this unit is the same-section bl from fn_117_17D58 at
// .text 0x17D7C, which carries no relocation in the fully linked module
// (evidence/rel_decode_17ee4.py, which also reproduces the machine-confirmed
// anchors E20C->0x135468, E274->0x135EB4 and E27C->0x13C428 exactly). The
// comparison target is therefore the first 0x20 bytes of the canonical
// dtk-sliced gap-fallback object build/RSBE01_02/ft_dedede/obj/
// auto_00_00017EE4_text.o (sha1 88d2ca2aa7d607911d54a11ef5a36426c25a2df6),
// whose .text spans the whole uncovered region [0x17EE4,0x197E8);
// evidence/compare_17ee4.py restricts the target .text to the owned window
// and its relocations to offsets < 0x20.
//
// This is the integer counterpart of the float handler fn_117_17D38
// (.text 0x17D38: lwz r0, 0x10(r3); subf r0, r0, r5; slwi r0, r0, 2;
// add r3, r3, r0; lwz r3, 0x18(r3); slwi r0, r6, 2; lfsx f1, r3, r0; blr),
// which fn_117_17AAC dispatches to for index < 4008 exactly the way
// fn_117_17D58 dispatches here for index < 24006.
#include <so/so_module_accesser.h>
#include <types.h>

// TU-local view of the article-integer accesser record covering exactly the
// fields this unit touches, kept in an anonymous namespace so it cannot
// conflict with the caller's own global 0xd8-sized view of the same record
// (prefix plus the embedded selector at +0xD4) in ft_dedede_function_17d58.cpp.
// This unit additionally reads the +0x14 base index and the +0x88 pointer
// table; per-TU views of one record follow the established repository
// convention (cf. DededeTraversalIndex).
namespace {
struct DededeArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    u8 unused[0x88 - 0x18];
    int* rows[33];               // +0x88: rows[index - firstIndex]
};
static_assert(sizeof(DededeArticleIntegerAccesser) == 0x10C, "Integer accesser view");
} // namespace

extern "C" int fn_117_17EE4(DededeArticleIntegerAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
