#pragma force_active on
extern "C" void __dl__FPv(void* p);

class ftIkeEmpty {
public:
    ~ftIkeEmpty() {}
};

extern "C" {
void* fn_119_1DD0(ftIkeEmpty* self, short flag) {
    if (self != 0 && flag > 0) {
        __dl__FPv(self);
    }
    return self;
}
}
