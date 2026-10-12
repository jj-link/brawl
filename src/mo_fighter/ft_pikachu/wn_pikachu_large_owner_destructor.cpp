#include <so/so_module_accesser.h>

extern "C" {
void* fn_98_38F0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_98_398C(void*, short);
void* fn_98_3B58(void*, short);
void* fn_98_3BB4(void*, short);
void* fn_98_3C10(void*, short);
void* fn_98_3C6C(void*, short);
void* fn_27_93100(void*, short);
void* fn_98_3CF8(void*, short);
void* fn_98_4D60(void*, short);
void* fn_27_19F32C(void*, short);
void* fn_27_1A54AC(void*, short);
void* fn_98_3F10(void*, short);
void* fn_98_3FAC(void*, short);
void* fn_98_40E8(void*, short);
void* fn_98_43F8(void*, short);
void* fn_98_452C(void*, short);
void* fn_98_4588(void*, short);
void* fn_98_45E4(void*, short);
void* fn_98_4650(void*, short);
void* fn_98_46B0(void*, short);
void* fn_98_4710(void*, short);
void* fn_98_4E20(void*, short);
void* fn_98_476C(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4900(void*, short);
void* fn_98_4974(void*, short);
void* fn_98_4A74(void*, short);
void* fn_98_4AE0(void*, short);
void* fn_98_4B98(void*, short);
void* fn_98_4BD8(void*, short);
void* fn_98_4C34(void*, short);
void* fn_27_1D81C8(void*, short);
}

#pragma always_inline on
#pragma inline_depth(8)

// Each embedded aggregate keeps its own destructor's null guard.
static inline void destroyArticleArrays(char* arrays) {
    if (arrays) {
        if (arrays) {
            if (arrays + 4) {
                short deleting = -1;
                fn_98_3CF8(arrays + 0x64a4, deleting);
                if (arrays + 8) {
                    fn_98_3CF8(arrays + 0x4320, deleting);
                    if (arrays + 0xc) {
                        fn_98_3CF8(arrays + 0x219c, deleting);
                        if (arrays + 0x10) fn_98_3CF8(arrays + 0x18, deleting);
                    }
                }
            }
        }
    }
}

static inline void destroyArticleStorage(char* storage) {
    if (storage) {
        if (storage) {
            destroyArticleArrays(storage + 8);
            fn_98_4D60(storage, static_cast<short>(0));
        }
    }
}

static inline void destroyArticleModule(char* module) {
    if (module) {
        short deleting = -1;
        fn_27_93100(module + 0x869c, deleting);
        destroyArticleStorage(module + 0x68);
        fn_27_19F32C(module + 0x1c, deleting);
        fn_27_1A54AC(module, deleting);
    }
}

static inline void destroyModuleStorage(char* storage) {
    if (storage) {
        short deleting = -1;
        fn_98_3B58(storage + 0x9ee8, deleting);
        fn_98_3BB4(storage + 0x9ea8, deleting);
        fn_98_3C10(storage + 0x9e90, deleting);
        fn_98_3C6C(storage + 0x9cf4, deleting);
        destroyArticleModule(storage + 0x161c);
        if (storage + 0x15a8) fn_98_3F10(storage + 0x15f8, deleting);
        fn_98_3FAC(storage + 0x14f4, deleting);
        fn_98_40E8(storage + 0x1334, deleting);
        fn_98_43F8(storage + 0x1290, deleting);
        fn_98_452C(storage + 0x125c, deleting);
        fn_98_4588(storage + 0x1244, deleting);
        fn_98_45E4(storage + 0x10e0, deleting);
        fn_98_4650(storage + 0x1078, deleting);
        fn_98_46B0(storage + 0x106c, deleting);
        fn_98_4710(storage + 0x1044, deleting);
        fn_98_4E20(storage + 0xe74, deleting);
        fn_98_476C(storage + 0xe10, deleting);
        fn_98_4838(storage + 0xdd4, deleting);
        fn_98_4900(storage + 0xd1c, deleting);
        fn_98_4974(storage + 0xb10, deleting);
        fn_98_4A74(storage + 0x930, deleting);
        fn_98_4AE0(storage + 0x900, deleting);
        fn_98_4B98(storage + 0x8f0, deleting);
        fn_98_4BD8(storage + 0x8d8, deleting);
        reinterpret_cast<soModuleAccesser*>(storage + 0x7f8)->soModuleAccesser::~soModuleAccesser();
        fn_98_4C34(storage, deleting);
    }
}

static inline void destroyOwner(char* owner) {
    if (owner) {
        short deleting = -1;
        fn_98_38F0(owner + 0xa5b8, deleting);
        fn_27_1DBB60(owner + 0xa580, deleting);
        if (owner + 0xcc) {
            fn_98_398C(owner + 0x9fd0, deleting);
            destroyModuleStorage(owner + 0xcc);
        }
        fn_27_1D81C8(owner, static_cast<short>(0));
    }
}

extern "C" void* fn_98_3650(void* object, int deleting) {
    if (object) {
        destroyOwner(static_cast<char*>(object));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
