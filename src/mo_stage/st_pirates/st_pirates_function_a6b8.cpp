#pragma force_active on
struct Flags {
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
};

extern "C" void fn_52_A6B8(unsigned char* self) {
    unsigned char* sub = *(unsigned char**)(self + 0x170);
    Flags* f;
    if (sub == 0) {
        return;
    }
    f = (Flags*)(sub + 0x54);
    switch (self[0x150]) {
    case 4:
    case 10:
        f->b7 = 0;
        f->b4 = f->b7;
        f->b6 = f->b4;
        break;
    default:
        f->b4 = 1;
        f->b6 = f->b4;
        break;
    }
}
