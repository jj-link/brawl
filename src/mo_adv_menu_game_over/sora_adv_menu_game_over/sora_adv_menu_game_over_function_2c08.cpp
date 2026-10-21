#pragma force_active on
typedef unsigned char u8;

class Obj {
    char pad[0x5C];
public:
    virtual void m(int);
};

extern "C" {
extern u8 lbl_33_data_420[];
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void fn_800FAEB8(void*, int);
void __dl__FPv(void*);

void* fn_33_2C08(u8* object, int deleting)
{
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_33_data_420;
        fn_800B8EDC(*reinterpret_cast<void**>(object + 0x1D4), *reinterpret_cast<void**>(object + 0x1D0));
        if (object + 0x1D4) {
            fn_800B8A0C(*reinterpret_cast<void**>(object + 0x1D4), 1);
        }
        if (object + 0x1D0) {
            Obj* t = *reinterpret_cast<Obj**>(object + 0x1D0);
            if (t) {
                t->m(1);
            }
        }
        if (object) {
            fn_800FAEB8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
