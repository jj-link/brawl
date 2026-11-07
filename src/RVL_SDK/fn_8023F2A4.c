#pragma force_active on
extern char lbl_80529CF8[];

int fn_8023F2A4(void) {
    char *p = lbl_80529CF8;
    int count = 0;
    switch ((int)*(unsigned short *)(p + 0x185c)) {
    case 2: case 3: case 4: case 5: case 6:
        count++;
    }
    switch ((int)*(unsigned short *)(p + 0x1890)) {
    case 2: case 3: case 4: case 5: case 6:
        count++;
    }
    switch ((int)*(unsigned short *)(p + 0x18c4)) {
    case 2: case 3: case 4: case 5: case 6:
        count++;
    }
    return count;
}