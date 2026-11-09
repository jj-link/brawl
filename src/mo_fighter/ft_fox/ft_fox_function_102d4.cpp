#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_97_4CC4(void*, short);
void* fn_97_3AD4(void*, short);
void* fn_97_3B30(void*, short);
void* fn_97_3BBC(void*, short);
void* fn_97_1043C(void*, short);
void* fn_97_3FC8(void*, short);
void* fn_97_40FC(void*, short);
void* fn_97_4158(void*, short);
void* fn_97_41B4(void*, short);
void* fn_97_4220(void*, short);
void* fn_97_4280(void*, short);
void* fn_97_42E0(void*, short);
void* fn_97_5648(void*, short);
void* fn_97_433C(void*, short);
void* fn_97_4408(void*, short);
void* fn_97_4464(void*, short);
void* fn_97_10590(void*, short);
void* fn_97_45BC(void*, short);
void* fn_97_4628(void*, short);
void* fn_97_46E0(void*, short);
void* fn_97_4720(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_97_4FA8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_97_102D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_4CC4(storage + 0x1714, -1);
        fn_97_3AD4(storage + 0x16F8, -1);
        fn_97_3B30(storage + 0x155C, -1);
        fn_97_3BBC(storage + 0x14FC, -1);
        fn_97_1043C(storage + 0x1334, -1);
        fn_97_3FC8(storage + 0x1290, -1);
        fn_97_40FC(storage + 0x125C, -1);
        fn_97_4158(storage + 0x1244, -1);
        fn_97_41B4(storage + 0x10E0, -1);
        fn_97_4220(storage + 0x1078, -1);
        fn_97_4280(storage + 0x106C, -1);
        fn_97_42E0(storage + 0x1044, -1);
        fn_97_5648(storage + 0xE74, -1);
        fn_97_433C(storage + 0xE10, -1);
        fn_97_4408(storage + 0xDD4, -1);
        fn_97_4464(storage + 0xD1C, -1);
        fn_97_10590(storage + 0xB10, -1);
        fn_97_45BC(storage + 0x930, -1);
        fn_97_4628(storage + 0x900, -1);
        fn_97_46E0(storage + 0x8F0, -1);
        fn_97_4720(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_97_4FA8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
