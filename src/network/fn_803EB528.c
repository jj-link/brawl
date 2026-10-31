#pragma force_active on

extern int PFAPI_convertReturnValue(int);
extern int fn_803EA488(int, void*, int);
extern char lbl_805644C0[];

int fn_803EB528(int* arg0, void* arg1) {
    int result;

    if (arg0 == 0 || *arg0 == 0) {
        result = 10;
        *(int*)(lbl_805644C0 + 0x40) = result;
        goto done;
    }

    while (*arg0 != 0) {
        if (arg1 != 0) {
            result = fn_803EA488(*arg0, arg1, *(int*)((char*)arg1 + 0x50));
        } else {
            result = fn_803EA488(*arg0, 0, 0);
        }
        if (result != 0) {
            return PFAPI_convertReturnValue(result);
        }
        arg0++;
    }

done:
    return PFAPI_convertReturnValue(result);
}
