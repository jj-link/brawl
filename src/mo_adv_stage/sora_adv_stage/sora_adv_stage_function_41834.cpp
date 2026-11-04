#pragma force_active on

extern "C" void OSReport(const char* fmt, ...);

extern char lbl_40_data_17A88[];

struct Inner {
    char _00[0x50];
    int count;   // 0x50
    int unk54;   // 0x54
    char _58[8];
    int unk60;   // 0x60
};

struct Obj {
    char _00[0xc3c];
    Inner* inner; // 0xc3c
};

extern "C" void fn_40_41834(Obj* arg0) {
    char* base = lbl_40_data_17A88;
    if (arg0->inner != 0) {
        OSReport(base + 0x1e8);
        OSReport(base + 0x210);
        int off;
        int i = 0;
        off = 0;
        while (i < arg0->inner->count) {
            OSReport(base + 0x228, i + 1, *(int*)((char*)arg0->inner + off));
            off += 4;
            i += 1;
        }
        OSReport(base + 0x234);
        OSReport(base + 0x24c, arg0->inner->unk54);
        OSReport(base + 0x258);
        OSReport(base + 0x268, arg0->inner->unk60);
    }
}
