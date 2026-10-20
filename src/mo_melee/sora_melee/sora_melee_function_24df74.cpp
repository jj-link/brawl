#pragma force_active on
extern "C" int fn_27_24DF74(unsigned char* p, unsigned int a, unsigned short b) {
    if (a != 1 && a != 2)
        return 0;

    p[5] = static_cast<unsigned char>(a);
    p[4] = 1;
    *reinterpret_cast<unsigned short*>(p + 6) = b;
    return 1;
}
