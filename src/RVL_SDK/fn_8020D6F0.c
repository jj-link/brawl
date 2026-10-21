#pragma force_active on
typedef struct SdHandle {
    int unk00;
    int unk04;
} SdHandle;

extern int lbl_805A0BA8;
extern int fn_8020D41C(int, int, SdHandle *, int, int);
extern int fn_8020CAEC(int);

int fn_8020D6F0(int a0, int a1, int value, SdHandle *handle)
{
    int result;

    if (lbl_805A0BA8 != 2)
        return -128;

    handle->unk04 = value;
    result = fn_8020D41C(a0, a1, handle, 1, 1);
    return fn_8020CAEC(result);
}
