#pragma force_active on
struct fn27Bits {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
};

struct fn27Inner {
    char pad[0x1f];
    fn27Bits flags;
};

extern "C" {
bool fn_27_111F1C(fn27Inner** p) {
    return (*p)->flags.b != 0;
}
}
