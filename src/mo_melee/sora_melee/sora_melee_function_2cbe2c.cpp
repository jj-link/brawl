#pragma force_active on
extern "C" void fn_27_2CBEF0(void* self, int a, int b);

extern "C" void fn_27_2CBE2C(void* arg0, int arg1, int arg2) {
    int* self = (int*)arg0;
    switch (arg1) {
    case 0:
        self[0xF2C] = 6;
        break;
    case 1:
        self[0xF2C] = 1;
        break;
    case 2:
        self[0xF2C] = 0;
        break;
    case 3:
        self[0xF2C] = 5;
        break;
    }
    switch (arg2) {
    case 0:
        self[0xF2D] = 4;
        break;
    case 1:
        self[0xF2D] = 0;
        break;
    case 2:
        self[0xF2D] = 1;
        break;
    case 3:
        self[0xF2D] = 2;
        break;
    case 4:
        self[0xF2D] = 3;
        break;
    }
    fn_27_2CBEF0(arg0, self[0xF2C], self[0xF2D]);
}
