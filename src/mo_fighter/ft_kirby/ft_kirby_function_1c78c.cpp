#pragma force_active on
// fn_96_1C78C (ft_kirby, 16 bytes)
//
// The original words at .text[0x1C78C,0x1C79C) are 80630000 1C04000C
// 7C630214 4E800020, i.e. lwz r3, 0x0(r3); mulli r0, r4, 0xC; add r3, r3, r0;
// blr. There is no memory barrier or branch elsewhere in this sequence, so the
// whole body is the address computation itself: the array base is *not* the
// argument, it is fetched from the first word of the object the argument
// points at, the index is scaled by the 12-byte record stride and the sum is
// returned. The parameter types below therefore describe a table header whose
// first field is the record pointer, plus the element size used for the
// scaling; nothing is dereferenced, so the record contents stay opaque.
struct Record {
    char data[12];
};

struct RecordTable {
    Record* array;
};

extern "C" Record* fn_96_1C78C(RecordTable* table, int index) {
    return &table->array[index];
}
