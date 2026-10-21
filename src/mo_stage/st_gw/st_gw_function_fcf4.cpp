#include <types.h>
#pragma force_active on

extern "C" {
void fn_63_2C40(void* self, int flag);
void __dt__14snd3DGeneratorFv(void* self, int flags);
extern char lbl_63_data_4598[];
}

struct st_gw_obj {
    char pad_00[0x3C];
    void* m_3C;
    char pad_40[0x184 - 0x40];
    void* m_184;
    char m_188[0x4];
};

extern "C" {
st_gw_obj* fn_63_FCF4(st_gw_obj* self, int flag) {
    if (self) {
        void* p = self->m_184;
        self->m_3C = lbl_63_data_4598;
        if (p) {
            operator delete(p);
        }
        self->m_184 = 0;
        __dt__14snd3DGeneratorFv(&self->m_188, -1);
        fn_63_2C40(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
