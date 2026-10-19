#include <types.h>
#pragma force_active on

extern "C" int fn_40_F8E0(char* self, unsigned int id, unsigned char* out);

struct fn_27_Self {
    u8 m_pad[0x54];
    char** m_list;
    u32 m_count;
};

extern "C" int fn_27_2333DC(fn_27_Self* self, u32 id, u8* out) {
    for (u32 i = 0; i < self->m_count; i++) {
        if (fn_40_F8E0(self->m_list[i], id, out)) {
            return 1;
        }
    }
    return 0;
}
