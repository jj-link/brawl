#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_80455458[];

class muMenu {
public:
    u8 getCharColor(int a, int b, int c);
};

u8 muMenu::getCharColor(int a, int b, int c) {
    u8* table = *(u8**)(lbl_80455458 + (((u32)this) << 4) + 8);
    return table[a * 2];
}
