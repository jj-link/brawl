#pragma force_active on

extern int fn_8038DDDC(void* p, int n);

int fn_8038E2B8(void* self)
{
    void* p = *(void**)((char*)self + 8);
    int count;
    void* next;

    if (*(int*)p == 0) {
        return 4;
    }

    count = *(int*)((char*)p + 12);
    if (count <= 0) {
        return 6;
    }

    next = *(void**)((char*)p + 8);
    if (next != 0) {
        return fn_8038DDDC(next, count);
    }

    return 5;
}
