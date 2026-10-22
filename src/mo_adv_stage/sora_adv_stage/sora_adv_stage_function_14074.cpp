#pragma force_active on
typedef unsigned char u8;

struct Base4 {
    unsigned int value;
};

struct CastTarget : Base4 {
    virtual void f0();
    virtual void f3(int);
};

struct Gen : Base4 {
    virtual void f1(int);
};

extern "C" {
extern u8 lbl_40_data_2E44[];
extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];

void stopSE__14snd3DGeneratorFll(void*, long, long);
void __dla__FPv(void*);
void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

void* fn_40_14074(u8* self, int deleting)
{
    if (self) {
        *reinterpret_cast<void**>(self + 4) = lbl_40_data_2E44;
        if (*reinterpret_cast<Gen**>(self + 0x28)) {
            for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0xc); i++) {
                u8* e = *reinterpret_cast<u8**>(self + 0x10) + i * 0x20;
                if (*e) {
                    stopSE__14snd3DGeneratorFll(*reinterpret_cast<void**>(self + 0x28), *reinterpret_cast<long*>(e + 8), 0);
                }
            }
            Gen* g = *reinterpret_cast<Gen**>(self + 0x28);
            if (g) {
                g->f1(1);
            }
        }
        *reinterpret_cast<void**>(self + 0x28) = 0;
        void* arr = *reinterpret_cast<void**>(self + 0x10);
        if (arr) {
            if (arr)
            __dla__FPv(static_cast<u8*>(arr) - 0x10);
        }
        *reinterpret_cast<void**>(self + 0x10) = 0;

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
