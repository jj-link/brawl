// fn_123_141DC returns one integer from the Sonic article-integer accesser
// record: a pointer row is read from the record's table at +0x48, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words at
// .text[0x141DC,0x141FC) are 80030014 7C002850 5400103A 7C630214 80630048
// 54C0103A 7C63002E 4E800020, i.e. lwz r0, 0x14(r3); subf r0, r0, r5;
// slwi r0, r0, 2; add r3, r3, r0; lwz r3, 0x48(r3); slwi r0, r6, 2;
// lwzx r3, r3, r0; blr.
//
// Same access pattern as the float counterparts (lwfsx) and the other
// fighters' integer accesser units: row = rows[index - firstIndex];
// return row[element].
#pragma force_active on
namespace {
struct SonicArticleIntegerAccesser {
    unsigned char prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    unsigned char unused[0x48 - 0x18];
    int* rows[1];                // +0x48: rows[index - firstIndex]
};
}

extern "C" int fn_123_141DC(SonicArticleIntegerAccesser* self, void* accesser, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
