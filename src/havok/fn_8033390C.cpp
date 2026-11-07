#pragma force_active on
extern "C" int fn_803338E4(int arg0);

extern "C" int fn_8033390C(void* arg0) {
    unsigned char* p = (unsigned char*)arg0;
    int result = 0;
    if (fn_803338E4(p[0xc]) != 0 || ((int)p[0xc] == 0x13 && fn_803338E4(p[0xd]) != 0)) {
        result = 1;
    }
    return result;
}