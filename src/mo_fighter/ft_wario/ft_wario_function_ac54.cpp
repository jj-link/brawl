#pragma force_active on
extern "C" void* fn_110_AB94(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_AC54(void* object, short deleting) {
    if (object == 0) {
        goto done;
    }

    if (object != 0) {
        fn_110_AB94(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }

    if (deleting <= 0) {
        goto done;
    }

    __dl__FPv(object);

done:
    return object;
}
