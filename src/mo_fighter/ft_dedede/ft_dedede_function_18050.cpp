// fn_117_18050 is the seventh entry (index 6) of Dedede's chained
// article-record-holder dispatch table at .data+0x94B4 - the cursor-advance
// method, virtual slot vtable+0x20 (6th declared virtual) of the holder
// interface. The original words at .text[0x18050,0x180E0) are
// 9421FFF0 7C0802A6 90010014 93E1000C 7C7F1B78 81830000 818C0018 7D8903A6
// 2C030000 40820054 807F000C 2C030000 4081002C 3403FFFF 901F000C 41810010
// 38000000 901F0008 48000030 807F0008 3803006C 901F0008 48000020 807F0004
// 2C030000 41820014 81830000 818C0020 7D8903A6 4E800421 83E1000C 80010014
// 7C0803A6 38210010 4E800020.
//
// No relocation hits [0x18050,0x180E0) in any import stream of ft_dedede.rel
// (m27/m117/m0). The only reference to this unit is an R_PPC_ADDR32 pointer
// at .data+0x94CC (m117 stream, symsec 1, addend 0x18050) - the seventh entry
// of the holder dispatch table whose other entries point at the sibling
// record-holder methods fn_117_18208/18030/18040/181A8/18250/17F7C/180E0/
// 18158/18210 (evidence/rel_decode_18050.py; it also reproduces the
// machine-confirmed anchors m27 0xE20C->0x135468, 0xE274->0x135EB4 and
// 0xE27C->0x13C428 exactly, and the table is preceded by the typeinfo-style
// .data chain 0x94A4/0x94A8/0x94AC with 0x94B0 zero, so the table base the
// object vptr points at is 0x94AC and declared virtuals start at vptr+0x8).
// The comparison target is the retained pre-registration gap-fallback object
// build/.../auto_00_00018018_text.o, whose .text starts at 0x18018; the owned
// unit sits at .text offset 0x38..0xC8 with no relocations.
//
// Slot map machine-confirmed against the table plus the family
// disassembly: vptr+0x08 fn_117_18208 (returns false), vptr+0x0C
// fn_117_18030 and vptr+0x10 fn_117_18040 (tail-call vptr+0x2C getRecord
// trampolines), vptr+0x14 fn_117_181A8 (served-count total),
// vptr+0x18 fn_117_18250 (isEmpty: totalCount==0 via cntlzw/srwi),
// vptr+0x1C fn_117_17F7C, vptr+0x20 fn_117_18050 (this unit),
// vptr+0x24 fn_117_180E0, vptr+0x28 fn_117_18158, vptr+0x2C fn_117_18210
// (getRecord, the published 18210 unit).
//
// Semantics: advancing an empty holder (virtual4 isEmpty != 0) does nothing.
// Otherwise, when the local array still serves records (count > 0) the count
// is decremented - the store and test reuse the addic. flags - and the array
// cursor moves one 0x6C record forward while records remain, else the array
// pointer is nulled. When the local side is exhausted (count <= 0) and a
// chained holder is present (+0x04), the same advance virtual is invoked on
// the chain (the sibling cluster confirms the layout: fn_117_18210 indexes
// the array/chain for getRecord, fn_117_180E0 forwards its advance past an
// empty chain link, fn_117_18158 clears array+count and the chain, and
// fn_117_181A8 totals the served records).
#include <StaticAssert.h>
#include <types.h>

namespace {
// One 0x6C-byte record served by the holder; this unit only moves the cursor,
// so the contents stay opaque.
struct DededeArticleRecord {
    u8 data[0x6C];
};
static_assert(sizeof(DededeArticleRecord) == 0x6C, "Record element size");

// Interface of a chained record holder. Declared virtuals sit at vtable
// offsets 0x8..0x20; this unit calls isEmpty (offset 0x18, fn_117_18250) on
// self and advance (offset 0x20, this method) on the chained holder.
class DededeArticleRecordProvider {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int getTotalCount();
    virtual bool isEmpty();
    virtual void slot1C();
    virtual void advance();
};

// TU-local view of the record holder covering exactly the fields this unit
// touches: vptr at +0x00, chained holder at +0x04, record array at +0x08 and
// the count of records the array still serves at +0x0C.
class DededeArticleRecordHolder : public DededeArticleRecordProvider {
public:
    DededeArticleRecordProvider* next; // +0x04: chained holder or null
    DededeArticleRecord* array; // +0x08: cursor into the record array
    int count; // +0x0C: records the array still serves
};
static_assert(sizeof(DededeArticleRecordHolder) == 0x10, "Holder view layout");
} // namespace

extern "C" void fn_117_18050(DededeArticleRecordHolder* self) {
    if (self->isEmpty()) {
        return;
    }
    int count = self->count;
    if (count > 0) {
        self->count = count - 1;
        if (count - 1 <= 0) {
            self->array = 0;
        } else {
            self->array += 1;
        }
    } else if (self->next != 0) {
        self->next->advance();
    }
}
