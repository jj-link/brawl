#pragma force_active on
extern "C" void fn_802F8E7C(void*);

struct S_0x8 {
    void* unk0;
    void* unk4;
    void* unk8;
};

struct S_0x14 {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
    S_0x8* unk14;
};

extern "C" {
void fn_802EA80C(int a, struct S_0x14* b) {
    fn_802F8E7C(b->unk14->unk8);
}
}
