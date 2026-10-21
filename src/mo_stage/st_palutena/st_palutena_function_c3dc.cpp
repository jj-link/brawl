#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_67_C3DC(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* x = s + 0xd0;
    if (x != 0) {
        unsigned char* holder = *(unsigned char**)(s + 0x44);
        unsigned char* model = *(unsigned char**)holder;
        if (model != 0) {
            if (*(unsigned int*)(model + 0x11c) == 0) {
                *(unsigned int*)(x + 0xc) = 0;
                *(unsigned char**)(model + 0x11c) = x;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(short*)(model + 0x122) = (short)*(unsigned int*)(s + 0xc4);
            }
            unsigned char* p = *(unsigned char**)(x + 4);
            *(float*)(p + 0x2c) = *(float*)(s + 0x158);
            *(float*)(p + 0x30) = *(float*)(s + 0x15c);
            *(float*)(p + 0x34) = *(float*)(s + 0x160);
        }
    }
}
