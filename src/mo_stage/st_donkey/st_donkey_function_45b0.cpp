#include <math.h>
#pragma force_active on

struct Constants {
    float x[21];
};

union GXColor {
    struct {
        unsigned char r, g, b, a;
    };
    unsigned long rgba;
};

struct CopiedMatAccess {
    unsigned char data[0x34];
};

extern "C" {
extern const Constants lbl_50_rodata_A0;
extern char lbl_50_data_1520[];

void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, void*, unsigned long);
void* GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(void*, bool);
void GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(
    void*, unsigned long, GXColor);
void fn_80190A3C(void*, bool);
void DCStore__Q34nw4r3g3d6ResMatFb(void*, bool);
}

extern "C" void fn_50_45B0(unsigned char* self) {
    const Constants* data = &lbl_50_rodata_A0;
    float value;

    switch (self[0x150]) {
    case 3:
        value = *(float*)(self + 0x154) / __fabsf(data->x[4]);
        break;
    case 4:
        value = data->x[0];
        break;
    case 5:
        value = data->x[10] -
                *(float*)(self + 0x154) / __fabsf(data->x[4]);
        break;
    default:
        value = data->x[10];
        break;
    }

    void* mdl = 0;
    void* mat = 0;
    void* tev = 0;
    GXColor color;
    color.rgba = 0xffffffff;

    void* obj = **(void***)(self + 0x44);
    if (!obj)
        return;

    mdl = *(void**)((unsigned char*)obj + 0xe8);
    if (!mdl)
        return;

    mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&mdl, lbl_50_data_1520);
    if (!mat)
        return;

    CopiedMatAccess access;
    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
        &access, obj, *(unsigned long*)((unsigned char*)mat + 0xc));

    tev = GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(
        &access, false);
    if (!tev)
        return;

    unsigned char c =
        (unsigned char)(int)(data->x[11] - data->x[12] * value);
    color.r = c;
    color.g = c;
    color.b = c;
    color.a = 255;

    GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(&tev, 1, color);
    fn_80190A3C(&tev, false);
    DCStore__Q34nw4r3g3d6ResMatFb(&mat, false);
}
