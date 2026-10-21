#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_11_data_688[];

void free__13gfHeapManagerFPv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_11_775C(u8* self, int deleting)
{
    if (self) {
        *reinterpret_cast<void**>(self + 0x3C) = lbl_11_data_688;

        u8* cursor = self;
        for (int i = 0; i < 9; ++i, cursor += 0x58) {
            void* heap = *reinterpret_cast<void**>(cursor + 0x80);
            if (heap) {
                free__13gfHeapManagerFPv(heap);
            }
        }

        cursor = self;
        for (int i = 0; i < 2; ++i, cursor += 0x10) {
            void* heap = *reinterpret_cast<void**>(cursor + 0x54);
            if (heap) {
                free__13gfHeapManagerFPv(heap);
            }
        }

        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
