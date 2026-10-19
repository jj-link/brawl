#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a;
    unsigned char b;
    unsigned char c[3];
} SelEntry;

typedef struct {
    unsigned short a;
    unsigned short b;
} SubEntry;

extern const SelEntry lbl_11_rodata_280[];

unsigned short fn_11_85CC(int idx, int subidx) {
    return ((const SubEntry *)lbl_11_rodata_280[idx].a)[subidx].a;
}
}
