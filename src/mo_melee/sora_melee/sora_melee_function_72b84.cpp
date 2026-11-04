#pragma force_active on
class Class_2F8E8 {
public:
    virtual void fn_27_174D8C();
    virtual void fn_27_1744D4();
    virtual void fn_27_17496C();
    virtual void fn_27_73E4C();
    virtual void fn_27_73EF8();
    virtual void fn_27_73FA4(short*, int, int, int, float);
};
extern const float lbl_27_rodata_9B8;
extern "C" void fn_27_72B84(Class_2F8E8* self, int a, int b, int c, int d) {
    short x[2];
    x[0] = 4;
    self->fn_27_73FA4(x, d, -1, 0, lbl_27_rodata_9B8);
    short y = 1;
    self->fn_27_73FA4(&y, d, a, 0, lbl_27_rodata_9B8);
}