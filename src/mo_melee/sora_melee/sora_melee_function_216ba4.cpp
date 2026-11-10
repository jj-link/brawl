#include <types.h>
#include <so/controller/so_controller_impl.h>

#pragma force_active on

extern "C" void fn_27_1FAC54(void*, s32);
extern "C" s32 fn_27_20B63C(void*);
extern "C" f32 fn_27_20BC28(void*, s8*);
extern "C" f32 fn_27_20BCBC(void*, void*, f32);
extern "C" u32 fn_27_20E30C(void*, u32, u8*, u8*, u8*);
extern "C" f32 randf__Fv();
extern const f32 lbl_27_rodata_3000[];

extern "C" void fn_27_216BA4(void* self, f32* out, s32* buttons) {
    const f32* rodata = lbl_27_rodata_3000;
    char* p = (char*)self;
    s32 state = *(s32*)(p + 0xA8);

    switch (state) {
    case 0: {
        f32 val = fn_27_20BC28(
            *(void**)(p + 0x74),
            (s8*)((char*)*(void**)(p + 0x70) + 0x110));
        void* fighter = *(void**)(p + 0x74);
        void* target = *(void**)((char*)fighter + 0xBC);

        if (val > rodata[0]) {
            if ((*(s32*)((char*)target + 0x40) & 0x100) == 0) {
                if (!(*(f32*)((char*)target + 0x30) <
                      rodata[2] + *(f32*)((char*)target + 0x1C))) {
                    if ((*(s32*)((char*)target + 0x40) & 0x200) != 0 ||
                        (*(f32*)((char*)target + 0x34) <
                         rodata[2] + *(f32*)((char*)target + 0x24))) {
                        val = -val;
                    }
                }
            }
        } else {
            if ((*(s32*)((char*)target + 0x40) & 0x200) == 0) {
                if (!(*(f32*)((char*)target + 0x34) <
                      rodata[2] + *(f32*)((char*)target + 0x24))) {
                    if ((*(s32*)((char*)target + 0x40) & 0x100) != 0 ||
                        (*(f32*)((char*)target + 0x30) <
                         rodata[2] + *(f32*)((char*)target + 0x1C))) {
                        val = -val;
                    }
                }
            }
        }

        *(f32*)(p + 0xDC) = val;
        *(s32*)(p + 0x94) = 0x78;
        *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
    }
    case 1: {
        *out = *(f32*)(p + 0xDC);
        f32 a0 = *(f32*)((char*)*(void**)(p + 0x74) + 0xA0);

        if (a0 * *(f32*)(p + 0xDC) > rodata[0]) {
            f32 result = fn_27_20BCBC(
                *(void**)(p + 0x74),
                (char*)*(void**)(p + 0x74) + 0x5C,
                a0);
            if (result < rodata[21]) {
                if (randf__Fv() < rodata[43]) {
                    *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
                }
                return;
            }
        }

        if (*(s32*)((char*)*(void**)(p + 0x74) + 0xB4) == 0x65) {
            *(s32*)(p + 0xA8) = *(s32*)(p + 0xA8) + 1;
        }
        return;
    }
    default:
        if (*(u8*)((char*)*(void**)(p + 0x74) + 0x1BA) == 3) {
            *buttons |= soController::getButtonMask(soController::Pad_Button_Attack);
        } else if (fn_27_20B63C(*(void**)(p + 0x74)) != 0) {
            f32 r = randf__Fv();
            if (r < rodata[7]) {
                *(u16*)(p + 0x7E) = fn_27_20E30C(self, 0x6014, 0, 0, 0);
            } else if (r < rodata[12]) {
                *(u16*)(p + 0x7E) = fn_27_20E30C(self, 0x6011, 0, 0, 0);
            } else {
                *(u16*)(p + 0x7E) = fn_27_20E30C(self, 0x6015, 0, 0, 0);
            }

            switch (*(u16*)(p + 0x7E)) {
            case 0x603C:
            case 0x603D:
                *(u16*)(p + 0x7E) = 0x6035;
                break;
            }
        }

        u16 prev = *(u16*)(p + 0x78);
        if (prev != 0) {
            *(u16*)(p + 0x7C) = prev;
        }
        *(u16*)(p + 0x78) = 0;
        fn_27_1FAC54(*(void**)(p + 0x70), 0);
        break;
    }
}
