#pragma force_active on
extern "C" int fn_27_8D3E4(void* p);

extern "C" void fn_27_337104(char* arg0) {
    int i;
    char* r3;

    i = 0;
    do {
        if (i == 5) {
            r3 = arg0 + 0x9CA8;
        } else if (i == 4) {
            r3 = arg0 + 0x7D5C;
        } else if (i == 3) {
            r3 = arg0 + 0x5E10;
        } else if (i == 2) {
            r3 = arg0 + 0x3EC4;
        } else if (i == 1) {
            r3 = arg0 + 0x1F78;
        } else if (i == 0) {
            r3 = arg0 + 0x2C;
        } else {
            r3 = 0;
        }
        if (fn_27_8D3E4(r3 + 0x88) == 0) {
            break;
        }
        i++;
    } while (i < 6);
}
