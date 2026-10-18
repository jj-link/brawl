#pragma force_active on
extern "C" int fn_27_77A88(void*, int);
extern "C" int fn_113_23400(void*, unsigned char*);
extern "C" int fn_113_235BC(void*, unsigned char*);
extern "C" int fn_113_236C0(void*, unsigned char*);
extern "C" int fn_113_237E0(void*, unsigned char*);
extern "C" int fn_113_23900(void*, unsigned char*);

extern "C" int fn_113_23340(void* arg0, int arg1) {
    if (arg1 <= 0x270F) {
        return fn_27_77A88(arg0, arg1);
    }

    switch (arg1) {
    case 0x2710: {
        unsigned char value = 0;
        return fn_113_23400(arg0, &value);
    }
    case 0x2711: {
        unsigned char value = 0;
        return fn_113_235BC(arg0, &value);
    }
    case 0x2712: {
        unsigned char value = 0;
        return fn_113_236C0(arg0, &value);
    }
    case 0x2713: {
        unsigned char value = 0;
        return fn_113_237E0(arg0, &value);
    }
    case 0x2714: {
        unsigned char value = 0;
        return fn_113_23900(arg0, &value);
    }
    default:
        return 1;
    }
}
