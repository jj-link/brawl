#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

struct CallbackOwner {
    unsigned char pad[4];
    void* p;
    unsigned int f2;
    unsigned int f;
};

extern "C" void fn_51_15C10(void* self) {
    unsigned char* s = (unsigned char*)self;
    CallbackOwner* st = (CallbackOwner*)(s + 0xd0);
    if ((unsigned int)st == 0)
        return;
    void* model = (*(void***) (s + 0x44))[0];
    if (model == 0)
        return;
    if (*(unsigned int*)((unsigned char*)model + 0x11c) == 0) {
        st->f = 0;
        *(unsigned int*)st->p = *(unsigned int*)(s + 0xc4);
        *(void**)((unsigned char*)model + 0x11c) = st;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        *(unsigned short*)((unsigned char*)model + 0x122) = (unsigned short)*(unsigned int*)st->p;
    }
    float* dst = (float*)st->p;
    float* src = *(float**)(s + 0x158);
    ((float*)((unsigned char*)dst + 0x8))[0] = src[0];
    ((float*)((unsigned char*)dst + 0xc))[0] = src[1];
    ((float*)((unsigned char*)dst + 0x10))[0] = src[2];
    float* dst2 = (float*)((unsigned char*)st->p + 0x2c);
    dst2[0] = *(float*)(s + 0x164);
    dst2[1] = *(float*)(s + 0x168);
    dst2[2] = *(float*)(s + 0x16c);
}
