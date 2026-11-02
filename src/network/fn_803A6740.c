#pragma force_active on

typedef struct {
    int (*f0)(void);
    void (*f4)(int, int, int);
    int f8;
    int fc;
    int f10;
    int count;
} SOState;

extern SOState lbl_80537680;
extern int lbl_8059FE14;

int fn_803A6740(int arg0, int arg1)
{
    int temp;
    int result;
    unsigned int masked;

    if (arg1 > 0 && lbl_80537680.f0 != 0) {
        temp = lbl_80537680.f0();
        result = temp;
        if (temp != 0) {
            lbl_80537680.count++;
            if (lbl_8059FE14 != 0) {
                masked = temp & 0x1FFFFFFF;
                if (masked < 0x10000000U || masked >= 0x18000000U) {
                    if (temp != 0 && lbl_80537680.f4 != 0) {
                        lbl_80537680.count--;
                        lbl_80537680.f4(arg0, temp, arg1);
                    }
                    result = 0;
                }
            }
        }
        return result;
    }
    return 0;
}
