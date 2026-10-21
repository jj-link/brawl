#pragma force_active on

typedef unsigned char u8;

extern "C" void __dl__FPv(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" u8 lbl_40_data_11A0[];
extern "C" u8 lbl_40_data_11D8[];
extern "C" u8 lbl_40_data_1610[];

struct Base {
    u8 pad[4];
};

struct Target : Base {
    virtual void f0();
    virtual void destroy(int);
};

extern "C" void* fn_40_8C84(void* self, int deleting) {
    if (self) {
        if (self) {
            *reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 4) =
                lbl_40_data_11A0;

            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4,
                               lbl_40_data_11D8, lbl_40_data_1610, 0)) {
                if (void* p = __dynamic_cast(*reinterpret_cast<void**>(self), 4,
                                             lbl_40_data_11D8,
                                             lbl_40_data_1610, 0)) {
                    reinterpret_cast<Target*>(p)->destroy(1);
                }
            }
        }

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
