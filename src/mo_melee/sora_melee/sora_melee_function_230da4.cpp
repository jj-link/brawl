#pragma force_active on
typedef unsigned char u8;

class Ground;

class Stage {
public:
    Ground* getGround(int idx);
};

extern "C" {
void endEntity__8grMadeinFv(void* self);
void fn_27_230DA4(Stage* self);
}

void fn_27_230DA4(Stage* self) {
    u8* base = (u8*)self;
    if (base[0x1E7] & 1) {
        endEntity__8grMadeinFv(self->getGround(0));
        base[0x1E7] &= ~1;
    }
    void* p = *(void**)(base + 0x1E8);
    if (p != 0 && (base[0x1E7] & 2)) {
        endEntity__8grMadeinFv(p);
        base[0x1E7] &= ~2;
    }
}
