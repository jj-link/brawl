#pragma force_active on
extern "C" void fn_95_7F30(void* self, unsigned char v);
extern "C" char lbl_95_data_2C74[];

struct Yoshi95Work {
    void* vtTail;   // +0x00
    int pad04;      // +0x04
    void* vtBase;   // +0x08
    int a1;         // +0x0C
    int a2;         // +0x10
    int a3;         // +0x14
    int a4;         // +0x18
    int a5;         // +0x1C
    int a6;         // +0x20
};

extern "C" void* fn_95_9118(void* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    Yoshi95Work* w = (Yoshi95Work*)self;
    fn_95_7F30(self, 0);
    w->vtBase = lbl_95_data_2C74;
    w->vtTail = lbl_95_data_2C74 + 8;
    w->a1 = a1;
    w->a2 = a2;
    w->a3 = a3;
    w->a4 = a4;
    w->a5 = a5;
    w->a6 = a6;
    return self;
}
