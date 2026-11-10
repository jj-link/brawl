#pragma force_active on
typedef struct Pad {
    unsigned short button;
    signed char stickX, stickY, substickX, substickY;
    unsigned char triggerL, triggerR, analogA, analogB;
} Pad;

void fn_80216474(void *unused, Pad *out, unsigned int *in)
{
    unsigned int first;
    out->button = 0;
    first = -((in[0] >> 23) & 1);
    out->button = first & 0x100;
    out->button = (-((in[0] >> 24) & 1) & 0x200) | (first & 0x100);
    out->button |= -((in[0] >> 21) & 1) & 0x400;
    out->button |= -((in[0] >> 20) & 1) & 0x800;
    out->button |= -((in[0] >> 25) & 1) & 0x1000;
    out->stickX = in[1] >> 16;
    out->stickY = in[1] >> 24;
    out->substickX = in[1];
    out->substickY = in[1] >> 8;
    out->triggerL = in[0] >> 8;
    out->triggerR = in[0];
    out->analogA = 0;
    out->analogB = 0;
    if (out->triggerL >= 0xAAU)
        out->button |= 0x40;
    if (out->triggerR >= 0xAAU)
        out->button |= 0x20;
    out->stickX -= 128;
    out->stickY -= 128;
    out->substickX -= 128;
    out->substickY -= 128;
}
