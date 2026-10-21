#pragma force_active on
extern "C" {
void fn_801AB014(void* self, int val) {
    if (val < 0) {
        val = 0;
    } else if (val > 0xFF) {
        val = 0xFF;
    }
    *(unsigned char*)((char*)self + 0xD1) = val;
}
}
