#pragma force_active on
extern "C" {

bool fn_8004F4A0(int);

struct UnkRecord {
    unsigned char unk00[0x14];
    char unk14;
    unsigned char unk15[0x3B];
};

int fn_1_26890(UnkRecord* rec) {
    int flag = 1;
    for (int i = 1; i < 4; ++i) {
        int value = rec[i - 1].unk14;
        switch (value) {
            case 72: value = 0x1d; break;
            case 73: value = 3; break;
            case 74: value = 0x0e; break;
        }
        if (value != -1 && fn_8004F4A0(value) == false) {
            flag = 0;
        }
    }
    return flag;
}

}
