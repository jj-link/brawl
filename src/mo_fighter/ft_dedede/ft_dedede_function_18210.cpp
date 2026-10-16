// fn_117_18210 returns a pointer to one 0x6C-byte record from Dedede's
// chained article-record holder. The original words at .text[0x18210,0x18250)
// are 8003000C 7C040000 41800028 80A30004 2C050000 4182001C 7CA32B78
// 7C802050 81850000 818C000C 7D8903A6 4E800420 80630008 1C04006C 7C630214
// 4E800020, i.e. lwz r0, 0xC(r3); cmpw r4, r0; blt .+0x28; lwz r5, 4(r3);
// cmpwi r5, 0; beq .+0x1C; mr r3, r5; subf r4, r0, r4; lwz r12, 0(r5);
// lwz r12, 0xC(r12); mtctr r12; bctr; lwz r3, 8(r3); mulli r0, r4, 0x6C;
// add r3, r3, r0; blr.
//
// No relocation hits [0x18210,0x18250) in any import stream of ft_dedede.rel
// (m27/m117/m0). The only reference to this unit is an R_PPC_ADDR32 pointer
// at .data+0x94D8 (m117 stream, symsec 1, addend 0x18210), the tenth entry of
// the .data callback table at .data+0x94B4 whose other entries point at the
// sibling record-holder methods fn_117_18208/18030/18040/181A8/18250/17F7C/
// 18050/180E0/18158 (evidence/rel_decode_18210.py, which also reproduces the
// machine-confirmed anchors m27 0xE20C->0x135468, 0xE274->0x135EB4 and
// 0xE27C->0x13C428 exactly). The comparison target is the canonical
// dtk-sliced object build/RSBE01_02/ft_dedede/obj/mo_fighter/ft_dedede/
// ft_dedede_function_18210.o, whose .text is exactly the owned 0x40 bytes
// with no relocations; supporting windowed comparisons restrict the
// pre-registration gap-fallback object's .text to the owned window.
//
// The holder is the head of a chain: +0x08 points at an array of 0x6C-byte
// records and +0x0C counts how many records that array serves, while +0x04
// optionally points at a chained holder serving the indices past the array
// (the sibling cluster confirms the layout: fn_117_181A8 totals
// (array ? count : 0) + next->vtable[0x14](), fn_117_18050 advances the
// array pointer by exactly 0x6C while decrementing the count, and
// fn_117_180E0 / fn_117_18158 forward the same lifecycle to the chained
// holder). For an index at or past the served count with a chained holder
// present, this unit tail-calls the chain's second virtual (vtable offset
// 0xC, the same slot convention as the committed accesser selectors, where
// the first declared virtual is slot 0x8) with the index adjusted by the
// served count; otherwise it indexes the array directly.
#include <StaticAssert.h>
#include <types.h>

namespace {
// One 0x6C-byte record served by the holder; this unit only computes its
// address, so the contents stay opaque.
struct DededeArticleRecord {
    u8 data[0x6C];
};
static_assert(sizeof(DededeArticleRecord) == 0x6C, "Record element size");

// Interface of a chained record holder. The second declared virtual sits at
// vtable offset 0xC (the slot this unit tail-calls), matching the committed
// selector convention where the first declared virtual is slot 0x8.
class DededeArticleRecordProvider {
public:
    virtual void slot08();
    virtual DededeArticleRecord* getRecord(int index);
};

// TU-local view of the record holder covering exactly the fields this unit
// touches. The holder is polymorphic in the original module (the sibling
// cluster reads its own vtable), so the leading word is reserved for the
// vptr and kept opaque here.
struct DededeArticleRecordHolder {
    u8 vptr[4]; // +0x00: holder vtable pointer, unused by this unit
    DededeArticleRecordProvider* next; // +0x04: chained holder or null
    DededeArticleRecord* array; // +0x08: record array
    int count; // +0x0C: records the array serves
};
static_assert(sizeof(DededeArticleRecordHolder) == 0x10, "Holder view layout");
} // namespace

extern "C" DededeArticleRecord* fn_117_18210(DededeArticleRecordHolder* self,
                                             int index) {
    if (index >= self->count && self->next != 0) {
        return self->next->getRecord(index - self->count);
    }
    return &self->array[index];
}
