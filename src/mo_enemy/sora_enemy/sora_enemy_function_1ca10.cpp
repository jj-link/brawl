#pragma force_active on
struct Unk {
    char pad[0x48];
    unsigned char unk48;
};

extern "C" bool fn_41_1AE7C(Unk* p);

extern "C" unsigned char fn_41_1CA10(Unk* p) {
    if (fn_41_1AE7C(p) == 1) {
        return 1;
    }
    return p->unk48;
}
