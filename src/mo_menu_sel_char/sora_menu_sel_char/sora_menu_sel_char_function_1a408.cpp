#include <types.h>
#include <mt/mt_matrix.h>

#pragma force_active on

struct RO {
    float one;
    float zero;
    float small;
};

extern "C" {
extern const RO lbl_10_rodata_7D0;

void fn_10_1C3E8(void*, int);
void fn_10_1860C(void*);
void fn_10_187C0(void*);
void fn_10_18DCC(void*);
void fn_10_19154(void*);
void fn_10_EE78(void*, int);
void fn_801AAF04(void*, int, Matrix*);
}

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
    virtual void v14();
    virtual void f3c(void*);
};

extern "C" void fn_10_1A408(void* self) {
    u8* p = reinterpret_cast<u8*>(self);
    const float* values = &lbl_10_rodata_7D0.one;
    u32 item;
    if (&item != 0)
        item = *reinterpret_cast<u32*>(p + 0xA8);
    u32 action = *reinterpret_cast<u32*>(p + 0xA4);

    switch (action) {
    case 0:
        break;
    case 1:
    case 2: {
        fn_10_1C3E8(*reinterpret_cast<void**>(p + 0xA0), 0);
        *reinterpret_cast<void**>(p + 0xA0) = 0;

        *reinterpret_cast<float*>(p + 0xCC) = values[2];

        Vec3f rotation;
        Vec3f scale;
        scale.m_x = values[2];
        scale.m_y = values[2];
        scale.m_z = values[0];
        rotation.m_x = values[1];
        rotation.m_y = values[1];
        rotation.m_z = values[1];

        Matrix matrix(true);
        matrix.setIdentity();
        matrix.setSRT(scale, rotation, *reinterpret_cast<Vec3f*>(p + 0x90));
        fn_801AAF04(*reinterpret_cast<void**>(p + 0x44), 0, &matrix);
        break;
    }
    case 3:
        break;
    case 5:
        fn_10_1860C(*reinterpret_cast<void**>(
            *reinterpret_cast<u8**>(*reinterpret_cast<u8**>(p + 0x9C) + 0x1F4)
            + item * 4 + 0x44));
        break;
    case 6:
        fn_10_187C0(*reinterpret_cast<void**>(
            *reinterpret_cast<u8**>(*reinterpret_cast<u8**>(p + 0x9C) + 0x1F4)
            + item * 4 + 0x44));
        break;
    case 7:
        fn_10_18DCC(*reinterpret_cast<void**>(
            *reinterpret_cast<u8**>(*reinterpret_cast<u8**>(p + 0x9C) + 0x1F4)
            + item * 4 + 0x44));
        break;
    case 8:
        fn_10_19154(*reinterpret_cast<void**>(
            *reinterpret_cast<u8**>(*reinterpret_cast<u8**>(p + 0x9C) + 0x1F4)
            + item * 4 + 0x44));
        break;
    case 4:
        fn_10_EE78(*reinterpret_cast<void**>(
                       *reinterpret_cast<u8**>(p + 0x9C) + 0x1F4),
                   0);
        break;
    }

    MenuObject* object = *reinterpret_cast<MenuObject**>(p + 0x40);
    u8* owner = *reinterpret_cast<u8**>(p + 0x9C);
    u32 enabled = (*reinterpret_cast<u32*>(owner + 0x1DC) >> 31) ^ 1;

    object->f3c(*reinterpret_cast<void**>(p + 0x44));

    if (enabled && !p[0xDC]) {
        object = *reinterpret_cast<MenuObject**>(p + 0x40);
        object->f34(*reinterpret_cast<void**>(
                        reinterpret_cast<u8*>(object) + 0xE4),
                    *reinterpret_cast<void**>(p + 0x44));
    }

    p[0xD0] = enabled;
    *reinterpret_cast<u32*>(p + 0xA4) = 0;
    *reinterpret_cast<u32*>(p + 0xA8) = 0;
}
