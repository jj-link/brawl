#pragma force_active on
extern "C" int fn_801AF924(void* self, int arg);

extern "C" int fn_801B3298(char* self, int arg) {
    if (arg == 5) {
        return *(int*)(self + 0x138);
    }
    return fn_801AF924(self, arg);
}
