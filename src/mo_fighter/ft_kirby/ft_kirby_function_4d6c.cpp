#pragma force_active on
extern "C" void fn_96_1FD0(void*, int);
extern "C" unsigned char lbl_96_data_5E3C[];

extern "C" void* fn_96_4D6C(void* object, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6) {
    fn_96_1FD0(object, 0);
    object = object;
    *(void**)((char*)object + 8) = lbl_96_data_5E3C;
    *(void**)((char*)object + 0) = lbl_96_data_5E3C + 8;
    *(void**)((char*)object + 12) = arg1;
    *(void**)((char*)object + 16) = arg2;
    *(void**)((char*)object + 20) = arg3;
    *(void**)((char*)object + 24) = arg4;
    *(void**)((char*)object + 28) = arg5;
    *(void**)((char*)object + 32) = arg6;
    return object;
}
