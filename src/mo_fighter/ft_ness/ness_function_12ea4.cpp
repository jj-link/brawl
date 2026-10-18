#pragma force_active on
struct NessProcess { void* vtable; };

extern "C" unsigned char lbl_101_data_8CF0[];

extern "C" NessProcess* fn_101_12EA4(NessProcess* process) {
    process->vtable = lbl_101_data_8CF0;
    return process;
}
