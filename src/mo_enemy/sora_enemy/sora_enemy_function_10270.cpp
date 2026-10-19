#pragma force_active on
class soModuleAccesser;
class soValueAccesser {
public:
    static float getValueFloat(soModuleAccesser* acc, unsigned long a, unsigned long b);
};
extern "C" void fn_27_5EC64(void* self, void* p2, float f);

struct FnObj {
    char pad[0x3C];
    soModuleAccesser* acc;
};

extern "C" void fn_41_10270(FnObj* self, void* p2, float f) {
    f = f * soValueAccesser::getValueFloat(self->acc, 0xbfa, 0);
    fn_27_5EC64(self, p2, f);
}
