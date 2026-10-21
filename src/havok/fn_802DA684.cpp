#pragma force_active on

struct Obj {
    unsigned char padding[0x1C];
    int value;
};

struct Out {
    int a;
    int b;
};

extern "C" void fn_802DA684(Obj* obj, signed char* flag, Out* out) {
    if (*flag != 0) {
        int t = obj->value;
        int m = (t * 4) - t;
        out->b = m;
        out->a = m * 8;
        return;
    }
    out->b = 0;
    out->a = 0;
}
