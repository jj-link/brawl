#pragma force_active on
extern "C" int fn_27_8C024(void*, void*, int, int);
extern "C" unsigned int fn_41_A8F4(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];

extern "C" unsigned int fn_41_2240C(void* self, void* acc, int param, int extra) {
    if (param <= 40999) {
        return fn_27_8C024(self, acc, param, extra);
    }

    switch (param) {
    case 41000:
        return fn_41_A8F4(__dynamic_cast(
            *(void**)((char*)acc + 8),
            0x3C,
            __RTTI__5Enemy,
            __RTTI__11StageObject,
            1));
    default:
        return 0;
    }
}
