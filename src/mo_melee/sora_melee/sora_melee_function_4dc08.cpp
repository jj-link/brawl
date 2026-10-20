#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

class Object {
    unsigned char unused[0x30];

public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void setColors(int, const Color*, const Color*);
};

extern "C" {
extern const Color lbl_27_rodata_524;
extern const Color lbl_27_rodata_528;

void fn_27_4DC08(int* self, int arg, Object* object) {
    if (*self != 1) {
        Color first = lbl_27_rodata_524;
        Color second = lbl_27_rodata_528;
        object->setColors(arg, &first, &second);
    }
}
}
