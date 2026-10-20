#pragma force_active on
struct Obj {
    char pad[0x1c];
    unsigned char pre : 3;
    unsigned char bit : 1;
    unsigned char post : 4;
};

extern "C" {
bool fn_27_111EC0(Obj **p) {
    return (*p)->bit != 0;
}
}
