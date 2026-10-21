#pragma force_active on
typedef unsigned char u8;

class muMenu {
public:
    int getNumCharColor(int, int, int);
};

extern u8 lbl_80455458[];

int muMenu::getNumCharColor(int a, int b, int c) {
    u8 *p = *(u8 **)(lbl_80455458 + ((int)this << 4) + 8);
    int count = 0;
    while (*p != 0xC) {
        p += 2;
        count++;
    }
    return count;
}
