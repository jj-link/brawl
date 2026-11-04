#pragma force_active on
typedef unsigned char u8;
struct Color { u8 r,g,b,a; };
extern "C" void fn_8016C160(void*, int, Color*, Color*);
extern "C" void fn_801F3D60(int, const void*);
extern "C" void fn_801F3E24(int, const void*);
extern "C" int fn_801755C0(u8* a, void* b, u8* c, int force) {
    Color x, y;
    int changed = 0;
    if (a[0xac]) {
        fn_8016C160(b, 0, &x, &y);
        if (force || a[0x94]!=x.r || a[0x95]!=x.g || a[0x96]!=x.b || a[0x97]!=x.a ||
            a[0x98]!=y.r || a[0x99]!=y.g || a[0x9a]!=y.b || a[0x9b]!=y.a) {
            changed = 1;
            a[0x94]=x.r; a[0x95]=x.g; a[0x96]=x.b; a[0x97]=x.a;
            a[0x98]=y.r; a[0x99]=y.g; a[0x9a]=y.b; a[0x9b]=y.a;
            for (int i=0;i<3;i++) {
                if (c[0x5d+i]==1) { Color t=x; fn_801F3D60(i+1,&t); }
                if (c[0x5e]==2) { Color t=y; fn_801F3D60(i+1,&t); }
            }
            for (int i=0;i<4;i++) {
                if (c[0x60+i]==1) { Color t=x; fn_801F3E24(i,&t); }
                if (c[0x60+i]==2) { Color t=y; fn_801F3E24(i,&t); }
            }
        }
    }
    if (a[0xad]) {
        fn_8016C160(b, 1, &x, &y);
        if (force || a[0x9c]!=x.r || a[0x9d]!=x.g || a[0x9e]!=x.b || a[0x9f]!=x.a ||
            a[0xa0]!=y.r || a[0xa1]!=y.g || a[0xa2]!=y.b || a[0xa3]!=y.a) {
            changed = 1;
            a[0x9c]=x.r; a[0x9d]=x.g; a[0x9e]=x.b; a[0x9f]=x.a;
            a[0xa0]=y.r; a[0xa1]=y.g; a[0xa2]=y.b; a[0xa3]=y.a;
            for (int i=0;i<3;i++) {
                if (c[0x5d+i]==3) { Color t=x; fn_801F3D60(i+1,&t); }
                if (c[0x5e]==4) { Color t=y; fn_801F3D60(i+1,&t); }
            }
            for (int i=0;i<4;i++) {
                if (c[0x60+i]==3) { Color t=x; fn_801F3E24(i,&t); }
                if (c[0x60+i]==4) { Color t=y; fn_801F3E24(i,&t); }
            }
        }
    }
    return changed;
}