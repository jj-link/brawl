#pragma fp_contract off

#include <nw4r/snd/snd_MoveValue.h>
#include <revolution/DVD/dvd.h>
#pragma force_active on

extern "C" {
int fn_801D2AD0();
void fn_801D31E8(int, int);
void fn_801B8458(void*, int);
void fn_802009E8(unsigned short);
void fn_80200A00(unsigned short);
void fn_80200A08(unsigned short);
void fn_80200A10(unsigned short);

extern const float lbl_805A3440;
extern const float lbl_805A3444;
extern const float lbl_805A3450;
}

typedef nw4r::snd::detail::MoveValue<float, int> Ramp;

struct State {
    char pad[0x1a];
    unsigned char disc;
    char pad1[1];
    Ramp a;
    Ramp b;
    Ramp c;
    char pad2[8];
    Ramp d[3];
    Ramp e[3];
};

extern "C" void fn_801B7ABC(State* self) {
    if ((unsigned int)DVDGetDriveStatus() <= 1) {
        if (self->disc) {
            self->disc = 0;
            fn_801D31E8(fn_801D2AD0(), 2);
        }
    } else if (!self->disc) {
        self->disc = 1;
        fn_801D31E8(fn_801D2AD0(), 2);
    }

    State* p = self;
    for (int i = 0; i < 3; ++i, p = (State*)((char*)p + 0x10)) {
        int changed = 0;

        if (!p->e[0].IsFinished()) {
            p->e[0].Update();
            changed = 1;
        }

        if (!p->d[0].IsFinished()) {
            p->d[0].Update();
            if (p->d[0].IsFinished())
                fn_801B8458(self, i);
            changed = 1;
        }

        if (changed) {
            float v = lbl_805A3444;
            float x = p->e[0].GetValue();
            if (x > lbl_805A3444)
                x = lbl_805A3444;
            else if (x < lbl_805A3440)
                x = lbl_805A3440;

            v *= x;
            x = p->d[0].GetValue();
            if (x > lbl_805A3444)
                x = lbl_805A3444;
            else if (x < lbl_805A3440)
                x = lbl_805A3440;

            v *= x;
            int n = (int)(lbl_805A3450 * v);
            switch (i) {
            case 0:
                fn_80200A00((unsigned short)n);
                break;
            case 1:
                fn_80200A08((unsigned short)n);
                break;
            case 2:
                fn_80200A10((unsigned short)n);
                break;
            }
        }
    }

    if (!self->a.IsFinished()) {
        self->a.Update();
        fn_801D31E8(fn_801D2AD0(), 8);
    }

    if (!self->c.IsFinished())
        self->c.Update();

    if (!self->b.IsFinished())
        self->b.Update();

    float v = self->b.GetValue() * self->c.GetValue();
    float x;
    if (v > lbl_805A3444)
        x = lbl_805A3444;
    else if (v < lbl_805A3440)
        x = lbl_805A3440;
    else
        x = v;

    fn_802009E8((unsigned short)(lbl_805A3450 * x));
}
