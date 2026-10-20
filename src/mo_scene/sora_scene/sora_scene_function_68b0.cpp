#pragma force_active on
struct Sub {
    void* unk0;
    void* unk4;
    void* unk8;
};

struct Obj {
    int unk0;
    int unk4;
    void* unk8;
    Sub* unkC;
};

extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
extern "C" void* getInstance__16CameraControllerFv();
extern "C" void changeInput__16CameraControllerFQ216CameraController4Kind(void* ctrl, int kind);

extern "C" void* fn_1_693C(void* self);
extern "C" void* fn_2_804C();
extern "C" void* fn_80052DB0();
extern "C" void* fn_2_6304(void* self, void* a, void* b, int c);

extern "C" void fn_1_68B0(Obj* self) {
    self->unkC = (Sub*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2A, 12);
    self->unk8 = fn_1_693C(self);
    self->unkC->unk8 = getInstance__16CameraControllerFv();
    changeInput__16CameraControllerFQ216CameraController4Kind(self->unkC->unk8, 0xA);
    self->unkC->unk0 = fn_2_804C();
    self->unkC->unk4 = fn_2_6304(self, self->unk8, fn_80052DB0(), 0);
}
