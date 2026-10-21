#pragma force_active on
// fn_801590A0: set/clear a bit in a word-array owned by the struct at arg0.

typedef unsigned int u32;

struct Bitset {
    u32 size;
    u32* words;
};

extern "C" void fn_801590A0(Bitset* bs, u32 index, u32 set) {
    u32 word = index >> 5;
    u32 bit = index & 0x1F;
    if (set == 1) {
        bs->words[word] |= 1u << bit;
    } else {
        bs->words[word] &= ~(1u << bit);
    }
}
