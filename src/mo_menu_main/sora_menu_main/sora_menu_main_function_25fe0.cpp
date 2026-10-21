#pragma force_active on
typedef unsigned char u8;

struct Pad668 {
    u8 pad[0x668];
};

struct Obj : public Pad668 {
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_2_data_3030[];
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_2_25FE0(u8* self, int deleting) {
    if (self) {
        *reinterpret_cast<void**>(self + 0x668) = lbl_2_data_3030;

        u8* cursor = self;
        for (int i = 0; i < 4; ++i, cursor += 4) {
            Obj* obj = *reinterpret_cast<Obj**>(cursor + 0x680);
            if (obj) {
                obj->f0(1);
            }
        }

        if (self) {
            __destroy_arr(self + 0x48, fn_2_37C, 0xA8, 9);
        }

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
