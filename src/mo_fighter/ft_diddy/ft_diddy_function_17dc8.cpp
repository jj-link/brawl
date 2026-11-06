#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_115_13378(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_115_18624(void*, int);
void* fn_115_1853C(void*, int);
void* fn_115_1845C(void*, int);
void* fn_115_183AC(void*, int);
void* fn_115_182C4(void*, int);
}

extern "C" void fn_115_17DC8(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_115_13378(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_18624(object + 0xE4, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_1853C(object + 0xA8, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_1845C(object + 0x68, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_183AC(object + 0x48, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_182C4(object + 8, i));
}
