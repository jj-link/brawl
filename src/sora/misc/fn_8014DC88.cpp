#pragma force_active on
struct Callback {
    virtual int func(int, int, int);
};

struct Holder {
    char padding[0x8];
    Callback* callback;
};

extern "C" int fn_8014DD34(void*, int);
extern "C" int fn_8014E0DC(void*, int);
extern "C" int fn_8014E230(int, int);
extern "C" int srGetAppInitialCode__Fv();

extern "C" int fn_8014DC88(Holder* arg0) {
    if (fn_8014DD34(arg0, 1) == 0) {
        return 0;
    }
    int result = fn_8014E230(srGetAppInitialCode__Fv(), 1);
    if (result != 0) {
        if (fn_8014E0DC(arg0, result) != 0) {
            Callback* cb = arg0->callback;
            if (cb != 0) {
                cb->func(3, result, 0x1ADAF);
            }
        }
        return 0;
    }
    return 1;
}
