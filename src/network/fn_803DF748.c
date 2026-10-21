#pragma force_active on
int fn_803DE800(void*, void*, void*, void*, int, int);

int PFENT_ITER_GetEntryOfPath(void* iter, void* entry, void* vol, void* str, int unk) {
    return fn_803DE800(iter, entry, vol, str, 0, unk);
}
