#pragma force_active on
extern "C" bool isExistTarget__16emAreaModuleImplFP16soModuleAccesserUl(void*, unsigned long);
extern "C" void fn_41_253E8(void*, int);
extern "C" void fn_41_25F80(void*, int);
extern "C" void fn_41_260C8(void*, int);
extern "C" void fn_41_26214(void*, int);

extern "C" void fn_41_26430(void* p1, int p2) {
    if (p2 == 8) {
        for (int i = 0; i < 8; i++) {
            if (isExistTarget__16emAreaModuleImplFP16soModuleAccesserUl(p1, i)) {
                fn_41_253E8(p1, p2);
                fn_41_25F80(p1, p2);
                fn_41_260C8(p1, p2);
                fn_41_26214(p1, p2);
            }
        }
    } else {
        fn_41_253E8(p1, p2);
        fn_41_25F80(p1, p2);
        fn_41_260C8(p1, p2);
        fn_41_26214(p1, p2);
    }
}
