#pragma force_active on

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual void* fn_27_100CC();
    virtual void fn_27_10094();
    virtual void* fn_27_100C8();
    virtual void* fn_27_100C4();
};

extern "C" {
void* fn_27_2816D0();
Class_CF8* fn_27_2DF188(void*);
void fn_27_1DC5E8(void*, int, const void*, void*, void*, void*, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_2DF4A4(void*, const void*, int, void*, void*);
void fn_27_1DC870(void*, int);
void fn_27_1D8FC8(void*, int);
extern char lbl_27_data_7C588[];
extern char lbl_27_data_7C594[];
}

extern "C" void* fn_27_2DF024(void* arg0, int arg1, void* arg2, const unsigned int* arg3) {
    unsigned char buf[0x40];
    int zero = 0;
    int minus_one = -1;

    fn_27_1DC5E8(buf, 4, arg3,
                 fn_27_2DF188(arg2)->fn_27_100CC(),
                 fn_27_2DF188(arg2)->fn_27_100C8(),
                 fn_27_2DF188(arg2)->fn_27_100C4(),
                 (unsigned char)*arg3, minus_one,
                 fn_27_2816D0(), zero, zero, zero, zero, zero, zero, zero);

    fn_27_2DF4A4(arg0, lbl_27_data_7C588, arg1, arg2, buf);
    fn_27_1DC870(buf, -1);

    char* data = lbl_27_data_7C594;
    *(char**)((char*)arg0 + 0x3C) = data;
    *(char**)((char*)arg0 + 0x40) = data + 0x64;
    *(char**)((char*)arg0 + 0x48) = data + 0x70;
    *(char**)((char*)arg0 + 0x54) = data + 0x84;
    *(char**)((char*)arg0 + 0x64) = data + 0xDC;
    *(char**)((char*)arg0 + 0x70) = data + 0xEC;
    *(char**)((char*)arg0 + 0x7C) = data + 0x100;
    *(char**)((char*)arg0 + 0x88) = data + 0x118;
    *(char**)((char*)arg0 + 0x90) = data + 0x124;
    fn_27_1D8FC8(arg0, 0);
    return arg0;
}