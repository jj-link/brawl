#pragma force_active on
extern void fn_803A9644(void*, void*, int);

int fn_803C7460(void* arg0) {
    unsigned char buf[32];
    fn_803A9644(buf, arg0, 0x20);
    if ((int)buf[0] != 'V' || (int)buf[1] != 'F' || (int)buf[2] != 'F' || (int)buf[3] != ' ') {
        return 0;
    }
    return 1;
}
