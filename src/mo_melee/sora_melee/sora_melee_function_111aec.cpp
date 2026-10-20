#pragma force_active on
extern "C" {

struct fn_27_111AEC_obj {
    unsigned char unk[0x58];
    unsigned short value;
};

unsigned short fn_27_111AEC(fn_27_111AEC_obj **arg) {
    return (*arg)->value;
}

}
