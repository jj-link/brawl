#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void* self, float* pos);

extern "C" void fn_62_110D0(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(unsigned int*)(m + 0x11c) == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(s + 0xc4);
                *(unsigned char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(unsigned int**)(p + 4);
                *(short*)(m + 0x122) = (short)*q;
            }
            {
                float* dst = *(float**)(p + 4);
                ((float*)((unsigned char*)dst + 0x8))[0] = ((float*)(s + 0x164))[0];
                ((float*)((unsigned char*)dst + 0xc))[0] = ((float*)(s + 0x164))[1];
                ((float*)((unsigned char*)dst + 0x10))[0] = ((float*)(s + 0x164))[2];
                dst = *(float**)(p + 4);
                ((float*)((unsigned char*)dst + 0x14))[0] = ((float*)(s + 0x164))[3];
                ((float*)((unsigned char*)dst + 0x18))[0] = ((float*)(s + 0x164))[4];
                ((float*)((unsigned char*)dst + 0x1c))[0] = ((float*)(s + 0x164))[5];
            }
            setPos__14snd3DGeneratorFP5Vec3f(s + 0x194, (float*)(s + 0x164));
        }
    }
}
