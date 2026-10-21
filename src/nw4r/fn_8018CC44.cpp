#pragma force_active on
extern "C" void fn_8018CC44(unsigned char* p, unsigned int v) {
    p[0] = 0x61;
    p[1] = (unsigned char)(v >> 24);
    p[2] = (unsigned char)((v >> 16) & 0xFF);
    p[3] = (unsigned char)((v >> 8) & 0xFF);
    p[4] = (unsigned char)v;
}
