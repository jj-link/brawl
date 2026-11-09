#pragma force_active on
extern unsigned char lbl_8052C9B8[0x408];
int fn_8024A1DC(int index);

int fn_80247E58(unsigned int index)
{
    if (lbl_8052C9B8[0x400] == 0) {
        return 1;
    }
    if (index > 16 || lbl_8052C9B8[index * 0x34] == 0) {
        return 5;
    }
    if (*(lbl_8052C9B8 + index * 0x34 + 0xa) != 0) {
        return 0xa;
    }
    lbl_8052C9B8[index * 0x34 + 0xc] = 1;
    return fn_8024A1DC(index);
}
