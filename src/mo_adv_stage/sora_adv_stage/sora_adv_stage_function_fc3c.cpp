#pragma force_active on
typedef unsigned char u8;

struct Base4 {
    unsigned int value;
};

struct CastTarget : Base4 {
    virtual void f0();
    virtual void f3(int);
};

extern "C" {
extern u8 lbl_40_data_1FC0[];
extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];
extern void* g_gfSceneRoot;

void __dla__FPv(void*);
void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_238230(void*, int, void*);

void* fn_40_FC3C(u8* self, int deleting)
{
    if (self) {
        void* p14 = *reinterpret_cast<void**>(self + 0x14);
        *reinterpret_cast<void**>(self + 4) = lbl_40_data_1FC0;
        if (p14) {
            __dla__FPv(p14);
            *reinterpret_cast<void**>(self + 0x14) = 0;
        }

        void* p18 = *reinterpret_cast<void**>(self + 0x18);
        if (p18) {
            if (p18) {
                __dla__FPv((u8*)p18 - 0x10);
            }
            *reinterpret_cast<void**>(self + 0x18) = 0;
        }

        void* p1c = *reinterpret_cast<void**>(self + 0x1c);
        if (p1c) {
            if (p1c) {
                __dla__FPv((u8*)p1c - 0x10);
            }
            *reinterpret_cast<void**>(self + 0x1c) = 0;
        }

        void* p20 = *reinterpret_cast<void**>(self + 0x20);
        if (p20) {
            __dla__FPv(p20);
            *reinterpret_cast<void**>(self + 0x20) = 0;
        }

        void* scene = *reinterpret_cast<void**>((u8*)g_gfSceneRoot + 0x40);
        *reinterpret_cast<void**>((u8*)scene + 0xd4) = 0;
        fn_27_238230(self + 0x30, -1, scene);

        if (self) {
            *reinterpret_cast<void**>(self + 4) = lbl_40_data_11A0;
            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4,
                               lbl_40_data_11D8, lbl_40_data_1610, 0)) {
                CastTarget* target = static_cast<CastTarget*>(
                    __dynamic_cast(*reinterpret_cast<void**>(self), 4,
                                   lbl_40_data_11D8, lbl_40_data_1610, 0));
                if (target) {
                    target->f3(1);
                }
            }
        }

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
