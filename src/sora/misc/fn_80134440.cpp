#pragma force_active on
extern "C" void fn_80134440(void* arg0, int arg1) {
    unsigned short* p = (unsigned short*)((unsigned char*)arg0 + 0xE);
    if (arg1) {
        int v = (*p) & 0xFFFFFEFF;
        *p = (unsigned short)v;
        return;
    }
    *p |= 0x100;
}
