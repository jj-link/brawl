#include <types.h>
#pragma force_active on
struct Acc {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual s32 geti();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11();
    virtual f32 getf();
};
struct VBase { char pad[4]; };
struct V : VBase {
    virtual void v0(); virtual void v1();
    virtual f32 f2(void*, u32, u32);
    virtual s32 i3(void*, u32, u32);
    virtual void v4();
    virtual f32 f5(void*, u32, u32);
    virtual s32 i6(void*, u32, u32);
};
extern VBase lbl_27_bss_71C8;
struct BaseItem {
    char pad[0xCC];
    char x[0x29E0];
    Acc acc;
    f32 getParamFloat(u32 id);
    f32 F4(u32 id);
    s32 I3(u32 id);
    f32 F2(u32 id);
    s32 I1(u32 id);
};
extern "C" s32 fn_27_28CCF0(void*, s32);
#define P ((char*)this + 0xCC)
#define B ((V*)&lbl_27_bss_71C8)
inline f32 BaseItem::F4(u32 id) {
    s32 top = (s32)(id >> 28);
    s32 fl = 0;
    if (top > 0 && top < 3) fl = 1;
    if (fl != 0) {
        if ((s32)((id >> 24) & 0xF) == 0) return (f32)acc.geti();
        return acc.getf();
    }
    s32 s = (s32)id;
    if (s > 0x4e1f) return (f32)fn_27_28CCF0(this, id);
    if (s < 0x7cf) return B->f2(P, id, 0);
    return B->f5(P, id, 0);
}
inline s32 BaseItem::I3(u32 id) {
    s32 top = (s32)(id >> 28);
    s32 fl = 0;
    if (top > 0 && top < 3) fl = 1;
    if (fl != 0) {
        if ((s32)((id >> 24) & 0xF) == 1) return (s32)acc.getf();
        return acc.geti();
    }
    s32 s = (s32)id;
    if (s < 0x4e1f) return (s32)F4(id);
    if (s < 0x55ef) return B->i3(P, id, 0);
    return B->i6(P, id, 0);
}
inline f32 BaseItem::F2(u32 id) {
    s32 top = (s32)(id >> 28);
    s32 fl = 0;
    if (top > 0 && top < 3) fl = 1;
    if (fl != 0) {
        if ((s32)((id >> 24) & 0xF) == 0) return (f32)acc.geti();
        return acc.getf();
    }
    s32 s = (s32)id;
    if (s > 0x4e1f) return (f32)I3(id);
    if (s < 0x7cf) return B->f2(P, id, 0);
    return B->f5(P, id, 0);
}
inline s32 BaseItem::I1(u32 id) {
    s32 top = (s32)(id >> 28);
    s32 fl = 0;
    if (top > 0 && top < 3) fl = 1;
    if (fl != 0) {
        if ((s32)((id >> 24) & 0xF) == 1) return (s32)acc.getf();
        return acc.geti();
    }
    s32 s = (s32)id;
    if (s < 0x4e1f) return (s32)F2(id);
    if (s < 0x55ef) return B->i3(P, id, 0);
    return B->i6(P, id, 0);
}
f32 BaseItem::getParamFloat(u32 id) {
    s32 top = (s32)(id >> 28);
    s32 fl = 0;
    if (top > 0 && top < 3) fl = 1;
    if (fl != 0) {
        if ((s32)((id >> 24) & 0xF) == 0) return (f32)acc.geti();
        return acc.getf();
    }
    s32 s = (s32)id;
    if (s > 0x4e1f) return (f32)I1(id);
    if (s < 0x7cf) return B->f2(P, id, 0);
    return B->f5(P, id, 0);
}