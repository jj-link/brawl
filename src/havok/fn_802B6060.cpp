#pragma force_active on
// Release a heap block when requested, preserving its pointer.
extern "C" {
void __dl__FPv(void*);
}

extern "C" {
void* __dt__14Class_802B6060Fv(void* block, int destroy) {
    if (block != 0 && destroy > 0) {
        __dl__FPv(block);
    }
    return block;
}
}
