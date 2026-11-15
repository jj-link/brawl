#include <types.h>
#pragma force_active on

struct Object_vptr_1c_base { char pad[0x1c]; };
class Object_vptr_1c : public Object_vptr_1c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* arg);
};

struct Obj {
    char pad0[0x0c];
    int w0c;
    char pad1[0x3c];
    char sub[8];
    u8 f54;
    u8 f55;
    char pad2[6];
    float f5c;
};

extern "C" {
void* fn_8016FBF4(void* p);
int fn_8016FBC8(void* p);
void fn_8005AD04();
void fn_801643E0(void* self, void (*f)(), int a, int b);
void fn_80164480(void* self, void (*f)(), int a, int b);
void fn_8005D118();
void fn_8005D2E4();
void fn_8005D34C();

extern void* lbl_805A0110;
extern int lbl_805A0118[2];
extern int lbl_805A0120[2];
extern int lbl_805A0128;
extern int lbl_805A012C;
extern int lbl_805A0130;
extern int lbl_805A0134;
extern float lbl_805A0138;

void fn_8005CE70(Obj* self) {
    int state = self->w0c >> 24;
    if ((state == 2 || state == 4) && fn_8016FBC8(self->sub) != 0) {
        char* r31;
        if (lbl_805A0110 == 0) {
            fn_8005AD04();
        }
        r31 = (char*)lbl_805A0110 + 0x84;
        if (!(self->f55 & 1)) {
            lbl_805A0128 = lbl_805A0118[0];
            lbl_805A012C = lbl_805A0118[1];
            lbl_805A0130 = lbl_805A0120[0];
            lbl_805A0134 = lbl_805A0120[1];
        } else {
            lbl_805A0128 = lbl_805A0118[1];
            lbl_805A012C = lbl_805A0118[0];
            lbl_805A0130 = lbl_805A0120[1];
            lbl_805A0134 = lbl_805A0120[0];
        }
        int v = self->f54;
        v &= 0xFFFFFFEF;
        self->f54 = (u8)v;
        if ((v >> 5) & 1) {
            float f31 = self->f5c;
            void* r30 = fn_8016FBF4(self->sub);
            lbl_805A0138 = f31;
            if (((u8)self->f54 >> 4) & 1) {
                if (!(self->f55 & 1)) {
                    lbl_805A0128 = lbl_805A0118[0];
                    lbl_805A012C = lbl_805A0118[1];
                    lbl_805A0130 = lbl_805A0120[0];
                    lbl_805A0134 = lbl_805A0120[1];
                } else {
                    lbl_805A0128 = lbl_805A0118[1];
                    lbl_805A012C = lbl_805A0118[0];
                    lbl_805A0130 = lbl_805A0120[1];
                    lbl_805A0134 = lbl_805A0120[0];
                }
                self->f54 = self->f54 & 0xFFFFFFEF;
            }
            fn_801643E0(r30, fn_8005D118, 0, 0);
            fn_80164480(r30, fn_8005D34C, 0, 1);
            ((Object_vptr_1c*)fn_8016FBF4(self->sub))->slot5(r31);
        } else {
            ((Object_vptr_1c*)fn_8016FBF4(self->sub))->slot5(r31);
        }
        void* r30b = fn_8016FBF4(self->sub);
        if (((u8)self->f54 >> 4) & 1) {
            if (!(self->f55 & 1)) {
                lbl_805A0128 = lbl_805A0118[0];
                lbl_805A012C = lbl_805A0118[1];
                lbl_805A0130 = lbl_805A0120[0];
                lbl_805A0134 = lbl_805A0120[1];
            } else {
                lbl_805A0128 = lbl_805A0118[1];
                lbl_805A012C = lbl_805A0118[0];
                lbl_805A0130 = lbl_805A0120[1];
                lbl_805A0134 = lbl_805A0120[0];
            }
            self->f54 = self->f54 & 0xFFFFFFEF;
        }
        fn_801643E0(r30b, fn_8005D2E4, 1, 1);
        fn_80164480(r30b, fn_8005D34C, 1, 1);
    }
}
}