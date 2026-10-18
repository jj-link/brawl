#pragma force_active on
extern "C" void fn_105_8058(void*, int);
extern "C" unsigned char lbl_105_data_2D8C[];

struct IceClimberWork {
    void* vtPrimary;
    void* field04;
    void* vtSecondary;
    void* field0C;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void* field20;
};

extern "C" IceClimberWork* fn_105_9248(
    IceClimberWork* work,
    void* arg1,
    void* arg2,
    void* arg3,
    void* arg4,
    void* arg5,
    void* arg6
) {
    fn_105_8058(work, 0);
    work->vtSecondary = lbl_105_data_2D8C;
    work->vtPrimary = (char*)lbl_105_data_2D8C + 8;
    work->field0C = arg1;
    work->field10 = arg2;
    work->field14 = arg3;
    work->field18 = arg4;
    work->field1C = arg5;
    work->field20 = arg6;
    return work;
}
