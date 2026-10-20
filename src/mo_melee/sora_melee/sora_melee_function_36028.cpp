#pragma force_active on
typedef unsigned int u32;

class WorkArray {
public:
    virtual void unused();
    virtual char* at(u32 index) const;
};

struct Work {
    char padding[8];
    WorkArray* array;
};

extern "C" void fn_8015C1EC(void*, unsigned short);

extern "C" void fn_27_36028(const Work* self, u32 value, u32 index) {
    char* entry = self->array->at(index);
    fn_8015C1EC(entry + 0x1C, (unsigned short)value);
}
