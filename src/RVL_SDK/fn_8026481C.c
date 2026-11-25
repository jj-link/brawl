#include <types.h>

#pragma force_active on

typedef struct Ctx {
    char pad0[0xC];
    u16 unkC;
    char padE[2];
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u16 unk20;
    u16 transfer[3][0x100];
    u8 unk622[0x14];
    u16 unk636;
    u32 unk638;
    u8 unk63C[4];
    u8 unk640[4];
    u8 unk644[4];
    u16 unk648;
    char pad64A[2];
    u32 unk64C;
    u32 unk650;
    char pad654[0x674 - 0x654];
    u8 *base;
    u32 size;
} Ctx;

static inline u16 read16(u8 *p, u32 sw)
{
    u16 s;
    u32 x = (u32)p[0] | ((u32)p[1] << 8);

    s = ((x >> 8) & 0xFF) | ((x << 8) & 0xFF00);
    if (sw == 0x4949) {
        s = (u16)x;
    }
    return (u16)s;
}

static inline u32 read32(u8 *p, u32 sw)
{
    u32 s;
    u32 x = (u32)p[0] | ((u32)p[1] << 8) |
            ((u32)p[2] << 16) | ((u32)p[3] << 24);

    if (sw == 0x4949) {
        s = x;
    } else {
        s = x >> 24;
        s = (s & ~0xFF00UL) | ((x >> 8) & 0xFF00);
        s = (s & ~0xFF0000UL) | ((x << 8) & 0xFF0000);
        s = (s & ~0xFF000000UL) | (x << 24);
    }
    return s;
}

static inline void read32into(u32 *dst, u8 *p, u32 sw)
{
    *dst = read32(p, sw);
}

void fn_8026481C(Ctx *ctx, u32 sw, u8 *msg)
{
    u32 type;
    u16 sub;
    u8 *p;
    u32 off;
    u32 i;
    s32 j;

    {
        u16 x = (u16)(msg[0] | (msg[1] << 8));
        type = ((x >> 8) & 0xFF) | ((x << 8) & 0xFF00);
        if (sw == 0x4949) {
            type = (u16)x;
        }
        type = (u16)type;
    }
    sub = read16(msg + 2, sw);

    switch ((s32)type) {
    case 0x103:
        goto done;
    case 0x104:
    case 0x105:
        break;
    case 0x111:
        break;
    case 0x112:
        ctx->unkC = read16(msg + 8, sw);
    done:
        return;
    case 0x11A: {
        u32 address;
        off = read32(msg + 8, sw);
        address = (u32)ctx->base + off;
        if (address > ctx->size - 4) {
            break;
        }
        ctx->unk10 = read32(ctx->base + off, sw);
        }
        p = ctx->base;
        p += off + 4;
        if ((u32)p > ctx->size - 4) {
            break;
        }
        ctx->unk14 = read32(p, sw);
        break;
    case 0x11B: {
        u32 address;
        off = read32(msg + 8, sw);
        address = (u32)ctx->base + off;
        if (address > ctx->size - 4) {
            break;
        }
        ctx->unk18 = read32(ctx->base + off, sw);
        }
        p = ctx->base;
        p += off + 4;
        if ((u32)p > ctx->size - 4) {
            break;
        }
        ctx->unk1C = read32(p, sw);
        break;
    case 0x128:
        ctx->unk20 = read16(msg + 8, sw);
        break;
    case 0x12D:
        off = read32(msg + 8, sw);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 0x100; j++) {
                p = ctx->base + off;
                if ((u32)p > ctx->size - 2) {
                    break;
                }
                ctx->transfer[i][j] = read16(p, sw);
                off += 2;
            }
        }
        break;
    case 0x132:
        p = ctx->base;
        p += read32(msg + 8, sw);
        if ((u32)p > ctx->size - 0x14) {
            break;
        }
        ctx->unk622[0] = p[0];
        ctx->unk622[1] = p[1];
        ctx->unk622[2] = p[2];
        ctx->unk622[3] = p[3];
        ctx->unk622[4] = p[4];
        ctx->unk622[5] = p[5];
        ctx->unk622[6] = p[6];
        ctx->unk622[7] = p[7];
        ctx->unk622[8] = p[8];
        ctx->unk622[9] = p[9];
        ctx->unk622[10] = p[10];
        ctx->unk622[11] = p[11];
        ctx->unk622[12] = p[12];
        ctx->unk622[13] = p[13];
        ctx->unk622[14] = p[14];
        ctx->unk622[15] = p[15];
        ctx->unk622[16] = p[16];
        ctx->unk622[17] = p[17];
        ctx->unk622[18] = p[18];
        ctx->unk622[19] = p[19];
        break;
    case 0x201:
    case 0x202:
        break;
    case 0x213:
        ctx->unk636 = read16(msg + 8, sw);
        break;
    case 0x8769:
        ctx->unk638 = read32(msg + 8, sw);
        break;
    case 0x9000:
        ctx->unk63C[0] = msg[8];
        ctx->unk63C[1] = msg[9];
        ctx->unk63C[2] = msg[10];
        ctx->unk63C[3] = msg[11];
        break;
    case 0x9101:
        ctx->unk640[0] = msg[8];
        ctx->unk640[1] = msg[9];
        ctx->unk640[2] = msg[10];
        ctx->unk640[3] = msg[11];
        break;
    case 0xA000:
        ctx->unk644[0] = msg[8];
        ctx->unk644[1] = msg[9];
        ctx->unk644[2] = msg[10];
        ctx->unk644[3] = msg[11];
        break;
    case 0xA001:
        ctx->unk648 = read16(msg + 8, sw);
        break;
    case 0xA002:
        if (sub == 3) {
            ctx->unk64C = read16(msg + 8, sw);
        } else if (sub == 4) {
            ctx->unk64C = read32(msg + 8, sw);
        }
        break;
    case 0xA003:
        if (sub == 3) {
            ctx->unk650 = read16(msg + 8, sw);
        } else if (sub == 4) {
            ctx->unk650 = read32(msg + 8, sw);
        }
        break;
    default:
        break;
    }
}
