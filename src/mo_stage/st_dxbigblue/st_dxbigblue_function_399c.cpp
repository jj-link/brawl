#pragma force_active on
extern "C" const float lbl_81_rodata_0[];
struct Entry { unsigned char kind; char pad[3]; float x, y; char rest[0x28]; };
extern "C" int fn_81_399C(void* self, float* out, float* pos, unsigned int mode) {
    const float* c = lbl_81_rodata_0;
    if (!out) return 0;
    if (!pos) return 0;
    float x, half, scale, px, width, height, result;
    result = c[0];
    Entry* entry = (Entry*)((char*)self + 0xb00);
    *out = result;

    for (int i = 0; i < 6; ++entry, ++i) {
        if (entry->kind != 10) {
            switch (i) {
            case 0: width = c[29]; height = c[30]; break;
            case 1: width = c[31]; height = c[30]; break;
            case 2: width = c[31]; height = c[30]; break;
            case 3: width = c[31]; height = c[30]; break;
            case 4: width = c[32]; height = c[31]; break;
            case 5: width = c[33]; height = width; break;
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
    }
    if (c[0] == result) return 0;
    *out = result;
    return 1;
}