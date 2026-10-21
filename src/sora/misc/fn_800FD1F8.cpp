#pragma force_active on
extern "C" {
extern char lbl_8045C720[];

void fn_800FD1F8(void *arg0) {
    unsigned int* p = (unsigned int*)arg0;
    p[4] = (unsigned int)lbl_8045C720;
    p[1] = 0;
    p[2] = 0;
    p[3] = -1;
    p[0] = 0;
}
}
