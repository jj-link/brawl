#pragma force_active on
extern "C" {
void fn_27_196828(signed char* base, int idx, int val) {
    signed char* p = base + (idx << 1);
    if (p[0x64] == -1) {
        return;
    }
    if (val != p[0x65]) {
        return;
    }
    p[0x64] = -1;
}
}
