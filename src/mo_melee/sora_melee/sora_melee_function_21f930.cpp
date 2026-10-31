#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

struct Obj {
    u8 pad0[0x138];
    u8 b138;
    u8 pad139[0x1F];
    u32 f158;
    u32 f15C;
    u32 f160;
    u32 f164;
};

struct RoData {
    f32 pad0[9];
    f32 f24;
    f32 pad28[8];
    f32 f48;
    f32 pad4c[2];
    f32 f54;
    f32 pad58[3];
    f32 f64;
    f32 pad68[1];
    f32 f6c;
    f32 f70;
    f32 f74;
    f32 f78;
};

extern "C" f32 randf__Fv();
extern "C" RoData lbl_27_rodata_3290;

extern "C" void fn_27_21F930(void** arg0, s8* arg1, u8* arg2, u8* arg3, s32 arg4)
{
    RoData* rd = &lbl_27_rodata_3290;
    u32 mask = 1u << arg4;

    Obj* a = (Obj*)*arg0;
    if ((a->f15C & mask) || (a->f164 & mask)) {
        *arg2 = 3;
    } else {
        *arg2 = 0;
    }

    if (((Obj*)*arg0)->f158 & mask || ((Obj*)*arg0)->f15C & mask) {
        switch (arg4) {
        case 4:
        case 5:
        case 6:
            if (randf__Fv() < rd->f6c) {
                *arg1 = (s8)(rd->f24 * randf__Fv());
            } else {
                *arg1 = (s8)(rd->f24 + rd->f70 * randf__Fv());
            }
            break;
        default:
            if (randf__Fv() < rd->f74) {
                *arg1 = (s8)(rd->f64 * randf__Fv());
            } else {
                *arg1 = (s8)(rd->f48 + rd->f78 * randf__Fv());
            }
            break;
        }

        if (((Obj*)*arg0)->f158 & mask && randf__Fv() < rd->f54) {
            *arg2 = 0;
        }
    } else if (((Obj*)*arg0)->f164 & mask) {
        *arg1 = *arg2 + 7;
    } else {
        *arg1 = 0;
    }

    if (arg3 != 0) {
        if (arg4 >= 0 && arg4 < 0x16) {
            *arg3 = ((char*)*arg0 + arg4)[0x138];
        } else {
            *arg3 = 0;
        }
    }
}
