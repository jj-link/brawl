#pragma force_active on
// Release a block's allocation through the global heap allocator.
extern "C" {
extern void* lbl_805A0EC8;
void fn_8027EABC(void*, void*, unsigned int, int);
}

struct Block {
    void* data;
    unsigned short size;
};

extern "C" Block* fn_802E1F28(Block* block, int count) {
    if (block != 0 && count > 0) {
        fn_8027EABC(lbl_805A0EC8, block, block->size, 44);
    }
    return block;
}
