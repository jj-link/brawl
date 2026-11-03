#pragma force_active on

extern unsigned int lbl_805A1210;
extern unsigned int lbl_805A1220;

int fn_803C42D8(unsigned int arg0) {
    unsigned int current;
    unsigned int count;
    unsigned int end;
    int index;

    if (arg0 != 0) {
        count = lbl_805A1210;
        if (count != 0 && lbl_805A1220 != 0) {
            current = lbl_805A1220;
        } else {
            current = 0;
        }
        end = current + count * 0x140;
        index = 0;
        for (; current != end; current += 0x140, index++) {
            if (arg0 == current) {
                return index;
            }
        }
    }
    return -1;
}
