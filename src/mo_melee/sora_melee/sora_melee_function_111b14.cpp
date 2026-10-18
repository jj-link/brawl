#pragma force_active on
struct Inner {
    char pad[0x34];
    void* unk34;
};

struct Outer {
    Inner* inner;
    char pad[0x6];
    unsigned char unk0a;
};

extern "C" {
void fn_27_111B14(Outer* p, void* v) {
    if (p->unk0a == 1) {
        p->inner->unk34 = v;
    }
}
}
