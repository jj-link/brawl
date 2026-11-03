#pragma force_active on
extern "C" int fn_801C8EB4(void);
extern "C" int fn_801C6C04(int, int*);
extern "C" void fn_801CC9D8(unsigned int*, unsigned int, unsigned int, unsigned int);

extern "C" int fn_801C8B3C(void* arg0, int arg1, int a2, int a3, unsigned int arg4, unsigned int arg5) {
    int flag;
    unsigned int val;
    unsigned int val2;
    int pad[2];
    int sp[15];
    if (fn_801C8EB4() == 0) {
        return 0;
    }
    val = 0;
    if (fn_801C6C04(arg1, &sp[7]) != 0) {
        val = sp[11];
    }
    if (arg5 < val * 0xA000u) {
        flag = 0;
    } else {
        val2 = 0;
        if (fn_801C6C04(arg1, &sp[0]) != 0) {
            val2 = sp[4];
        }
        fn_801CC9D8((unsigned int*)((char*)arg0 + 0xBC), arg4, arg5, val2);
        flag = 1;
    }
    if (flag == 0) {
        return 0;
    }
    *(int*)((char*)arg0 + 0x1C) = (int)((char*)arg0 + 0xB0);
    return 1;
}