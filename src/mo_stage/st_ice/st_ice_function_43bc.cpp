#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Vec3f {
    float x, y, z;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void* generator, Vec3f* pos);
extern "C" const float lbl_62_rodata_80;

extern "C" void fn_62_43BC(unsigned char* s) {
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32* q = *(u32**)(p + 4);
                *q = *(u32*)(s + 0xc4);
                *(unsigned char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            {
                unsigned char* dst = *(unsigned char**)(p + 4);
                *(float*)(dst + 0x2c) = *(float*)(s + 0x178);
                *(float*)(dst + 0x30) = *(float*)(s + 0x17c);
                *(float*)(dst + 0x34) = *(float*)(s + 0x180);
            }
            {
                Vec3f zero;
                zero.x = lbl_62_rodata_80;
                zero.y = lbl_62_rodata_80;
                zero.z = lbl_62_rodata_80;
                setPos__14snd3DGeneratorFP5Vec3f(s + 0x1bc, &zero);
            }
        }
    }
}
