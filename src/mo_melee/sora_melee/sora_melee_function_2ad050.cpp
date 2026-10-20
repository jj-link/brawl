#pragma force_active on
typedef int s32;

struct Entry {
    s32 value;
    s32 unk4;
    s32 unk8;
};

class Object {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual s32 size();

    s32 unk4;
    s32 unk8;
    Entry entries[1];
};

extern "C" s32 fn_27_2AD39C(void* self, s32 a, s32 b);

extern "C" void fn_27_2AD050(Object* self, const s32* value) {
    s32 index = fn_27_2AD39C(self, self->size() - 1, -1);
    if (index >= 0) {
        self->entries[index].value = *value;
    }
}
