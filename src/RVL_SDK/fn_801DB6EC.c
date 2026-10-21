#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 viTVMode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    u32 xFBmode;
    unsigned char field_rendering;
    unsigned char aa;
    unsigned char sample_pattern[12][2];
    unsigned char vfilter[7];
} RenderMode;

extern int fn_801E9BDC(void);
extern void fn_801E8DC8(RenderMode*);
extern void fn_801E955C(int, int, int, int);

void fn_801DB6EC(u16 width, u16 height)
{
    RenderMode mode;

    mode.fbWidth = width;
    mode.efbHeight = 480;
    mode.xfbHeight = height;
    mode.viXOrigin = 40;
    mode.viWidth = 640;
    mode.viHeight = height;

    switch (fn_801E9BDC()) {
    case 0:
    case 2:
        if (*(u16*)0xCC00206C & 1) {
            mode.viTVMode = 2;
            mode.viYOrigin = 0;
            mode.xFBmode = 0;
        } else {
            mode.viTVMode = 0;
            mode.viYOrigin = 0;
            mode.xFBmode = 1;
        }
        break;
    case 5:
        mode.viTVMode = 20;
        mode.viYOrigin = 0;
        mode.xFBmode = 1;
        break;
    case 1:
        mode.viTVMode = 4;
        mode.viYOrigin = 47;
        mode.xFBmode = 1;
        break;
    }

    fn_801E8DC8(&mode);
    fn_801E955C(0, 0, 640, 480);
}
