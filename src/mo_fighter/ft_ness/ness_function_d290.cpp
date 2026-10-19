#pragma force_active on
struct NessPair { float x; float y; };

class NessVec2Source {
public:
    virtual void slot0();
    virtual void slot1();
    virtual NessPair get();
};

extern "C" {
extern const float lbl_101_rodata_8;
void fn_101_C2CC(void* destination, const void* source, float z);
}

extern "C" void fn_101_D290(void* self, NessVec2Source* source) {
    NessPair tmp = source->get();
    fn_101_C2CC(self, &tmp, lbl_101_rodata_8);
}
