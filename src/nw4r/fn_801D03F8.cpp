#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_801BB188();
extern "C" void fn_801BB8E0(void*, void*);
extern "C" char lbl_80466D3C[];

extern "C" void* fn_801D03F8(void* arg0, int arg1) {
    void** var_r31;
    void** var_r30;
    int var_r29;
    int var_r28;

    if (arg0 != 0) {
        var_r31 = (void**)arg0;
        ((void**)arg0)[2] = lbl_80466D3C;
        var_r29 = 0;
        do {
            var_r30 = var_r31;
            var_r28 = 0;
            do {
                void* temp_r27 = var_r30[3];
                if (temp_r27 != 0) {
                    fn_801BB8E0(fn_801BB188(), temp_r27);
                }
                var_r28++;
                var_r30++;
            } while (var_r28 < 4);
            var_r29++;
            var_r31 += 4;
        } while (var_r29 < 2);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
