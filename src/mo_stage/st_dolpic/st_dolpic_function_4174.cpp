#include <types.h>
#pragma force_active on

struct DolPic {
    u8 padding[0x6EC];
    void* entries[10];
    u8 padding2[0x30];
    u8 field_744;
    u8 field_745;
    u8 pad2[2];
    f32 field_748;
};

extern "C" void fn_80110B98(void*, u32, void*);
extern "C" void fn_8011097C(void*);
extern "C" void fn_801109AC(void*);
extern "C" f32 lbl_46_rodata_C8;

extern "C" void fn_46_4174(DolPic* self, u8 count, u32 mode) {
    if (count < 10) {
        switch (count) {
        case 0:
            for (u8 i = 0; i < 10; i++) {
                if (self->entries[i]) {
                    fn_80110B98(self->entries[i], mode, 0);
                    if (mode == 1)
                        fn_8011097C(self->entries[i]);
                    else
                        fn_801109AC(self->entries[i]);
                }
            }
            self->field_744 = 0;
            break;
        default:
            if (mode == 1) {
                if (self->entries[count]) {
                    fn_80110B98(self->entries[count], mode, 0);
                    if (self->field_745 == 0)
                        fn_8011097C(self->entries[count]);
                }
                self->field_744 = count;
            } else {
                self->field_745 = self->field_744;
                self->field_748 = 600.0f;
                self->field_744 = 0;
            }
            break;
        }
    }
}
