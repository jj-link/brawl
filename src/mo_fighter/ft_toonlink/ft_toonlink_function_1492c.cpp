// fn_121_1492C returns one integer from the Toon Link article-integer accesser
// record: a pointer row is read from the record's table at +0x54, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words at .text[0x1492C,0x1494C)
// are 80030014 7C002850 5400103A 7C630214 80630054 54C0103A 7C63002E 4E800020,
// i.e. lwz r0, 0x14(r3); subf r0, r0, r5; slwi r0, r0, 2; add r3, r3, r0;
// lwz r3, 0x54(r3); slwi r0, r6, 2; lwzx r3, r3, r0; blr.
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

// TU-local view of the article-integer accesser record covering exactly the
// fields this unit touches, kept in an anonymous namespace. This unit reads
// the +0x14 base index and the +0x54 pointer table.
namespace {
struct ToonLinkArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    u8 unused[0x54 - 0x18];
    int* rows[1];                // +0x54: rows[index - firstIndex]
};
} // namespace

extern "C" int fn_121_1492C(ToonLinkArticleIntegerAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
