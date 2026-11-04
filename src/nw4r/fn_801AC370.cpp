#pragma force_active on
extern "C" {
extern char lbl_804662E8[];
void* fn_80204E5C(void*, int);
void* fn_801ACF68(void*, void*, void*, void*, int, int, int, void*, void*, void*);
}
struct Sub { void* vtable; void* first; void* second; int count; int zero1; int zero2; };
extern "C" void* fn_801AC370(void* allocator, int* size, int a, int b, int c, int d)
{
    int off1 = (a * 4 + 0x28a7) & ~3;
    int off2 = (off1 + (b * 4) * 2 + 3) & ~3;
    int off3 = (off2 + c * 0x44 + 3) & ~3;
    int off4 = (off3 + c * 4 + 3) & ~3;
    int total = (off4 + d * 0xc + 3) & ~3;
    int b4 = b * 4;
    void* result = 0;
    if (size) *size = total;
    if (allocator) {
        char* mem = (char*)fn_80204E5C(allocator, total);
        if (!mem) return 0;
        Sub* sub = (Sub*)(mem + 0x288c);
        char* first = mem + off1;
        if (sub) {
            sub->vtable = lbl_804662E8;
            sub->first = first;
            sub->second = first + b4;
            sub->count = b;
            sub->zero1 = 0;
            sub->zero2 = 0;
        }
        result = mem;
        char* p2 = mem + off2;
        char* p3 = mem + off3;
        char* p4 = mem + off4;
        if (mem)
            result = fn_801ACF68(mem, allocator, sub, mem + 0x28a4, a, c, d, p2, p3, p4);
    }
    return result;
}