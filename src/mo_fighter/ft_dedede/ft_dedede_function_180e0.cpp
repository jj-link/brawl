// fn_117_180E0 is the eighth virtual of Dedede's chained article-record
// holder (the R_PPC_ADDR32 entry at .data+0x94D0 in the holder vtable whose
// method entries start at .data+0x94B4). The original words at
// .text[0x180E0,0x18158) are 9421FFF0 7C0802A6 90010014 93E1000C 7C7F1B78
// 80630004 2C030000 41820034 81830000 818C0018 7D8903A6 4E800421 2C030000
// 4082001C 807F0004 81830000 818C0024 7D8903A6 4E800421 48000018 807F000C
// 2C030000 4081000C 3803FFFF 901F000C 83E1000C 80010014 7C0803A6 38210010
// 4E800020, i.e. stwu r1,-0x10(r1); mflr r0; stw r0,0x14(r1); stw r31,0xC(r1);
// mr r31,r3; lwz r3,4(r3); cmpwi r3,0; beq .+0x34; lwz r12,0(r3);
// lwz r12,0x18(r12); mtctr r12; bctrl; cmpwi r3,0; bne .+0x1C;
// lwz r3,4(r31); lwz r12,0(r3); lwz r12,0x24(r12); mtctr r12; bctrl;
// b .+0x18; lwz r3,0xC(r31); cmpwi r3,0; ble .+0xC; addi r0,r3,-1;
// stw r0,0xC(r31); lwz r31,0xC(r1); lwz r0,0x14(r1); mtlr r0;
// addi r1,r1,0x10; blr.
//
// No relocation hits [0x180E0,0x18158) in any import stream of ft_dedede.rel
// (m27/m117/m0). The only reference to this unit is one R_PPC_ADDR32 pointer
// at .data+0x94D0 (m117 stream, symsec 1, addend 0x180E0), the eighth method
// entry of the .data holder vtable at .data+0x94B4 whose entries point at the
// sibling record-holder methods fn_117_18208/18030/18040/181A8/18250/17F7C/
// 18050/180E0/18158/18210 (evidence/rel_decode_180e0.py, which also
// reproduces the machine-confirmed anchors m27 0xE20C->0x135468,
// 0xE274->0x135EB4 and 0xE27C->0x13C428 exactly). The comparison target is
// the canonical dtk-sliced object build/RSBE01_02/ft_dedede/obj/mo_fighter/
// ft_dedede/ft_dedede_function_180e0.o, whose .text is exactly the owned
// 0x78 bytes with no relocations; supporting windowed comparisons restrict
// the pre-registration gap-fallback object's .text to the owned window at
// .text offset 0xC8 (0x180E0 - 0x18018).
//
// Behaviour: when a chained holder is present, its fifth virtual (vtable
// offset 0x18, the same slot convention as the committed accesser selectors,
// where the first declared virtual is slot 0x8) is consulted; when it reports
// zero, the lifecycle call is forwarded to the chain's eighth virtual (vtable
// offset 0x24) and the holder's own count is left untouched. Otherwise (or
// when no chained holder is present) the record count at +0x0C is decremented
// only while it stays positive. The original reloads self->next before the
// second dispatch (lwz r3, 4(r31) after the first bctrl), so the source does
// not cache the chained pointer across the call.
#include <StaticAssert.h>
#include <types.h>

namespace {
// One 0x6C-byte record served by the holder; this unit only updates the
// serving count, so the record contents stay opaque.
struct DededeArticleRecord {
    u8 data[0x6C];
};
static_assert(sizeof(DededeArticleRecord) == 0x6C, "Record element size");

// Interface of a chained record holder. The fifth declared virtual sits at
// vtable offset 0x18 and the eighth at 0x24 (the two slots this unit
// dispatches), matching the committed selector convention where the first
// declared virtual is slot 0x8.
class DededeArticleRecordProvider {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
};

// TU-local view of the record holder covering exactly the fields this unit
// touches. The holder is polymorphic in the original module (the .data
// vtable at .data+0x94B4 points at the sibling methods), so the leading word
// is reserved for the vptr and kept opaque here.
struct DededeArticleRecordHolder {
    u8 vptr[4]; // +0x00: holder vtable pointer, unused by this unit
    DededeArticleRecordProvider* next; // +0x04: chained holder or null
    DededeArticleRecord* array; // +0x08: record array, unused by this unit
    int count; // +0x0C: records the array serves
};
static_assert(sizeof(DededeArticleRecordHolder) == 0x10, "Holder view layout");
} // namespace

extern "C" void fn_117_180E0(DededeArticleRecordHolder* self) {
    if (self->next != 0 && self->next->slot18() == 0) {
        self->next->slot24();
    } else {
        if (self->count > 0) {
            self->count = self->count - 1;
        }
    }
}
