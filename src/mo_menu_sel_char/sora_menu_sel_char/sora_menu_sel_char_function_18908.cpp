#pragma force_active on
extern "C" {
struct ColorRGBA {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct FontTextBuf {
    ColorRGBA color;
    char text[28];
};

extern const unsigned char lbl_10_rodata_6B4[4];
extern const ColorRGBA lbl_10_rodata_750[6];
extern void* g_GameGlobal;

void setFontColor__5MuMsgFUlUcUcUcUc(void* msg, unsigned long index, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long index, unsigned long value, void* extra);
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
int fn_8004D6C4(void* global, int index, char* out);
void fn_10_11720(void* self, char* buf);

void fn_10_18908(void* self, int index, int mode, int flag, int tableIdx) {
    int colorIdx;
    FontTextBuf tb;
    int printMode = -1;
    int found = 0;

    switch (mode) {
    case 0:
        colorIdx = 5;
        break;
    case 2:
        colorIdx = 4;
        break;
    case 1:
        if (flag) {
            colorIdx = lbl_10_rodata_6B4[tableIdx];
        } else {
            colorIdx = *(int*)((char*)self + 0x1B0);
        }
        break;
    }

    void* msg = *(void**)((char*)self + 0x40C);
    const ColorRGBA* col = &lbl_10_rodata_750[colorIdx];
    tb.color = *col;
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 0, col->r, col->g, col->b, 0xff);

    switch (mode) {
    case 1:
        if (index >= 0) {
            if (fn_8004D6C4(g_GameGlobal, index, tb.text)) {
                found = 1;
            }
        }
        if (!found) {
            fn_10_11720(self, tb.text);
        }
        break;
    case 2:
        printMode = 2;
        break;
    case 0:
        printMode = 3;
        break;
    }

    if (printMode >= 0) {
        printIndex__5MuMsgFUlUlPv(*(void**)((char*)self + 0x40C), 0, printMode, 0);
    } else {
        printf__5MuMsgFUlPCce(*(void**)((char*)self + 0x40C), 0, tb.text);
    }
}
}
