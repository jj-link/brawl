#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_2164(void* self, short flag) {
    if (self != 0) {
        __dt__16acCmdInterpreterFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
