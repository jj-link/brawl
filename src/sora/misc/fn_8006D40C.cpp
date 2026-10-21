#pragma force_active on
extern "C" void fn_8006D40C(unsigned char* arg0, float farg0) {
    short v = (short)farg0;
    unsigned char* p = (unsigned char*)&v;
    arg0[0] = p[0];
    arg0[1] = p[1];
}
