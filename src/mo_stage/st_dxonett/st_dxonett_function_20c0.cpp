#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
void* getManager__15gfCameraManagerFv(void);
void fn_80019E88(void* self, float* out, float a, float b);
void fn_8003DEE0(float* out, float* in, float a, float b);
int fn_80043898(float* a, float* b);
extern const float lbl_78_rodata_58[7];
}

extern "C" void fn_78_20C0(u8* self) {
    const float* k = lbl_78_rodata_58;
    u8* m;
    u8* p = self + 0xD0;
    if (p != 0) {
        u8** a = *(u8***)(self + 0x44);
        m = a[*(u32*)(self + 0xC0)];
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32* q = *(u32**)(p + 4);
                *q = *(u32*)(self + 0xc4);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            float sp2c[3];
            float sp20[3];
            float sp14[3];
            float sp8[3];
            sp14[0] = k[0];
            sp14[1] = k[0];
            sp14[2] = k[0];
            sp8[0] = k[0];
            sp8[1] = k[0];
            sp8[2] = k[0];
            u8* g = (u8*)getManager__15gfCameraManagerFv();
            if (g != 0) {
                float* s = (float*)(g + 0x114);
                if (s != 0) {
                    fn_80019E88(g, sp8, k[6] * s[2], k[5] * s[3]);
                    float fx = *(float*)(g + 0x6c);
                    sp14[0] = fx;
                    float fy = *(float*)(g + 0x70);
                    sp14[1] = fy;
                    float fz = *(float*)(g + 0x74);
                    sp14[2] = fz;
                    sp20[0] = fx;
                    sp20[1] = fy;
                    sp20[2] = fz;
                    fn_8003DEE0(sp2c, sp8, fy, fx);
                    if (fn_80043898(sp20, sp14) != 0) {
                        u8* d = *(u8**)(p + 4);
                        *(float*)(d + 0x8) = sp14[0];
                        *(float*)(d + 0xc) = sp14[1];
                        *(float*)(d + 0x10) = sp14[2];
                    }
                }
            }
        }
    }
}
