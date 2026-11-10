#pragma force_active on
extern float lbl_805A3E70;
struct Entry {
    unsigned char type; unsigned char pad01[15];
    float f10, f14, f18, f1C;
    unsigned char pad20[32];
    float f40, f44, f48, f4C;
    float f50, f54, f58, f5C;
    unsigned char pad60[32];
};
extern "C" void fn_8029E8B0(int, const float* vec, Entry* entry)
{
    float v = lbl_805A3E70;
    for (;;) {
        switch ((int)entry->type) {
        case 1:
            entry->f4C=v; entry->f48=v; entry->f44=v; entry->f40=v;
            entry->f5C=v; entry->f58=v; entry->f54=v; entry->f50=v;
            ++entry;
            break;
        case 0:
            do {
                entry->f4C=v; entry->f48=v; entry->f44=v; entry->f40=v;
                entry->f5C=v; entry->f58=v; entry->f54=v; entry->f50=v;
                entry->f10 += vec[0];
                entry->f14 += vec[1];
                entry->f18 += vec[2];
                entry->f1C += vec[3];
                ++entry;
                signed char b = (unsigned char)(entry->type == 0);
                if (((unsigned int)(-b | b) >> 31) == 0) break;
            } while (true);
            break;
        case 2: return;
        default: *(int*)0=0; break;
        }
    }
}