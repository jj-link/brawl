#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

extern "C" {
extern const Color lbl_27_rodata_4FC;
extern const Color lbl_27_rodata_500;
}

struct TargetBase {
    unsigned char padding[0x30];
};

struct Target : TargetBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void setColors(int, const Color*, const Color*);
};

extern "C" void fn_27_4B0E8(int* self, int arg, Target* target)
{
    if (*self != 1) {
        Color first = lbl_27_rodata_4FC;
        Color second = lbl_27_rodata_500;
        target->setColors(arg, &first, &second);
    }
}
