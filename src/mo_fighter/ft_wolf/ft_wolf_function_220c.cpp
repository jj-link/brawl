#pragma force_active on
class acCmdInterpreter;

extern "C" {
void* __dt__16acCmdInterpreterFv(void* self, short flag);
void __dl__FPv(void* p);
void* fn_125_220C(acCmdInterpreter* self, short flag);
}

void* fn_125_220C(acCmdInterpreter* self, short flag) {
    if (self != 0) {
        __dt__16acCmdInterpreterFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
