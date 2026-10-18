// fn_123_171A0 returns one integer from the Sonic article-integer accesser
// record: a pointer row is read from the record's table at +0x44, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words at
// .text[0x171A0,0x171C0) are 80030014 7C002850 5400103A 7C630214 80630044
// 54C0103A 7C63002E 4E800020, i.e. lwz r0, 0x14(r3); subf r0, r0, r5;
// slwi r0, r0, 2; add r3, r3, r0; lwz r3, 0x44(r3); slwi r0, r6, 2;
// lwzx r3, r3, r0; blr.
//
// This is the same shape as the Dedede integer accesser handler
// fn_117_17EE4 (src/mo_fighter/ft_dedede/ft_dedede_function_17ee4.cpp),
// except the pointer-table field sits at +0x44 instead of +0x88.
#include <types.h>
#pragma force_active on

// TU-local view of the article-integer accesser record covering exactly the
// fields this unit touches, kept in an anonymous namespace so it cannot
// conflict with other per-TU views of the same record.
namespace {
struct SonicArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    u8 unused[0x44 - 0x18];
    int* rows[1];                // +0x44: rows[index - firstIndex]
};
} // namespace

extern "C" int fn_123_171A0(SonicArticleIntegerAccesser* self, int p2, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
