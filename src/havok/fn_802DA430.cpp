#pragma force_active on
extern "C" void* fn_802DA104(int);
extern "C" void fn_802DA190(void*, void*);
extern "C" void fn_802DA2B4(void*);

struct S0 {
    unsigned char pad[4];
    unsigned short unk4;
    unsigned short unk6;
};

extern "C" void* fn_802DA430(void* arg0, int arg1) {
    S0* p = (S0*)arg0;
    void* var_r31;
    unsigned short temp_r3;

    var_r31 = arg0;
    temp_r3 = p->unk6;
    if ((int)((p->unk4 + arg1) * 2) <= (int)temp_r3) {
        var_r31 = fn_802DA104((temp_r3 >> 1) & 0x7FFF);
        fn_802DA190(var_r31, arg0);
        fn_802DA2B4(arg0);
    }
    return var_r31;
}
