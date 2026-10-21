#pragma force_active on
typedef unsigned char u8;

struct Base4 {
    unsigned int value;
};

struct CastObject : Base4 {
    virtual void f0();
    virtual ~CastObject();
};

extern "C" {
extern u8 lbl_40_data_2AC8[];
extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];

void exit__6gfTaskFv(void*);
void __dla__FPv(void*);
void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

void* fn_40_125EC(u8* self, int deleting)
{
    if (self) {
        void* task = *reinterpret_cast<void**>(self + 0x98);
        *reinterpret_cast<void**>(self + 4) = lbl_40_data_2AC8;
        if (task) {
            exit__6gfTaskFv(task);
        }

        void* array = *reinterpret_cast<void**>(self + 0x94);
        if (array) {
            __dla__FPv(array);
        }
        *reinterpret_cast<void**>(self + 0x94) = 0;

        if (self) {
            *reinterpret_cast<void**>(self + 4) = lbl_40_data_11A0;
            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4,
                               lbl_40_data_11D8, lbl_40_data_1610, 0)) {
                delete static_cast<CastObject*>(
                    __dynamic_cast(*reinterpret_cast<void**>(self), 4,
                                   lbl_40_data_11D8, lbl_40_data_1610, 0));
            }
        }

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
