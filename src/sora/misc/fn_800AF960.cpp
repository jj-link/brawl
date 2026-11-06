#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_80455458[];

class muMenu {
public:
    int getCharColorNo(int a, int b, int c);
};

int muMenu::getCharColorNo(int a, int b, int c) {
    u8* e = lbl_80455458;
    e += ((u32)this) << 4;
    int count = 0;
    u8* p = *(u8**)(e + 8);
    while (*p != 0xC) {
        p += 2;
        count++;
    }
    u8* q = ((u8**)e)[2];
    int i;
    for (i = 0; i < count; i++) {
        if (a == *q) {
            return i;
        }
        q += 2;
    }
    return -1;
}
