#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_93_AD94(void* self, short flag) {
    if (self != 0) {
        __dt__21ftExtendParamAccesserFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
