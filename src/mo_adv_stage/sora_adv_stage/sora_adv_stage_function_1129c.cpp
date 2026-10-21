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
extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];

void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

void* fn_40_1129C(u8* self, int deleting)
{
    if (self) {
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
