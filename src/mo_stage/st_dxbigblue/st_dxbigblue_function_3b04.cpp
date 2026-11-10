#pragma force_active on
extern "C" const float lbl_81_rodata_0[];
struct Entry { unsigned char kind; char pad[3]; float x, y; char rest[0x28]; };
extern "C" int fn_81_3B04(void* self, float* out, float* pos, unsigned int mode) {
    Entry* entry;
    const float* c = lbl_81_rodata_0;
    if (!out) return 0;
    if (!pos) return 0;
    float x, half, scale, px, width, height, result;
    result = c[0];
    *out = result;
    for (unsigned int i = 0; i != 6;) {
        entry = (Entry*)((char*)self + i * 0x34 + 0xb00);
        if (entry->kind != 10) {
            switch (i) {
            case 4: width = c[32]; height = c[31]; break;
            default: ++i; continue;
            }
            scale = c[34];
            half = scale * width;
            x = entry->x;
            px = pos[0];
            if (px > x - half && px < x + half) {
                if (mode == 1) {
                    if (pos[1] > entry->y && result < entry->y)
                        result = entry->y + c[20] * height;
                } else {
                    if (pos[1] < entry->y && result < entry->y)
                        result = entry->y + c[20] * height;
                }
            }
        }
        ++i;
    }
    if (c[0] == result) return 0;
    *out = result;
    return 1;
}