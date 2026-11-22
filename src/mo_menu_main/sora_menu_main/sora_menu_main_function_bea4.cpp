#include <mt/mt_matrix.h>

#pragma force_active on

extern "C" {
int isReady__14gfFileIOHandleCFv(const void* self);
void release__14gfFileIOHandleFv(void* self);
void readRequest__14gfFileIOHandleFPCcPvii(void* self, const char* name, void* buf, int length, int offset);
void Init__Q34nw4r3g3d7ResFileFPv(void* arg);
void endKeepScreen__17gfKeepFrameBufferFv(void* self);
void fn_1_6DA0(int a, int b);
void fn_2_9460(void* self, int a, void* b);
void fn_2_9F3C(void* self, int index, int sel, void* p);
float fn_2_B184(void* self, int index, float a, float b);
Matrix fn_2_A618(void* self, int index);
void fn_800B330C(void* obj, const void* str, int flag);
void fn_800B6838(void* model, const Vec3f* pos);
void fn_800B6F6C(void* model, const Vec3f* rot);
int sprintf(char* buf, const char* fmt, ...);
extern char* g_gfApplication;
extern char lbl_2_data_1238[];
extern char lbl_2_data_127C[];
extern const float lbl_2_rodata_2A0;
extern const float lbl_2_rodata_370;
}

extern "C" int fn_2_BEA4(char* self) {
    char buf[0x3c];
    int idx;

    if (isReady__14gfFileIOHandleCFv(self + 0x290) == 0) {
        return 1;
    }

    {
        char* slot = self + *(int*)(self + 0x294) * 4;
        void** res = (void**)(slot + 0xc4);
        *res = *(void**)(slot + 0x2a0);
        Init__Q34nw4r3g3d7ResFileFPv(res);
        release__14gfFileIOHandleFv(self + 0x290);
        *(int*)(self + 0x294) = *(int*)(self + 0x294) + 1;
    }

    while (*(int*)(self + 0x294) < 4) {
        idx = *(int*)(self + 0x294);
        char* entry = self + idx * 0x14;
        if ((((unsigned char)entry[0x4c]) >> 7) & 1) {
            char* base = *(char**)(*(char**)(self + 0xd8));
            int sel = ((((unsigned char)entry[0x4c]) >> 7) & 1) ? *(int*)(entry + 0x50) : -1;
            sprintf(buf, lbl_2_data_1238, *(char**)(base + sel * 0x60 + 8));
            readRequest__14gfFileIOHandleFPCcPvii(self + 0x290, buf, *(void**)(self + idx * 4 + 0x2a0), 0, 0);
            return 1;
        }
        *(int*)(self + 0x294) = *(int*)(self + 0x294) + 1;
    }

    endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xd0);
    fn_1_6DA0(*(int*)(self + 0x40), *(int*)(self + 0x178));
    fn_2_9460(self, *(int*)(self + 0x254), self + 0xa0);
    fn_1_6DA0(*(int*)(self + 0x40), *(int*)(self + 0x29c));

    int i;
    char* p23 = self;
    for (i = 0; i < 4; i++) {
        fn_800B330C(*(void**)(p23 + 0x108), lbl_2_data_127C, 0);
        p23 += 4;
    }

    void* model;
    char* p30;
    char* p29;
    char* p28;
    char* p27;
    p29 = self;
    p27 = self;
    p30 = self + 0x4c;
    p28 = self + 0xc4;
    for (int k = 0; k < 4; k++) {
        if ((((unsigned char)p30[0]) >> 7) & 1) {
            int sel = ((((unsigned char)p30[0]) >> 7) & 1) ? *(int*)(p29 + 0x50) : -1;
            fn_2_9F3C(self, k, sel, p28);
            float f28 = *(float*)(p29 + 0x54);
            float f27 = *(float*)(p29 + 0x58);
            float f29 = fn_2_B184(self, k, f28, f27);
            model = *(void**)(p27 + 0xf8);
            Matrix tmp = fn_2_A618(self, k);
            Matrix mtx(true);
            mtx = tmp;
            Vec3f src(lbl_2_rodata_2A0, lbl_2_rodata_2A0, lbl_2_rodata_2A0);
            Vec3f pos;
            Vec3f res;
            mtx.mulPos(&src, &res);
            float t2 = f27 + res.m_z;
            float t1 = lbl_2_rodata_370 + (f29 + res.m_y);
            float t3 = f28 + res.m_x;
            pos.m_x = t3;
            pos.m_y = t1;
            pos.m_z = t2;
            fn_800B6838(model, &pos);
            *(float*)(p30 + 0x8) = f28;
            *(float*)(p30 + 0xc) = f27;
            f29 = *(float*)(p29 + 0x5c);
            Vec3f v2(lbl_2_rodata_2A0, f29, lbl_2_rodata_2A0);
            fn_800B6F6C(*(void**)(self + (k + 4) * 4 + 0xe8), &v2);
            *(float*)(p29 + 0x5c) = f29;
        }
        p30 += 0x14;
        p29 += 0x14;
        p28 += 4;
        p27 += 4;
    }
    return 3;
}
