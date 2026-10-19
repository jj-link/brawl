#pragma force_active on
extern "C" {
void fn_40_44100(int*);
void fn_40_437DC(int*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_40_4384C(void* self) {
    int* p = (int*)self;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    __construct_array((char*)self + 0x10, (void (*)(void*))fn_40_44100,
                      (void (*)(void*))fn_40_437DC, 4, 0x2a);
    p[46] = 0;
    p[47] = 0;
    return self;
}
