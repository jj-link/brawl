#pragma force_active on
struct gfArchive;

struct Callback {
    void* object;
    unsigned long type;
    unsigned char padding[0x78];
};

struct Slider {
    unsigned char padding0[0xD4];
    Callback* callbacks;
    unsigned char padding1[0x88];
    void* object;
    unsigned long index;
};

extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(
    void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);

extern "C" void setCulcCallback__21grYakumonoPunchSliderFP9gfArchive(
    Slider* self, gfArchive*) {
    self->index = 1;
    if (self->object) {
        makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 2, 15);
        self->callbacks[self->index].object = self->object;
        self->callbacks[self->index].type = 6;
    } else {
        makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 15);
    }
    setCalcuCallbackRoot__9grGimmickFUl(self, 3);
}
