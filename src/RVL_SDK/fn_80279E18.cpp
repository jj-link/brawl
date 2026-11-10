#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual int slot15();
};

extern "C" {
extern const f32 lbl_805A3B70;
extern const u8 lbl_805A3B74;
extern const u8 lbl_805A3B75;
extern const u8 lbl_805A3B76;
extern const u8 lbl_805A3B77;
extern const f32 lbl_805A3B78;

void fn_80278D9C(u8 width, unsigned int* color,
                 f32 x1, f32 y1, f32 x2, f32 y2, f32 z);
}

struct Dimensions {
    f32 x;
    f32 y;
};

extern "C" void fn_80279E18(void* arg) {
    char* self = static_cast<char*>(arg);
    Object_vptr_0* object = *reinterpret_cast<Object_vptr_0**>(self + 0x28);

    if (object->slot15() != 0) {
        char* data = *reinterpret_cast<char**>(self + 0x2C);
        Dimensions size;
        size.x = *reinterpret_cast<f32*>(data + 0x4C);
        size.y = *reinterpret_cast<f32*>(data + 0x50);
        f32 x = *reinterpret_cast<f32*>(data + 0x90);
        f32 y = *reinterpret_cast<f32*>(data + 0xA0);

        u8 color[4] = {
            lbl_805A3B74,
            lbl_805A3B75,
            lbl_805A3B76,
            lbl_805A3B77
        };

        if (*reinterpret_cast<u8*>(self + 4) != 0) {
            color[0] = 0;
            color[2] = 255;
        }

        fn_80278D9C(8, reinterpret_cast<unsigned int*>(color),
                     x - size.x * lbl_805A3B78,
                     y - size.y * lbl_805A3B78,
                     x + size.x * lbl_805A3B78,
                     y - size.y * lbl_805A3B78,
                     lbl_805A3B70);

        fn_80278D9C(8, reinterpret_cast<unsigned int*>(color),
                     x + size.x * lbl_805A3B78,
                     y - size.y * lbl_805A3B78,
                     x + size.x * lbl_805A3B78,
                     y + size.y * lbl_805A3B78,
                     lbl_805A3B70);

        fn_80278D9C(8, reinterpret_cast<unsigned int*>(color),
                     x + size.x * lbl_805A3B78,
                     y + size.y * lbl_805A3B78,
                     x - size.x * lbl_805A3B78,
                     y + size.y * lbl_805A3B78,
                     lbl_805A3B70);

        fn_80278D9C(8, reinterpret_cast<unsigned int*>(color),
                     x - size.x * lbl_805A3B78,
                     y + size.y * lbl_805A3B78,
                     x - size.x * lbl_805A3B78,
                     y - size.y * lbl_805A3B78,
                     lbl_805A3B70);
    }
}
