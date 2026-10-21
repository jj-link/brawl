#pragma force_active on

struct ColorRGBA {
    unsigned char r, g, b, a;
};

struct Local {
    ColorRGBA col;
    char buf[0x14];
};

extern "C" {
extern const unsigned char lbl_10_rodata_6B4[4];
extern const ColorRGBA lbl_10_rodata_750[6];

void setFontColor__5MuMsgFUlUcUcUcUc(
    void*, unsigned long, unsigned char, unsigned char,
    unsigned char, unsigned char);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void fn_8006BCA8(char*, int);

void fn_10_191A0(char* self, int arg1, int arg2, int arg3) {
    Local l;
    unsigned int idx;

    if (arg2 != 0)
        idx = lbl_10_rodata_6B4[arg3];
    else
        idx = *(unsigned int*)(self + 0x1B0);

    void* msg = *(void**)(self + 0x40C);
    const ColorRGBA* col = &lbl_10_rodata_750[idx];
    l.col = *col;

    setFontColor__5MuMsgFUlUcUcUcUc(
        msg, 0x1E, col->r, col->g, col->b, 0xFF);
    fn_8006BCA8(l.buf, arg1);
    printf__5MuMsgFUlPCce(*(void**)(self + 0x40C), 0x1E, l.buf);
}
}
