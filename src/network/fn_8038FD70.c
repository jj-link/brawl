#pragma force_active on
extern void OSReport(const char* fmt, ...);
extern char lbl_804914A8[];
extern char lbl_804914D0[];

typedef void (*FuncType)(void*, void*, void*);

int fn_8038FD70(void* arg0, void* arg1, void* arg2, int arg3) {
    int result;
    FuncType func;
    FuncType* func_ptr;

    result = 0;
    func_ptr = *(FuncType**)((char*)arg0 + 0x104);
    func = *func_ptr;

    if (func == 0) {
        OSReport(lbl_804914A8);
    } else if (arg3 & 0xF) {
        OSReport(lbl_804914D0);
    } else {
        while (arg3 != 0) {
            func(arg0, arg1, arg2);
            arg2 = (void*)((char*)arg2 + 0x10);
            arg1 = (void*)((char*)arg1 + 0x10);
            arg3 -= 0x10;
        }
        result = 1;
    }
    return result;
}
