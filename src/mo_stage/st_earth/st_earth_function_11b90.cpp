#pragma force_active on
extern "C" void fn_66_11B90(unsigned char* self) {
    int state = self[0x158];
    if (state < 6) {
        if (state != 1) {
            return;
        }
    } else {
        if (state >= 8) {
            return;
        }
    }
    self[0x158] = 2;
}
