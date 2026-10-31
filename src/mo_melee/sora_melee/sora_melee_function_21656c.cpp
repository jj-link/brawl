#pragma force_active on
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern "C" void fn_27_1FAC54(void* p, s32 arg);
extern "C" s32 fn_27_20B694(void* p, s32 flags);
extern "C" void fn_27_210AE4(void* a, void* b, void* c);
extern const float lbl_27_rodata_3000[];

extern "C" void fn_27_21656C(void* self, float* out) {
    const float* rodata = lbl_27_rodata_3000;
    char* p = (char*)self;

    if (!(*(s32*)((char*)*(void**)(p + 0x74) + 0x50) & 1)) {
        u16 val = *(u16*)(p + 0x78);
        if (val != 0)
            *(u16*)(p + 0x7C) = val;
        *(u16*)(p + 0x78) = 0;
        fn_27_1FAC54(*(void**)(p + 0x70), 0);
        return;
    }

    if (*(s32*)(p + 0xA8) == 0) {
        if (*(s16*)((char*)*(void**)(p + 0x74) + 0xA8) == 0) {
            u16 val = *(u16*)(p + 0x78);
            *(u16*)(p + 0x7E) = 0x2050;
            if (val != 0)
                *(u16*)(p + 0x7C) = val;
            *(u16*)(p + 0x78) = 0;
            fn_27_1FAC54(*(void**)(p + 0x70), 0);
            return;
        }
        *(s32*)((char*)*(void**)(p + 0x70) + 0x6C) = 2;
        *(s32*)(p + 0x94) = 0x28;
        *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
    }

    s32 state = *(s32*)(p + 0xA8);
    switch (state) {
    case 1:
        fn_27_210AE4(self, p + 0xE0, p + 0xE4);
        *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
        break;
    default:
        break;
    }

    float f_val = *(float*)(p + 0xE0) - *(float*)((char*)*(void**)(p + 0x74) + 0x5C);
    out[0] = rodata[0x35] * f_val;

    switch (*(s32*)(p + 0xA8)) {
    case 2:
        if (fn_27_20B694(*(void**)(p + 0x74), 0x20000) != 0) {
            out[1] = rodata[2];
            *(s32*)(p + 0xAC) = 0;
            *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
        }
        break;
    case 3:
        out[1] = rodata[2];
        if (*(s32*)(p + 0xAC) > 4) {
            *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
        }
        break;
    default:
        if (*(float*)((char*)*(void**)(p + 0x74) + 0x84) < rodata[0]) {
            u16 val = *(u16*)(p + 0x78);
            *(u16*)(p + 0x7E) = 0x2050;
            if (val != 0)
                *(u16*)(p + 0x7C) = val;
            *(u16*)(p + 0x78) = 0;
            fn_27_1FAC54(*(void**)(p + 0x70), 0);
        }
        break;
    }
}
