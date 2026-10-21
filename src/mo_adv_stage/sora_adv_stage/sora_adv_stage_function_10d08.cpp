#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void __dl__FPv(void*);
}

struct Pad4 {
    int pad;
};

struct VIface : Pad4 {
    virtual void f0();
    virtual void f1(int);
};

extern "C" void* fn_40_10D08(u8* self, int deleting)
{
    if (self) {
        if (self) {
            *reinterpret_cast<void**>(self + 4) = lbl_40_data_11A0;

            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4,
                               lbl_40_data_11D8, lbl_40_data_1610, 0)) {
                void* obj = __dynamic_cast(*reinterpret_cast<void**>(self), 4,
                                           lbl_40_data_11D8, lbl_40_data_1610, 0);
                if (obj) {
                    reinterpret_cast<VIface*>(obj)->f1(1);
                }
            }
        }

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
