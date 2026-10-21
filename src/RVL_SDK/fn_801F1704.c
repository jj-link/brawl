#pragma force_active on
typedef struct {
    unsigned rest : 30;
    unsigned lo : 1;
    unsigned hi : 1;
} Bits;

extern unsigned int* __GXData;

void fn_801F1704(unsigned int arg0) {
    Bits* p1 = (Bits*)((unsigned char*)__GXData + 0x23C);
    Bits* p2 = (Bits*)((unsigned char*)__GXData + 0x24C);
    p1->hi = arg0;
    p1->lo = arg0 >> 1;
    p2->hi = arg0;
    p2->lo = arg0 >> 1;
}
