#include <cstddef>
#pragma force_active on

extern "C" void fn_104_40F4(void*, short);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_406C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        void* member1;
        void* member2;
        void* member3;
        void* member4;
        member1 = storage + 0x8C;
        fn_104_40F4(member1, -1);
        member2 = storage + 0x20;
        member3 = storage + 0x20;
        member4 = storage + 0x20;
        if (member2 != 0 && member3 != 0 && member4 != 0) {
            fn_27_1A1E70(storage + 0x20, -1);
        }
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}