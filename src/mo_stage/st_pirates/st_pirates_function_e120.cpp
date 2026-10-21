#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, void*);

extern "C" void fn_52_E120(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* m = *(u8**)(*(u8**)(self + 0x44));
        if (m != 0) {
            if (*(u32*)(m + 0x11C) == 0) {
                *(u32*)(p + 0xC) = 0;
                *(u8**)(m + 0x11C) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(u16*)(m + 0x122) = (u16)**(u32**)(p + 4);
            }
            u8* q = *(u8**)(p + 4);
            *(float*)(q + 8) = *(float*)(self + 0x17C);
            *(float*)(q + 12) = *(float*)(self + 0x180);
            *(float*)(q + 16) = *(float*)(self + 0x184);
            setPos__14snd3DGeneratorFP5Vec3f(self + 0x1AC, self + 0x17C);
        }
    }
}
