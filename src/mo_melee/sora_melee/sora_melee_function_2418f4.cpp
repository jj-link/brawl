#include <types.h>
#pragma force_active on

extern "C" {
    void fn_27_23AAC4(void* self, const char* name);
    extern const char lbl_27_data_4DEC0[];
}

struct Data_4DED8 {
    char data[0x78];
};

extern "C" Data_4DED8 lbl_27_data_4DED8;

struct Obj {
    char pad[0x3c];
    void* m_3c;
    char pad2[0x8];
    s32 m_48;
    s32 m_4c;
    u32 m_50;
};

extern "C" Obj* fn_27_2418F4(Obj* self) {
    fn_27_23AAC4(self, lbl_27_data_4DEC0);
    self->m_3c = &lbl_27_data_4DED8;
    self->m_48 = -1;
    self->m_4c = -1;
    self->m_50 = 2;
    return self;
}
