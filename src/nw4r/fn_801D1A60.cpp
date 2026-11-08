#pragma force_active on
extern "C" {
extern float lbl_805A3640;
void* fn_801B77F8();
float fn_801B7A50(void*);
void fn_801BA3B8(void*, float, float);
}
extern "C" void fn_801D1A60(void* self) {
    char* row;
    int offset;
    char* entry;
    int i, j;
    char* base = (char*)self;
    float scale = lbl_805A3640;
    scale *= *(float*)(base + 0x110);
    scale *= fn_801B7A50(fn_801B77F8());
    row = base;
    i = 0;
    offset = 0;
    while (i < *(int*)(base + 0xA0)) {
        entry = base + offset;
        j = 0;
        float v = scale * *(float*)(row + 0x2C);
        float a = v * *(float*)(base + 0x118);
        float b = v * *(float*)(base + 0x114);
        while (j < *(int*)(base + 0x9C)) {
            void* p = *(void**)(entry + 0xC);
            if (p) fn_801BA3B8(p, a, b);
            entry += 0x10;
            j++;
        }
        row += 0x1C;
        offset += 4;
        i++;
    }
}