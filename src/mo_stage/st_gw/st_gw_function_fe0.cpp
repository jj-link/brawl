#pragma force_active on

#define U(a,b,c,d) virtual void u##a(); virtual void u##b(); virtual void u##c(); virtual void u##d();

struct Ground {
    char pad[0x3c];
    U(0,1,2,3)
    U(4,5,6,7)
    U(8,9,10,11)
    U(12,13,14,15)
    U(16,17,18,19)
    U(20,21,22,23)
    U(24,25,26,27)
    U(28,29,30,31)
    U(32,33,34,35)
    virtual void u36();
    virtual void g39(void*, int, int);
    virtual void u38();
    virtual void g41(void*);
    U(40,41,42,43)
    U(44,45,46,47)
    U(48,49,50,51)
    U(52,53,54,55)
    U(56,57,58,59)
    U(60,61,62,63)
    U(64,65,66,67)
    U(68,69,70,71)
    U(72,73,74,75)
    U(76,77,78,79)
    U(80,81,82,83)
    U(84,85,86,87)
    U(88,89,90,91)
    U(92,93,94,95)
    U(96,97,98,99)
    U(100,101,102,103)
    U(104,105,106,107)
    U(108,109,110,111)
    virtual void u112();
    virtual void u113();
    virtual void u114();
    virtual void g117(void*);
    virtual void g118(int);
    virtual void u117();
    virtual void g120(void*);
    virtual void g121(void*);
    virtual void g122(void*);
    virtual void g123(void*);
    virtual void g124(void*);
    virtual void g125(int);
};

struct Stage {
    char pad0[0x9c];
    void* data9C;
    char pad1[0x100];
    void* data1A0;
};

extern "C" {

extern char lbl_63_data_0[];

Ground* fn_63_13AE0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_63_FE0(Stage* stage, int kind) {
    Ground* ground;
    int id;
    const char* data = lbl_63_data_0;

    switch (kind) {
    case 11:
        ground = fn_63_13AE0(0x1e, data + 0x20c, data + 0x220);
        id = 6;
        break;
    case 12:
        ground = fn_63_13AE0(0x1f, data + 0x234, data + 0x248);
        id = 7;
        break;
    case 13:
        ground = fn_63_13AE0(0x20, data + 0x25c, data + 0x270);
        id = 8;
        break;
    case 14:
        ground = fn_63_13AE0(0x21, data + 0x284, data + 0x298);
        id = 9;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->g39(stage->data1A0, 0, 0);
        ground->g41(stage->data9C);
        ground->g117((char*)stage + 0x1e0);
        ground->g118(0);
        ground->g120((char*)stage + 0x214);
        ground->g121((char*)stage + 0x305);
        ground->g122((char*)stage + 0x304);
        ground->g124((char*)stage + 0x306);
        ground->g125(id);
        ground->g123((char*)stage + 0x1e4);
    }
}

}
