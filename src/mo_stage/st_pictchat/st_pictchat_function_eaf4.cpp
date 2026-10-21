#pragma force_active on
struct A { char pad[0x3c]; };
struct PictChat : A {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
    virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23();
    virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27();
    virtual void a28(); virtual void a29(); virtual void a30(); virtual void a31();
    virtual void a32(); virtual void a33(); virtual void a34(); virtual void a35();
    virtual void a36(); virtual void a37(); virtual void a38(); virtual void a39();
    virtual void a40(); virtual void a41(); virtual void a42(); virtual void a43();
    virtual void a44(); virtual void a45(); virtual void a46(); virtual void a47();
    virtual void a48(); virtual void a49(); virtual void a50(); virtual void a51();
    virtual void a52(); virtual void a53(); virtual void a54(); virtual void a55();
    virtual void a56(); virtual void a57(); virtual void a58(); virtual void a59();
    virtual void a60(); virtual void a61(); virtual void a62(); virtual void a63();
    virtual void a64(); virtual void a65(); virtual void a66(); virtual void a67();
    virtual void a68(); virtual void a69(); virtual void a70(); virtual void a71();
    virtual void a72(); virtual void a73(); virtual void a74(); virtual void a75();
    virtual void a76(); virtual void a77(); virtual void a78(); virtual void a79();
    virtual void a80(); virtual void a81(); virtual void a82(); virtual void a83();
    virtual void a84(); virtual void a85(); virtual void a86(); virtual void a87();
    virtual void a88(); virtual void a89(); virtual void a90(); virtual void a91();
    virtual void a92(); virtual void a93(); virtual void a94(); virtual void a95();
    virtual void a96(); virtual void a97(); virtual void a98(int); virtual void a99();
    virtual void a100(); virtual void a101(); virtual void a102(); virtual void a103();
    virtual void a104(); virtual void a105(); virtual void a106(); virtual void a107();
    virtual void a108(); virtual void a109(); virtual void a110(); virtual void a111();
    virtual void a112(); virtual void a113(); virtual void a114(); virtual void a115();
    virtual void a116(); virtual void a117();

    char pad1[0x10c];
    int f14c;
    char pad2[0xc];
    void* f15c;
    void* f160;
    unsigned char f164;
    unsigned char f165;
    unsigned char f166;
};

extern "C" void fn_73_EAF4(PictChat* self) {
    if (self->f165 == 1) {
        if (*(unsigned char*)self->f160 == self->f164 &&
            *(unsigned char*)self->f15c == 4) {
            self->a115();
            return;
        }
        if (self->f166 == 1) {
            self->a98(0);
            self->f166 = 0;
        }
    } else {
        self->a114();
        if (self->f14c != 0) {
            self->f165 = 1;
        }
    }
}
