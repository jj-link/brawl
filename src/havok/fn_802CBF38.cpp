#pragma force_active on

struct Self {
    int pad[0x1c24 / 4];
    unsigned int count;
    unsigned int ptr0;
    unsigned int ptr1;
    unsigned int ptr2;
};

struct SoHeapAllocator {
    virtual void vf0();
    virtual void dealloc(unsigned int);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" {
void fn_802CBF38(Self* self) {
    if (self->count != 0) {
        lbl_805A0EB8->dealloc(self->count);
        lbl_805A0EB8->dealloc(self->ptr0);
        lbl_805A0EB8->dealloc(self->ptr1);
        lbl_805A0EB8->dealloc(self->ptr2);
        self->count = 0;
        self->ptr0 = 0;
        self->ptr1 = 0;
        self->ptr2 = 0;
    }
}
}
