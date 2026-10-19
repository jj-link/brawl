#pragma force_active on
class grMadein {
public:
    ~grMadein();
};

extern "C" {
void __dl__FPv(void* p);
void __dt__8grMadeinFv(grMadein* self, int flags);

grMadein* fn_82_4110(grMadein* self, int flag) {
    if (self) {
        __dt__8grMadeinFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
