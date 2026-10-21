#pragma force_active on
extern void fn_801E0704(void*);

void OSInitMutex(void* mutex) {
    fn_801E0704(mutex);
    *(int*)((char*)mutex + 8) = 0;
    *(int*)((char*)mutex + 0xC) = 0;
}
