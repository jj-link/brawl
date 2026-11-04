#pragma force_active on
#pragma use_lmw_stmw on
struct Context { char pad[0x28]; int start; int end; };
struct Entry { signed char* name; char* ptr; };
struct List { Entry* data; int size; unsigned int capacity; };
extern "C" int fn_80331D00(int*, int*);
extern "C" signed char* fn_80331BF4(int, int*);
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_80331D14(Context* ctx, char* base, List* list) {
    char* data = base + ctx->start;
    int pos = 0;
    while (pos < ctx->end - ctx->start) {
        int offset = fn_80331D00((int*)data, &pos);
        if (offset == -1) break;
        signed char* name = fn_80331BF4((int)data, &pos);
        if (list->size == (int)(list->capacity & 0x3fffffff))
            fn_8027CE3C(list, 8);
        Entry* entry = &list->data[list->size++];
        entry->name = name;
        entry->ptr = base + offset;
    }
}