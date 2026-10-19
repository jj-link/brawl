#pragma force_active on
extern "C" void fn_41_5EEC4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5EF90(void* p1, int p2) {
    if (p1 == 0) goto done;
    if (p1 == 0) goto skip;
    fn_41_5EEC4((char*)p1 + 4, -1);
skip:
    if ((short)p2 > 0) {
        __dl__FPv(p1);
    }
done:
    return p1;
}
