#pragma force_active on
typedef struct {
    unsigned int words[4];
} Block;

extern const Block lbl_8040D9A0;
extern char lbl_80529CF8[];

void fn_8023E554(void) {
    *(unsigned short*)(lbl_80529CF8 + 0x18F6) = 0xFFFF;
    *(Block*)(lbl_80529CF8 + 0x18F8) = lbl_8040D9A0;
    *(unsigned char*)(lbl_80529CF8 + 0x1909) = 2;
}
