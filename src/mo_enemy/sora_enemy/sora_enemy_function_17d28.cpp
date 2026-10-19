#pragma force_active on
extern float lbl_41_rodata_C3C;

extern "C" float fn_41_15FD4(int, int);
extern "C" float fn_41_1F194();

extern "C" float fn_41_17D28(void* self, int taskId) {
    if (taskId == -1) {
        return lbl_41_rodata_C3C;
    }
    fn_41_15FD4(reinterpret_cast<int>(self), taskId);
    return fn_41_1F194();
}
