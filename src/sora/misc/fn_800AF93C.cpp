#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    int c;
    int d;
} MuStockEntry;

extern MuStockEntry lbl_80455458[];

unsigned char getFighterColorFileNo__6muMenuFiii(int a, int b, int c) {
    unsigned char *p = (unsigned char *)lbl_80455458[a].c + b * 2;
    return p[1];
}
}
