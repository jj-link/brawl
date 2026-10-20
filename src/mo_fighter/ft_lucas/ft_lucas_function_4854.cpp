#pragma force_active on
extern "C" void* fn_114_4150(void*, short);
extern "C" void* fn_27_D2AA4(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_4854(void* object, short deleting) {
    if (object) {
        fn_114_4150((char*)object + 0x6c, -1);
        void* ptr = (void*)((char*)object + 0x20);
        if (ptr != 0) {
            if (ptr != 0) {
                if (ptr != 0) {
                    fn_27_D2AA4(ptr, -1);
                }
            }
        }
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
