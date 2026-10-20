#pragma force_active on
struct fn_27_35C04_Flags {
    unsigned char pad[0x38];
    unsigned char a : 1;
    unsigned char bit : 1;
};

extern "C" void fn_27_35C04(fn_27_35C04_Flags* p, unsigned int flag) {
    p->bit = flag;
}
