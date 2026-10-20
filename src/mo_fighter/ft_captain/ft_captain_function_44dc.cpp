#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3DEC(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_100_44DC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3DEC(storage + 0x6c, destroy);
        char* ptr = storage + 0x20;
        if (ptr != 0) {
            if (ptr != 0) {
                if (ptr != 0) {
                    fn_27_D2AA4(ptr, destroy);
                }
            }
        }
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
