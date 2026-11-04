#pragma force_active on
extern "C" unsigned int OSGetTick();

struct Lbl_8049DDC0 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};
extern Lbl_8049DDC0 lbl_8049DDC0;
extern int lbl_805A0214;
extern "C" void fn_8007C61C(unsigned int, unsigned int, unsigned int);

extern "C" void fn_8007F15C(void* self, unsigned int arg1) {
    if (lbl_805A0214 != 0) {
        Lbl_8049DDC0* ptr = &lbl_8049DDC0;
        unsigned int divisor = ptr->d;
        unsigned int remainder;
        if (divisor != 1) {
            remainder = OSGetTick() % ptr->d;
        } else {
            remainder = 0;
        }
        fn_8007C61C(0, arg1, remainder);
    }
}