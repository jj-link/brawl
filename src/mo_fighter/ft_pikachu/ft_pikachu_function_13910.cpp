#pragma force_active on
void operator delete(void*);

// Destructor-only ABI declaration: storage belongs to the enclosing aggregate
// and the destructor implementation is provided by sora_melee.
class soCollisionAttackModuleImpl {
public:
    ~soCollisionAttackModuleImpl();
};

extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19CF10(void*, short);

extern "C" void* fn_98_13910(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        reinterpret_cast<soCollisionAttackModuleImpl*>(storage + 0x2d4)->~soCollisionAttackModuleImpl();
        fn_27_82AD4(storage + 0x2d0, memberDeleting);
        fn_27_4CAA0(storage + 0x24c, memberDeleting);
        fn_27_19CF10(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
