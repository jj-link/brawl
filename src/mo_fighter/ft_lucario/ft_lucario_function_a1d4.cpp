#pragma force_active on
struct FootPos {
    float x;
    float y;
    float z;
};

// Returns the FootPos entry at @p index within the array rooted at @p base:
// base + index * 8 + 4 (the first 4 bytes of each 8-byte slot are skipped).
// The original code evaluates base + index * 8 + 4 in a single add, so the
// pointer arithmetic is spelled out to keep the instruction schedule identical.
extern "C" FootPos* fn_118_A1D4(FootPos* base, int index) {
    return (FootPos *)((char *)base + (index << 3) + 4);
}
