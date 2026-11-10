#pragma force_active on
#define U(a,b,c,d) virtual void u##a(); virtual void u##b(); virtual void u##c(); virtual void u##d();

struct Ground {
    char pad[0x3c];
    virtual void u0();
    virtual void u1();
    U(4,5,6,7)
    U(8,9,10,11)
    U(12,13,14,15)
    U(16,17,18,19)
    U(20,21,22,23)
    U(24,25,26,27)
    U(28,29,30,31)
    U(32,33,34,35)
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void s39(void*, int, int);
    virtual void u40();
    virtual void s41(void*);
    U(42,43,44,45)
    U(46,47,48,49)
    U(50,51,52,53)
    U(54,55,56,57)
    U(58,59,60,61)
    U(62,63,64,65)
    U(66,67,68,69)
    U(70,71,72,73)
    U(74,75,76,77)
    U(78,79,80,81)
    U(82,83,84,85)
    U(86,87,88,89)
    U(90,91,92,93)
    U(94,95,96,97)
    U(98,99,100,101)
    U(102,103,104,105)
    U(106,107,108,109)
    U(110,111,112,113)
    virtual void s114(void*);
    virtual void u115();
    virtual void s116(void*);
    virtual void s117(void*);
    virtual void s118(void*);
    virtual void s119(void*);
    virtual void s120(void*);
    virtual void s121(int);
};

struct Stage {
    char pad0[0x9c];
    void* data9C;
    char pad1[0x100];
    void* data1A0;
    char pad2[0x34];
    char data1D8[0x60];
    char data238[0x20];
    char data258[2];
    char data25A[1];
    char data25B[1];
    char data25C[1];
};

extern "C" {

extern char lbl_78_data_0[];

Ground* fn_78_2CAC(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_78_8E8(Stage* stage, int kind) {
    Ground* ground;
    int id;
    const char* data = lbl_78_data_0;

    switch (kind) {
    case 6:
        ground = fn_78_2CAC(5, data + 0xe8, data + 0xfc);
        id = 0;
        break;
    case 7:
        ground = fn_78_2CAC(6, data + 0x110, data + 0x124);
        id = 1;
        break;
    case 8:
        ground = fn_78_2CAC(7, data + 0x138, data + 0x148);
        id = 2;
        break;
    case 9:
        ground = fn_78_2CAC(8, data + 0x158, data + 0x170);
        id = 3;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->s39(stage->data1A0, 0, 0);
        ground->s41(stage->data9C);
        ground->s114(stage->data1D8);
        ground->s116(stage->data238);
        ground->s117(stage->data258);
        ground->s118(stage->data25A);
        ground->s119(stage->data25B);
        ground->s120(stage->data25C);
        ground->s121(id);
    }
}

}
