#pragma force_active on
extern "C" {

void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_92_459C(void*, short);
void __dl__FPv(void*);

void* fn_92_12270(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x9C, -1);
        fn_27_21038(storage + 0x88, -1);
        fn_92_459C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

}
