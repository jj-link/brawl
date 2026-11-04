#pragma force_active on

typedef float f32;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern const f32 lbl_27_rodata_3000[];
extern void* g_aiMgr;
void* fn_27_1EE084(void* mgr, void* arg, void* p);
void* fn_27_1F1F58(void* fighterId);
f32 randf__Fv();
}

extern "C" void fn_27_210AE4(void* arg0, f32* arg1, f32* arg2) {
    const f32* R = lbl_27_rodata_3000;
    char* self = (char*)arg0;
    char* p;
    char* r7;
    char* r29;
    char* r31;
    f32 f31;
    f32 f2;
    f32 f3;

    p = *(char**)(self + 0x74);
    if (*(u8*)(p + 0xC0) == 1) {
        r7 = *(char**)(p + 0xBC);
        if (*(u32*)(r7 + 0x40) & 0x10000) {
            if (*(f32*)(p + 0x80) > R[0]) {
                *arg1 = R[22] + *(f32*)(r7 + 0x20);
                *arg2 = R[37] + *(f32*)(*(char**)(*(char**)(self + 0x74) + 0xBC) + 0x24);
                return;
            }
            *arg1 = *(f32*)(r7 + 0x18) - R[22];
            *arg2 = R[37] + *(f32*)(*(char**)(*(char**)(self + 0x74) + 0xBC) + 0x1C);
            return;
        }
    }

    r29 = (char*)fn_27_1EE084(g_aiMgr, *(void**)(self + 0x70), p);
    r31 = (char*)fn_27_1F1F58((char*)*(char**)(self + 0x70) + 0x110);
    f31 = R[6] + R[45] * randf__Fv();
    if (r29 == 0) {
        r29 = *(char**)(*(char**)(self + 0x74) + 0xBC);
    }
    f3 = R[3] * (*(f32*)(r29 + 0x18) + *(f32*)(r29 + 0x20));
    f2 = *(f32*)(r31 + 0x5C) + R[37] * *(f32*)(r31 + 0x80);
    if (f2 > R[22] + f3) {
        *arg1 = R[1];
    } else if (f2 < f3 - R[22]) {
        *arg1 = R[2];
    } else {
        *arg1 = randf__Fv() - R[3];
    }
    if (*arg1 < R[0]) {
        *arg1 = *(f32*)(r29 + 0x20) - *(f32*)(r29 + 0x18);
        *arg2 = *(f32*)(r29 + 0x24) - *(f32*)(r29 + 0x1C);
        *arg1 *= f31;
        *arg2 *= f31;
        *arg1 += *(f32*)(r29 + 0x18);
        *arg2 += *(f32*)(r29 + 0x1C);
    } else {
        *arg1 = *(f32*)(r29 + 0x18) - *(f32*)(r29 + 0x20);
        *arg2 = *(f32*)(r29 + 0x1C) - *(f32*)(r29 + 0x24);
        *arg1 *= f31;
        *arg2 *= f31;
        *arg1 += *(f32*)(r29 + 0x20);
        *arg2 += *(f32*)(r29 + 0x24);
    }
}
