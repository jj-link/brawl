#pragma force_active on

typedef float f32;
typedef int s32;

extern "C" void fn_27_17EFB4(void *, s32);
extern f32 lbl_27_rodata_2390[3];

class Inner {
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
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void call(int, void *, f32, f32);
};

struct Holder {
    unsigned char pad[0xA8];
    Inner *inner;
};

struct Self {
    unsigned char pad[0xD8];
    Holder *holder;
};

extern "C" void fn_27_17DA08(void *, Self *self, s32 id) {
    fn_27_17EFB4(self, id);

    switch (id) {
    case 0x9B:
    case 0xA4:
    case 0xA5:
    case 0xA6:
    case 0xA7:
    case 0xA8:
    case 0xA9:
    case 0xAA:
    case 0xAB:
    case 0xAC:
    case 0xAD:
    case 0xAE:
        break;

    default:
        Holder *holder = self->holder;
        holder->inner->call(0, holder, lbl_27_rodata_2390[0],
                            lbl_27_rodata_2390[0]);
        break;
    }
}
