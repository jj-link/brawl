#pragma force_active on
class ecMgr;

extern int lbl_805A014C;
extern int lbl_805A0150;
extern int lbl_805A0154;
extern int lbl_805A0158;
extern int lbl_805A015C;
extern int lbl_805A0160;

class ecMgr {
public:
    void preSetAnmIdx(int, int, int, int, int, int);
};

void ecMgr::preSetAnmIdx(int a0, int a1, int a2, int a3, int a4, int a5) {
    lbl_805A014C = a0;
    lbl_805A0150 = a1;
    lbl_805A0154 = a2;
    lbl_805A0158 = a3;
    lbl_805A015C = a4;
    lbl_805A0160 = a5;
}
