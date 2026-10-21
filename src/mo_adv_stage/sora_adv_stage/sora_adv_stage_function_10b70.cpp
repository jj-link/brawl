#pragma force_active on
typedef unsigned char u8;
extern "C" void __dl__FPv(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" u8 lbl_40_data_11A0[];
extern "C" u8 lbl_40_data_11D8[];
extern "C" u8 lbl_40_data_1610[];

struct Pad {
    unsigned int unk0;
};

struct IFace : Pad {
    virtual void f0();
    virtual void f1(int);
    virtual void f2();
};

extern "C" void* fn_40_10B70(u8* self, int deleting)
{
    if (self) {
        if (self) {
            *reinterpret_cast<void**>(self + 4) = lbl_40_data_11A0;
            void* p = __dynamic_cast(*reinterpret_cast<void**>(self), 4, lbl_40_data_11D8, lbl_40_data_1610, 0);
            if (p) {
                void* q = __dynamic_cast(*reinterpret_cast<void**>(self), 4, lbl_40_data_11D8, lbl_40_data_1610, 0);
                if (q) {
                    reinterpret_cast<IFace*>(q)->f1(1);
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
