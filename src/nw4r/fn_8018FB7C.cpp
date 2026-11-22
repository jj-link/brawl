#pragma force_active on
struct Handle { void* base; };
extern "C" int fn_8018F128(void** p, short idx);
extern "C" int fn_8018FB7C(Handle self, int arg)
{
    void* base = self.base;
    char* p = (char*)base + (arg << 1);
    if (*(short*)(p + 0x4c) != -1) {
        int off = *(int*)((char*)base + 4);
        void* data = off ? (void*)((char*)base + off) : (void*)0;
        return fn_8018F128(&data, *(short*)(p + 0x4c));
    }
    return 0;
}
