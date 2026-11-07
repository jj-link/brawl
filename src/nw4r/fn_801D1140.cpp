#pragma force_active on

extern "C" void fn_802022DC(void*, int);

struct Inner { char pad[0x38]; unsigned short type; };
struct Item { Inner* inner; };
struct Ctx {
    char pad0[0xC];
    Item* items[9][4];
    int rows;
    int cols;
    char pad1[0xAD - 0xA4];
    unsigned char flagAD;
    unsigned char flagAE;
    unsigned char flagAF;
    unsigned char flagB0;
};

extern "C" void fn_801D1140(Ctx* arg0) {
    int i;
    int j;
    if (arg0->flagAE != 0) {
        char* row = (char*)arg0;
        for (j = 0; j < arg0->rows; j++) {
            char* p = row;
            for (i = 0; i < arg0->cols; i++) {
                Item* item = *(Item**)(p + 0xC);
                if (item) {
                    Inner* inner = item->inner;
                    int valid = 0;
                    if (inner && inner->type == 1) valid = 1;
                    if (valid) fn_802022DC(inner, 0);
                }
                p += 4;
            }
            row += 0x10;
        }
        arg0->flagAE = 0;
    }
    arg0->flagB0 = 0;
    arg0->flagAF = 0;
    arg0->flagAD = 0;
}
