// fn_92_153C0 returns one integer from the Donkey Kong article-integer accesser
// record: a pointer row is read from the record's table at +0x2C, selected by
// the requested index minus the record's +0x14 base index, and the element-th
// integer of that row is returned. The original words are
// 80030014 7C002850 5400103A 7C630214 8063002C 54C0103A 7C63002E 4E800020.
#include <types.h>
#pragma force_active on

namespace {
struct DonkeyArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest integer index the table serves
    u8 unused[0x2C - 0x18];
    int* rows[8];               // +0x2C: rows[index - firstIndex]
};
} // namespace

extern "C" int fn_92_153C0(DonkeyArticleIntegerAccesser* self, int accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
