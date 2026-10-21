#pragma force_active on

typedef unsigned char u8;

extern "C" void __dl__FPv(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];

struct ObjectBase {
    unsigned int data;
};

struct Object : ObjectBase {
    virtual void f0();
    virtual void destroy(int);
};

extern "C" void* fn_40_10C3C(void* self, int flag) {
    if (self) {
        if (self) {
            *reinterpret_cast<void**>((u8*)self + 4) = lbl_40_data_11A0;
            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4,
                               lbl_40_data_11D8, lbl_40_data_1610, 0)) {
                Object* obj = static_cast<Object*>(
                    __dynamic_cast(*reinterpret_cast<void**>(self), 4,
                                   lbl_40_data_11D8, lbl_40_data_1610, 0));
                if (obj) {
                    obj->destroy(1);
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
