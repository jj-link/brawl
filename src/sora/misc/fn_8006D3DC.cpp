#pragma force_active on

extern "C" void fn_8006D3DC(unsigned char* p, float f) {
    union {
        float f;
        unsigned char b[4];
    } u;
    u.f = f;
    p[0] = u.b[0];
    p[1] = u.b[1];
    p[2] = u.b[2];
    p[3] = u.b[3];
}
