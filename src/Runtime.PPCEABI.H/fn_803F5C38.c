// Buffered stream position, accounting for pending bytes and translated newlines.
struct FILE;

extern int lbl_805A12E0; // errno

int fn_803F5C38(struct FILE* stream) {
    unsigned long pos_24;
    unsigned long state;
    unsigned long count;
    unsigned char* p;
    unsigned long pos_34;
    unsigned long offset_1c;
    unsigned long scan_len;
    unsigned long mode;
    int result;
    unsigned long buffered_1;

    mode = *(unsigned long*) ((char*) stream + 0x4);
    count = 0;
    buffered_1 = (mode >> 22) & 7;
    if ((unsigned char) (buffered_1 + 0xff) > 1 ||
        *(unsigned char*) ((char*) stream + 0xa) != 0) {
        lbl_805A12E0 = 0x28;
        return -1;
    }

    state = *(unsigned long*) ((char*) stream + 0x8) >> 29;
    if (state == 0) {
        return *(unsigned long*) ((char*) stream + 0x18);
    }

    offset_1c = *(unsigned long*) ((char*) stream + 0x1c);
    pos_24 = *(unsigned long*) ((char*) stream + 0x24);
    pos_24 -= offset_1c;
    pos_34 = *(unsigned long*) ((char*) stream + 0x34) + pos_24;
    if (state >= 3) {
        count = state - 2;
        pos_34 -= count;
    }

    if ((((*(volatile unsigned long*) ((char*) stream + 0x4)) >> 19) & 1) == 0) {
        for (scan_len = pos_24 - count, p = (unsigned char*) offset_1c; scan_len != 0; scan_len--) {
            if (*p++ == '\n') {
                pos_34++;
            }
        }
    }

    result = pos_34;
    return result;
}
