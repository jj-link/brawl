#pragma force_active on
extern const unsigned char lbl_27_rodata_4610[];
struct Entry { int a; float b,c,d,e; };
struct Self { Entry* ptr; int count; };
extern "C" void fn_27_27F520(Self* self, Entry* entry, float x, float y) {
const float* k = (const float*)lbl_27_rodata_4610;
self->ptr = entry;
self->count = 1;
float t = k[2] * x;
float zero = k[0];
entry->a = 0;
entry->b = zero;
entry->c = y;
entry->d = zero;
entry->e = t + k[3];
}
