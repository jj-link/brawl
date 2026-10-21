#pragma force_active on

struct FloatBlock {
    float x;
    float y;
    float z;
    float copyX;
    float copyY;
    float copyZ;
};

struct FloatBlockArray {
    virtual void* unknown();
    virtual FloatBlock* at(int index);
    virtual void* unknown1();
    virtual int size();
};

struct FloatBlockOwner {
    unsigned char pad[0x5C];
    FloatBlockArray* blocks;
};

extern "C" void fn_27_253B4(FloatBlock*);

extern "C" void fn_27_237B0(FloatBlockOwner* p) {
    fn_27_253B4((FloatBlock*)p);
    int count = p->blocks->size();
    for (int i = 0; i < count; ++i) {
        FloatBlock* block = p->blocks->at(i);
        block->copyX = block->x;
        block->copyY = block->y;
        block->copyZ = block->z;
    }
}
