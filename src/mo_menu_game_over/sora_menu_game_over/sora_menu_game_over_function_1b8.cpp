#pragma force_active on

typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];

public:
    virtual ~MenuObject();
};

extern "C" {
extern u8 lbl_12_data_98[];

void fn_800B8A0C(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_12_1B8(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_12_data_98;

        if (*reinterpret_cast<void**>(object + 0x50)) {
            fn_800B8A0C(*reinterpret_cast<void**>(object + 0x50), 1);
        }

        MenuObject* entry = *reinterpret_cast<MenuObject**>(object + 0x40);
        if (entry) {
            delete entry;
        }

        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
