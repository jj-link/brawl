#include <types.h>

#pragma force_active on

extern "C" {
void fn_10_1ABF4();
void fn_10_1B52C();
void fn_10_1B794(void*);
extern const float lbl_10_rodata_7D0;
extern const double lbl_10_rodata_7F8;
}

struct ModeObject {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual float f20(void*);
};

struct MenuObject {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void f34(void*, void*);
    virtual void v12();
    virtual void f3c(void*);
};

extern "C" void fn_10_1AA34(void* self) {
    u8* p = (u8*)self;

    if (*(int*)(*(u8**)(p + 0x9C)) != 1) {
        switch (*(int*)(p + 0xA4)) {
        case 0:
            fn_10_1ABF4();
            break;

        case 1:
            if (*(int*)(*(u8**)(p + 0xA0) + 0x18) != 1) {
                MenuObject* object = *(MenuObject**)(p + 0x40);
                int enabled =
                    (*(u32*)(*(u8**)(p + 0x9C) + 0x1DC) >> 31) ^ 1;

                object->f3c(*(void**)(p + 0x44));

                if (enabled && !p[0xDC]) {
                    object = *(MenuObject**)(p + 0x40);
                    object->f34(*(void**)((u8*)object + 0xE4),
                                *(void**)(p + 0x44));
                }

                p[0xD0] = (u8)enabled;
                *(int*)(p + 0xA4) = 0;
                *(int*)(p + 0xA8) = 0;
            }
            break;

        case 2:
            fn_10_1B52C();
            break;

        case 3: {
            ModeObject* mode = *(ModeObject**)(p + 0x70);
            void* arg = *(void**)((u8*)mode + 0x2C);
            s32 frame = *(u16*)((u8*)arg + 0x1C);

            if (mode->f20(arg) >= (float)frame - lbl_10_rodata_7D0) {
                MenuObject* object = *(MenuObject**)(p + 0x40);
                int enabled =
                    (*(u32*)(*(u8**)(p + 0x9C) + 0x1DC) >> 31) ^ 1;

                object->f3c(*(void**)(p + 0x44));

                if (enabled && !p[0xDC]) {
                    object = *(MenuObject**)(p + 0x40);
                    object->f34(*(void**)((u8*)object + 0xE4),
                                *(void**)(p + 0x44));
                }

                p[0xD0] = (u8)enabled;
                *(int*)(p + 0xA4) = 0;
                *(int*)(p + 0xA8) = 0;
            }
            break;
        }

        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        }

        fn_10_1B794(self);
    }
}
