#pragma force_active on

struct Work {
    void* first;
    void* second;
    unsigned short count;
    unsigned short count2;
    int value;
    int value2;
};

struct State {
    int value;
    Work* work;
    unsigned char bytes[8];
};

extern "C" {
void fn_8001BB1C();
void fn_8001BB8C();
void fn_803EC154(int, void (*)(), void (*)());
void fn_803EBFCC(int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void fn_803EBC54(int, int, int, State*);
int fn_803EC094(int);
void fn_801FC318(void*, const void*, const void*, int, int);

extern State lbl_80494928;
extern unsigned char lbl_80494938[];
extern int lbl_8059C52C;
extern unsigned char lbl_8059FFDC;
extern const unsigned char lbl_805A14B0[8];
extern const unsigned char lbl_805A14B8[8];

void fn_8001BBB8() {
    fn_803EC154(0, fn_8001BB1C, fn_8001BB8C);
    fn_803EBFCC(0x10000);

    lbl_80494928.value = 0;
    lbl_80494928.work = 0;

    Work* work =
        (Work*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(1, 0x1194);
    work->first = (char*)work + 0x20;
    work->second = (char*)work + 0x160;
    work->count = 4;
    work->count2 = 4;
    work->value = 1;
    work->value2 = 1;
    lbl_80494928.work = work;

    fn_803EBC54(0, 0, 0, &lbl_80494928);

    if (lbl_80494928.bytes[1] & 0x10) {
        lbl_8059C52C = 1;
        int enabled = 0;
        lbl_8059FFDC = 1;

        if (fn_803EC094(0x41) == 1) {
            enabled = 1;
        }
        if (enabled) {
            lbl_8059C52C = 3;
        }
    }

    fn_801FC318(lbl_80494938, lbl_805A14B0, lbl_805A14B8, 0, 2);
}
}
