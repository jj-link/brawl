#pragma force_active on
extern "C" {
extern char lbl_116_data_9794[];
extern char lbl_116_data_25F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
class Class_1E84 {
public:
    virtual void fn_116_7384();
    virtual void fn_116_19C8();
    virtual void fn_116_A6F8();
    virtual void fn_116_A6F0();
    virtual void fn_116_A6E8();
    virtual void fn_116_A6E0();
    virtual unsigned int fn_116_A6D8();
};
extern "C" int fn_116_193C8(void*, void*, void* self) {
    unsigned char buf[40];
    unsigned char* p = buf;
    Class_1E84* obj = reinterpret_cast<Class_1E84*>(self);
    switch (obj->fn_116_A6D8()) {
        case 0: p[32] = 0; p[33] = 0; __dynamic_cast(self, 0, lbl_116_data_9794, lbl_116_data_25F4, 1); return 1;
        case 1: p[30] = 0; p[31] = 0; return 1;
        case 2: p[28] = 0; p[29] = 0; return 1;
        case 3: p[26] = 0; p[27] = 0; return 1;
        case 4: p[24] = 0; p[25] = 0; return 1;
        case 5: p[22] = 0; p[23] = 0; return 1;
        case 6: p[20] = 0; p[21] = 0; return 1;
        case 7: p[18] = 0; p[19] = 0; return 1;
        case 8: p[16] = 0; p[17] = 0; return 1;
        case 9: p[14] = 0; p[15] = 0; return 1;
        case 10: p[12] = 0; p[13] = 0; return 1;
        case 11: p[10] = 0; p[11] = 0; return 1;
        case 12: p[8] = 0; p[9] = 0; return 1;
        case 13: p[6] = 0; p[7] = 0; return 1;
        case 14: p[4] = 0; p[5] = 0; return 1;
        case 15: p[2] = 0; p[3] = 0; return 1;
        case 16: p[0] = 0; p[1] = 0; return 1;
        default: return 0;
    }
}