#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

struct Manager {
    void* m0;
    void* m4;
    void* m8;
    void* mC;
    u8 m10;
    void* m14;
};

extern "C" {

extern u8 lbl_805A0580;
extern Manager lbl_804C1CC8;
extern u8 lbl_804C1CB8[0x10];
extern void fn_801BD71C(void*);
extern void __register_global_object(void*, void*, void*);

Manager* fn_801BD6A0(void) {
    if ((s8)lbl_805A0580 == 0) {
        void* p;
        lbl_804C1CC8.m8 = 0;
        p = &lbl_804C1CC8.m8;
        lbl_804C1CC8.mC = 0;
        lbl_804C1CC8.m0 = 0;
        lbl_804C1CC8.m4 = 0;
        lbl_804C1CC8.m8 = p;
        lbl_804C1CC8.mC = p;
        lbl_804C1CC8.m10 = 0;
        lbl_804C1CC8.m14 = 0;
        __register_global_object(&lbl_804C1CC8, (void*)fn_801BD71C, lbl_804C1CB8);
        lbl_805A0580 = 1;
    }
    return &lbl_804C1CC8;
}

}
