#pragma force_active on
struct KoopaWork {
    void* vtSecondary;
    unsigned int isNull;
    void* vtPrimary;
    unsigned int arg0;
    unsigned int arg1;
    unsigned int arg2;
    unsigned int arg3;
    unsigned int arg4;
    unsigned int arg5;
};

extern "C" void fn_102_60D0(void*, int);
extern "C" unsigned char lbl_102_data_1530[];

extern "C" KoopaWork* fn_102_72B8(KoopaWork* work,
                                   unsigned int arg0,
                                   unsigned int arg1,
                                   unsigned int arg2,
                                   unsigned int arg3,
                                   unsigned int arg4,
                                   unsigned int arg5) {
    fn_102_60D0(work, 0);
    work->vtPrimary = lbl_102_data_1530;
    work->vtSecondary = lbl_102_data_1530 + 8;
    work->arg0 = arg0;
    work->arg1 = arg1;
    work->arg2 = arg2;
    work->arg3 = arg3;
    work->arg4 = arg4;
    work->arg5 = arg5;
    return work;
}
