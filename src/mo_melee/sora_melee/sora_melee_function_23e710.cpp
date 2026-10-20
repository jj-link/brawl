#pragma force_active on
struct FnObj27 {
    char pad[0x44];
    unsigned char unk44;
};

extern "C" {
void fn_27_23E710(FnObj27* p) {
    if (p->unk44 == 3) {
        p->unk44 = 2;
    }
}
}
