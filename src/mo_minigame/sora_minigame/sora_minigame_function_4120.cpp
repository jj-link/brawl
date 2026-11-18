#pragma force_active on
#pragma fp_contract off

#include <types.h>
#include <gm/gm_lib.h>
#include <mt/mt_prng.h>

struct Object {
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
};

extern "C" {
extern void* lbl_20_bss_8;
extern float lbl_20_rodata_50[];
extern void* lbl_805A0EC8;

void* fn_8027EA20(void*, unsigned int, int);
void fn_8027EABC(void*, void*, unsigned int, int);
void fn_802E34D8(void*, float*);
u16 fn_80051700();
u16 fn_80051714(u16);
void* fn_801063BC();
void fn_801063CC(void*, void*, u32);
void fn_80106208(void*);
void fn_20_4120(void*);
}

struct Temp {
    void** items;
    int count;
    union {
        int capacity;
        u32 allocationSize;
    };

    Temp(void** p, int n, int initial) {
        items = p;
        count = n;
        capacity = initial;
    }
    u32 rawValue() const { return allocationSize; }
};

extern "C" void fn_20_4120(void* arg) {
    long length;
    int slot;
    void** entries;
    char* self = (char*)arg;
    char* state = (char*)lbl_20_bss_8;
    Temp temp(0, 0, 0x80000000);
    length = (int)(temp.capacity & 0x3fffffff);

    if (length < *(int*)(state + 0x4D4)) {
        if ((temp.capacity & 0x80000000) == 0)
            fn_8027EABC(lbl_805A0EC8, temp.items, temp.capacity * 4, 0x15);
        temp.items = (void**)fn_8027EA20(
            lbl_805A0EC8, *(int*)(state + 0x4D4) * 4, 0x15);
        temp.capacity = *(int*)(state + 0x4D4) |
                        (temp.capacity & 0x40000000);
    }

    temp.count = *(int*)(state + 0x4D4);
    void** dst;
    void** src = *(void***)(state + 0x4D0);
    dst = temp.items;
    for (int i = 0; i < temp.count; ++i)
        dst[i] = src[i];

    if (*(int*)(self + 0x68) != 0 && *(u8*)(state + 0x33C) == 0)
        fn_20_4120(temp.items[0]);

    float w, z, y, x;
    const int poolStart[1] = {-250};
    float zeroConstant = 0.0f;
    float one = 1.0f;
    x = 90.0f;
    float five = 5.0f;
    float negative170 = -170.0f;
    float scale = 1.3f;
    float angle = -89.67f;
    float fraction = 0.33f;
    float width = 300.0f;
    float margin = 10.0f;
    float height = 290.0f;
    y = -100.0f;
    z = 170.0f;
    float two = 2.0f;
    float negativeTwo = -2.0f;
    float smallestNormal = 1.1754943508222875e-38f;
    float six = 6.0f;
    float sixty = 60.0f;
    float eighthTurn = 0.39269909262657166f;
    double unsignedBias = 4503599627370496.0;
    *(float*)(self + 0x34) = x;
    w = 0.0f;
    *(float*)(self + 0x38) = y;
    *(float*)(self + 0x3C) = z;

    float vec[4] __attribute__((aligned(16)));
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    vec[3] = w;
    fn_802E34D8(*(void**)(self + 0x24), vec);

    if (*(u8*)(state + 0x35C) == 1) {
        void* saved;
        char* slotState;
        self[0x64] = 0;
        {
            u8 flags[20];
            u32 ids[20];
            int validCount = 0;

            for (int i = 0; i < 20; ++i) {
                u32 id = (u16)fn_80051700();
                int valid = !gmCheckExistFigure(id);
                if (valid) {
                    ids[19 - validCount] = id;
                    flags[19 - validCount] = valid;
                    ++validCount;
                } else {
                    ids[i - validCount] = id;
                    flags[i - validCount] = valid;
                }
            }

            float f = 100.0f * randf();
            int chosen;
            if (0.0f == *(float*)(state + 0x188)) {
                chosen = (int)((20.0f * f) / 100.0f);
            } else if (f < *(float*)(state + 0x188)) {
                if (validCount != 0) {
                    chosen = (int)(19.0f -
                        (float)validCount * f / *(float*)(state + 0x188));
                    if (chosen < 0 || chosen >= 20)
                        chosen = 0;
                } else {
                    chosen = randi(20);
                }
            } else {
                chosen = randi(20);
            }

            ((u32*)(state + 0x340))[*(int*)(self + 0x68)] = ids[chosen];
            self[0x64] = flags[chosen];
        }

        void* entry;
        fn_801063CC(&entry, fn_801063BC(),
            ((u32*)(state + 0x340))[*(int*)(self + 0x68)]);

        slotState = state + *(int*)(self + 0x68) * 4;
        saved = entry;
        entry = 0;
        if (*(void**)(slotState + 0x34C))
            fn_80106208(*(void**)(slotState + 0x34C));
        *(void**)(slotState + 0x34C) = saved;
        if (entry)
            fn_80106208(entry);
        entry = 0;
        *(u8*)(state + *(int*)(self + 0x68) + 0x358) = 0;

        u16 kind = fn_80051714(
            (u16)((u32*)(state + 0x340))[*(int*)(self + 0x68)]);
        if (kind == 0)
            *(int*)(self + 0x44) = *(int*)(state + 0xE8);
        else if (kind == 1)
            *(int*)(self + 0x44) = *(int*)(state + 0xE4);
        else if (kind == 2)
            *(int*)(self + 0x44) = *(int*)(state + 0xE0);
        else if (kind == 3)
            *(int*)(self + 0x44) = *(int*)(state + 0xDC);
        else if (kind == 4)
            *(int*)(self + 0x44) = *(int*)(state + 0xD8);
        else if (kind == 5)
            *(int*)(self + 0x44) = *(int*)(state + 0xD4);
        else
            *(int*)(self + 0x44) = 2;
    }

    if (randi(2) == 0) {
        if (randi(2) == 0)
            ++*(int*)(self + 0x44);
        else
            --*(int*)(self + 0x44);
    }

    if (*(int*)(self + 0x44) < 2)
        *(int*)(self + 0x44) = 2;
    else if (*(int*)(self + 0x44) > 4)
        *(int*)(self + 0x44) = 4;

    slot = *(int*)(self + 0x68);
    float zero = 0.0f;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x5C) = 2;
    *(float*)(self + 0x60) = zero;

    if (slot == 0) {
        *(int*)(self + 0x58) = randi(15);
        if (*(u8*)(state + 0x2D4) == 0)
            *(u8*)(state + 0x2D4) = 1;
        else
            (*(Object**)(state + 0x2D0))->method22();

        if (*(u8*)(state + 0x35C) == 1)
            *(int*)(self + 0x4C) = *(int*)(state + 0xBC) +
                randi(*(int*)(state + 0xC0) - *(int*)(state + 0xBC));
        else
            *(int*)(self + 0x4C) = 1;

        float range = *(float*)(state + 0xC4) - *(float*)(state + 0xC8);
        *(float*)(self + 0x50) = *(float*)(state + 0xC8) + range * randf();
        *(int*)(self + 0x54) = *(int*)(state + 0xCC) +
            randi(*(int*)(state + 0xD0) - *(int*)(state + 0xCC));
    } else {
        entries = temp.items;
        *(int*)(self + 0x58) = *(int*)((char*)entries[0] + 0x58);
        int value = *(int*)((char*)entries[0] + 0x54);
        *(int*)(self + 0x54) = value;
        slot = value * slot;
        *(int*)(self + 0x4C) = slot + *(int*)((char*)entries[0] + 0x4C);
        *(float*)(self + 0x50) = *(float*)((char*)entries[0] + 0x50);
    }

    *(u8*)(state + *(int*)(self + 0x68) + 0x33C) = 1;
    if ((temp.capacity & 0x80000000) == 0)
        fn_8027EABC(lbl_805A0EC8, temp.items, temp.rawValue() << 2, 0x15);
}
