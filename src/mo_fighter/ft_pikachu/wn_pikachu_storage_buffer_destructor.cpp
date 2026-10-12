#include <so/so_module_accesser.h>
#include <so/collision/so_collision_attack_module_impl.h>

extern "C" {
void* fn_98_38F0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_98_398C(void*, short);
void* fn_98_3B58(void*, short);
void* fn_98_3BB4(void*, short);
void* fn_98_3C10(void*, short);
void* fn_98_3C6C(void*, short);
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
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CF10(void*, short);
void* fn_98_476C(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4894(void*, short);
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

static inline void destroyAttackStorage(char* storage) {
    if (storage) {
        short deleting = -1;
        reinterpret_cast<soCollisionAttackModuleImpl*>(storage + 0x2d4)->soCollisionAttackModuleImpl::~soCollisionAttackModuleImpl();
        fn_27_82AD4(storage + 0x2d0, deleting);
        fn_27_4CAA0(storage + 0x24c, deleting);
        fn_27_19CF10(storage, deleting);
    }
}

static inline void destroyModuleStorage(char* storage) {
    if (storage) {
        short deleting = -1;
        fn_98_3B58(storage + 0x1a68, deleting);
        fn_98_3BB4(storage + 0x1a28, deleting);
        fn_98_3C10(storage + 0x1a10, deleting);
        fn_98_3C6C(storage + 0x1874, deleting);
        if (storage + 0x17fc) fn_98_3F10(storage + 0x184c, deleting);
        fn_98_3FAC(storage + 0x1748, deleting);
        fn_98_40E8(storage + 0x1588, deleting);
        fn_98_43F8(storage + 0x14e4, deleting);
        fn_98_452C(storage + 0x14b0, deleting);
        fn_98_4588(storage + 0x1498, deleting);
        fn_98_45E4(storage + 0x1334, deleting);
        fn_98_4650(storage + 0x12cc, deleting);
        fn_98_46B0(storage + 0x12c0, deleting);
        fn_98_4710(storage + 0x1298, deleting);
        destroyAttackStorage(storage + 0xf18);
        fn_98_476C(storage + 0xeb4, deleting);
        fn_98_4838(storage + 0xe78, deleting);
        fn_98_4894(storage + 0xdd0, deleting);
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

// Preserve the null guards belonging to each embedded aggregate destructor.
static inline void destroyOwner(char* owner) {
    if (owner) {
        if (owner) {
            short deleting = -1;
            fn_98_38F0(owner + 0x2138, deleting);
            fn_27_1DBB60(owner + 0x2100, deleting);
            if (owner + 0xcc) {
                fn_98_398C(owner + 0x1b50, deleting);
                destroyModuleStorage(owner + 0xcc);
            }
            fn_27_1D81C8(owner, static_cast<short>(0));
        }
    }
}

extern "C" void* fn_98_3CF8(void* buffer, short deleting) {
    if (buffer) {
        destroyOwner(static_cast<char*>(buffer) + 4);
        if (deleting > 0) operator delete(buffer);
    }
    return buffer;
}
