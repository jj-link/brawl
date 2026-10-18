#pragma force_active on
struct RobotWork {
    void* vtSecondary;   // +0x00
    int field04;         // +0x04 (not written by this function)
    void* vtPrimary;     // +0x08
    int a0C;             // +0x0C
    int a10;             // +0x10
    int a14;             // +0x14
    int a18;             // +0x18
    int a1C;             // +0x1C
    int a20;             // +0x20
};

extern "C" void fn_120_5BD8(void* p, unsigned char v);
extern "C" char lbl_120_data_2244[];

extern "C" RobotWork* fn_120_6DC0(RobotWork* work, int a, int b, int c, int d, int e, int f) {
    fn_120_5BD8(work, 0);
    work->vtPrimary = lbl_120_data_2244;
    work->vtSecondary = lbl_120_data_2244 + 8;
    work->a0C = a;
    work->a10 = b;
    work->a14 = c;
    work->a18 = d;
    work->a1C = e;
    work->a20 = f;
    return work;
}
