#pragma force_active on
extern "C" {
void* fn_91_2C9C(void*, short);
void fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);

void* fn_91_65A4(void* object, short deleting) {
    if (object != 0) {
        fn_91_2C9C(static_cast<unsigned char*>(object) + 0x8c, static_cast<short>(-1));
        void* p = static_cast<char*>(object) + 0x20;
        if (p != 0) {
            if (p != 0) {
                if (p != 0) {
                    fn_27_1A1E70(p, static_cast<short>(-1));
                }
            }
        }
        fn_27_CD934(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
