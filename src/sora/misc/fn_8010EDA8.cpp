#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

extern "C" {
void fn_801AAF90(void*, unsigned int, void*);
void fn_801F51DC(const void*, unsigned int);
void fn_801F52E4(int);
void fn_801EFB10();
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F12E0(unsigned char*, unsigned int*);
}

struct Point {
    unsigned short id;
    char pad[6];
    float x, y;
    char pad2[4];
    unsigned char flag7 : 1;
    unsigned char flag6 : 1;
    unsigned char rest : 6;
};

struct Settings {
    char pad[4];
    unsigned int color;
    unsigned char width;
    char pad2[7];
    float z;
};

struct Object {
    char pad[8];
    void* member;
    char pad2[0x3c8];
    int enabled;
    Settings* settings;
    char pad3[0xc];
    char* points;
    unsigned int stride;
    unsigned int count;
};

struct Pair {
    float x, y;
};

struct LineState {
    unsigned char width;
    unsigned int offset;
};

extern "C" void fn_8010EDA8(Object* obj)
{
            Point* next;
    Mtx matrix;

    if (obj->enabled) {
        LineState line;

        fn_801AAF90(obj->member, 2, matrix);
        fn_801F51DC(matrix, 0);
        fn_801F52E4(0);
        GXSetNumTevStages(1);
        GXSetNumIndStages(0);
        GXSetNumTexGens(0);
        GXSetNumChans(1);
        GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)255,
                      (GXTexMapID)255, (GXChannelID)4);
        GXSetTevOp((GXTevStageID)0, (GXTevMode)4);
        GXSetChanCtrl((GXChannelID)4, 0, (GXColorSrc)1, (GXColorSrc)1,
                      (GXLightID)0, (GXDiffuseFn)0, (GXAttnFn)2);
        fn_801EFB10();
        fn_801EF280(9, 1);
        fn_801EFB44(0, 9, 1, 4, 0);
        fn_801EF280(11, 1);
        fn_801EFB44(0, 11, 1, 5, 0);
        fn_801F12E0(&line.width, &line.offset);
        GXSetLineWidth(obj->settings->width, 0);

        float z = obj->settings->z;
        GXBegin((GXPrimitive)0xA8, (GXVtxFmt)0, obj->count);

        for (unsigned int i = 0; i < obj->count;) {
            next = (Point*)(obj->points + obj->stride * (i + 1));
            Point* current = (Point*)(obj->points + obj->stride * i);
            Pair* first = (Pair*)&current->x;
            Pair* selected = next->id == 255 ? first : (Pair*)&next->x;
            Pair result = *selected;

            if (!current->flag6 || !current->flag7 || !next->flag7) {
                result.x = first->x;
                result.y = first->y;
            }

            i += 2;
            unsigned int color = obj->settings->color;
            float rx = result.x;
            GXPosition3f32(first->x, first->y, z);
            GXColor1u32(color);
            WGPIPE.f = rx;
            WGPIPE.f = result.y;
            WGPIPE.f = z;
            WGPIPE.ui = color;
        }

        GXSetLineWidth(line.width, line.offset);
    }
}
