#pragma force_active on
extern "C" void* fn_109_105D8(void*, short);
extern "C" void* fn_109_3A94(void*, short);
extern "C" void* fn_109_10634(void*, short);
extern "C" void* fn_109_2DF0(void*, short);
extern "C" void* fn_109_10690(void*, short);
extern "C" void* fn_109_3AF0(void*, short);
extern "C" void* fn_109_1071C(void*, short);
extern "C" void* fn_109_108A8(void*, short);
extern "C" void* fn_109_3E10(void*, short);
extern "C" void* fn_109_3F44(void*, short);
extern "C" void* fn_109_3FA0(void*, short);
extern "C" void* fn_109_10B34(void*, short);
extern "C" void* fn_109_4014(void*, short);
extern "C" void* fn_109_10B90(void*, short);
extern "C" void* fn_109_4080(void*, short);
extern "C" void* fn_109_10C3C(void*, short);
extern "C" void* fn_109_10C98(void*, short);
extern "C" void* fn_109_40E0(void*, short);
extern "C" void* fn_109_10D0C(void*, short);
extern "C" void* fn_109_4164(void*, short);
extern "C" void* fn_109_4230(void*, short);
extern "C" void* fn_109_428C(void*, short);
extern "C" void* fn_109_10DEC(void*, short);
extern "C" void* fn_109_43E4(void*, short);
extern "C" void* fn_109_4450(void*, short);
extern "C" void* fn_109_4508(void*, short);
extern "C" void* fn_109_4548(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_109_10F68(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_10428(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_105D8(storage + 0x2708, -1);
        fn_109_3A94(storage + 0x26F0, -1);
        fn_109_10634(storage + 0x2598, -1);
        fn_109_2DF0(storage + 0x254C, -1);
        fn_109_10690(storage + 0x23B4, -1);
        fn_109_3AF0(storage + 0x2354, -1);
        fn_109_1071C(storage + 0x22A0, -1);
        fn_109_108A8(storage + 0x20DC, -1);
        fn_109_3E10(storage + 0x2038, -1);
        fn_109_3F44(storage + 0x2004, -1);
        fn_109_3FA0(storage + 0x1F90, -1);
        fn_109_10B34(storage + 0x1F5C, -1);
        fn_109_4014(storage + 0x1DF8, -1);
        fn_109_10B90(storage + 0x1D90, -1);
        fn_109_4080(storage + 0x1D84, -1);
        fn_109_10C3C(storage + 0x1D5C, -1);
        fn_109_10C98(storage + 0x1C00, -1);
        fn_109_40E0(storage + 0x129C, -1);
        fn_109_10D0C(storage + 0xEB0, -1);
        fn_109_4164(storage + 0xE4C, -1);
        fn_109_4230(storage + 0xE10, -1);
        fn_109_428C(storage + 0xD58, -1);
        fn_109_10DEC(storage + 0xB10, -1);
        fn_109_43E4(storage + 0x930, -1);
        fn_109_4450(storage + 0x900, -1);
        fn_109_4508(storage + 0x8F0, -1);
        fn_109_4548(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_109_10F68(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
