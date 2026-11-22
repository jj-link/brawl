#include <gf/gf_draw.h>
#include <revolution/GX/GXPixel.h>
#pragma force_active on

struct Obj {
    char pad[0x154];
    void* file;
    unsigned char mode;
    char pad2[3];
    int count;
    void* data;
};

struct Pair {
    const char* a;
    const char* b;
};

extern "C" {
extern Pair lbl_48_data_18F8[];

void fn_48_A4E0(int, void*, int*, int*, short*, short*);
void fn_48_A050(int, void*, short*, int);
int fn_8018E374(void*);
void* fn_8018D3F0(void*, const char*);
void fn_8001AA88(void*, void**);
void fn_801F2C58(void*, int, int);
void fn_801F2FB0(void*, int);
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
}

extern "C" void fn_48_A624(Obj* self) {
    short first[255];
    short second[14];
    char tex1[32];
    char tex2[32];
    int n1, n2;
    void* res1;
    void* res2;

    if (!self) {
        return;
    }

    int count = self->count;
    unsigned char mode = self->mode;
    void* data = self->data;

    if (!count || !data) {
        return;
    }

    fn_48_A4E0(count, data, &n1, &n2, first, second);

    if (n1 > 0) {
        const char* name = mode >= 2 ? 0 : lbl_48_data_18F8[mode].a;

        if (self) {
            int valid;
            if (self->file && fn_8018E374(&self->file))
                valid = 1;
            else
                valid = 0;

            if (!valid) {
                gfDrawSetVtxPosColorPrimEnvironment();
            } else {
                gfDrawSetVtxPosColorTexPrimEnvironment();
                res1 = fn_8018D3F0(&self->file, name);
                fn_8001AA88(tex1, &res1);
                fn_801F2C58(tex1, 0, 0);
                fn_801F2FB0(tex1, 0);
            }

            fn_801EF280(13, 1);
            fn_801EFB44(1, 13, 1, 4, 0);
            GXSetZMode(1, GX_LEQUAL, 1);
        }

        fn_48_A050(n1, data, first, 0);
    }

    if (n2 > 0) {
        const char* name = mode >= 2 ? 0 : lbl_48_data_18F8[mode].b;

        if (self) {
            int valid;
            if (self->file && fn_8018E374(&self->file))
                valid = 1;
            else
                valid = 0;

            if (!valid) {
                gfDrawSetVtxPosColorPrimEnvironment();
            } else {
                gfDrawSetVtxPosColorTexPrimEnvironment();
                res2 = fn_8018D3F0(&self->file, name);
                fn_8001AA88(tex2, &res2);
                fn_801F2C58(tex2, 0, 0);
                fn_801F2FB0(tex2, 0);
            }

            fn_801EF280(13, 1);
            fn_801EFB44(1, 13, 1, 4, 0);
            GXSetZMode(1, GX_LEQUAL, 1);
        }

        fn_48_A050(n2, data, second, 1);
    }
}
