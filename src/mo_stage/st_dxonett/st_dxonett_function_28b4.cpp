#pragma force_active on
struct StObj;

extern "C" void fn_78_17D0(StObj* self, int arg);

extern "C" {
StObj* fn_78_28B4(StObj* self, int arg) {
    if (self != 0) {
        fn_78_17D0(self, 0);
        if (arg > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
