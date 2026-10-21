#pragma force_active on
extern "C" void fn_27_2B6CA0(void* self, int arg);
extern "C" void fn_27_2B8688(void* self, int arg);
extern "C" void fn_27_2B87B8(void* self, int arg);

struct Bit7 {
    unsigned char b7 : 1;
    unsigned char rest : 7;
};

extern "C" void fn_27_2B48E8(void* self, int state, int arg)
{
    unsigned char* p = (unsigned char*)self;
    int old = *(int*)(p + 0x38);
    *(int*)(p + 0x38) = state;
    if (state != old) {
        switch (state) {
        case 0:
            fn_27_2B6CA0(self, arg);
            break;
        case 1:
            fn_27_2B8688(self, arg);
            break;
        case 2:
            fn_27_2B87B8(self, arg);
            break;
        case 3:
            fn_27_2B6CA0(self, arg);
            ((Bit7*)(p + 0xFD))->b7 = 0;
            ((Bit7*)(p + 0x205))->b7 = 0;
            ((Bit7*)(p + 0x1B9))->b7 = 0;
            break;
        case -1:
            ((Bit7*)(p + 0x241))->b7 = 0;
            break;
        }
    }
}
