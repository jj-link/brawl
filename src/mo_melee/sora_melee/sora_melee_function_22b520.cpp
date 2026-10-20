#pragma force_active on
struct Source {
    unsigned char pad0[0x40];
    unsigned int value40;
    unsigned char pad44[0xC];
    unsigned int value50;
};

struct Destination {
    unsigned char pad0[0x7C];
    unsigned int value7C;
    unsigned int value80;

    void set(unsigned int a, unsigned int b) {
        value7C = a;
        value80 = b;
    }
};

extern "C" Destination* lbl_8049DEC8;

extern "C" void fn_27_22B520(Source* source) {
    if (lbl_8049DEC8) {
        lbl_8049DEC8->set(source->value40, source->value50);
    }
}
