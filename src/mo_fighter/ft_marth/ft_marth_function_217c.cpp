#pragma force_active on
extern "C" {
void* __dt__16acCmdInterpreterFv(void* self, short destroyFlag);
void __dl__FPv(void* p);

void* fn_106_217C(void* self, short flag) {
    if (self != 0) {
        __dt__16acCmdInterpreterFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
