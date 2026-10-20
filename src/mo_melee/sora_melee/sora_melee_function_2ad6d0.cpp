#pragma force_active on
typedef int s32;

class Work {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual s32 size();
};

extern "C" s32 fn_27_2ADA28(void* self, s32 index, s32 value);

extern "C" void fn_27_2AD6D0(Work* self, const s32* value) {
    s32 index = fn_27_2ADA28(self, self->size() - 1, -1);
    if (index >= 0) {
        *(s32*)((char*)self + index * 12 + 16) = *value;
    }
}
