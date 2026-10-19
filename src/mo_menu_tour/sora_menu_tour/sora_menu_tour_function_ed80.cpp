#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_3_data_DA0[];
void fn_800B8A0C(void*, int);
void fn_18_113C(void*, int);
void __dl__FPv(void*);

void* fn_3_ED80(u8* object, int deleting)
{
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_3_data_DA0;
        fn_800B8A0C(*reinterpret_cast<void**>(object + 0x48), 1);
        fn_18_113C(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
