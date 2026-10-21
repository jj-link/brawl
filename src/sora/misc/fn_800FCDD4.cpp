#pragma force_active on
extern "C" void fn_800DA59C(int, int, int);

extern "C" void fn_800FCDD4(int* arg0, int arg1) {
    int a, b;
    if (arg1 == 0) {
        a = 0;
        b = 3;
    } else {
        a = 1;
        b = 2;
    }
    fn_800DA59C(*(int*)((char*)arg0 + 0x40), a, b);
}
