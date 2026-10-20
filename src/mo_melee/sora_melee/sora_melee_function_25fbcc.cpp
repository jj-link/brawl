#pragma force_active on
class Ground {
public:
    void setupMelee();
    unsigned char pad[0x6c];
    signed char unk6c;
    unsigned char unk6d;
};

void Ground::setupMelee() {
    int a = unk6c;
    a = a & ~1;
    unk6c = a;
    unk6d = unk6d | 1;
}
