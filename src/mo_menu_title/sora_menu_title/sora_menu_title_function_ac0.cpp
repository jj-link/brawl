#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern const char lbl_24_data_340[];
extern const char lbl_24_data_3E4[];
}

struct TitleMenuTask {
    char pad[0x3C];
    const char* data_ptr;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
};

extern "C" void* fn_24_AC0() {
    void* ptr = __nw__FUlQ25Heaps8HeapType(0x60, 0x2A);
    if (ptr) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(ptr, lbl_24_data_340, 8, 0xF, 8, true);
        TitleMenuTask* self = (TitleMenuTask*)ptr;
        self->data_ptr = lbl_24_data_3E4;
        self->field_40 = 0;
        self->field_44 = 0;
        self->field_48 = 0;
        self->field_4C = 0;
        self->field_50 = 0;
        self->field_58 = 0;
    }
    return ptr;
}
