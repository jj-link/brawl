#include <types.h>
#pragma force_active on

struct Vec2f {
    f32 x;
    f32 y;

    Vec2f() {}
    Vec2f(const Vec2f& other) : x(other.x), y(other.y) {}
};

class PikminList {
public:
    virtual void v0();
    virtual Vec2f* at(int index);
    virtual void v2();
    virtual int count();
};

class PikminExtractor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec2f get();
};

struct PikminData {
    char pad[0xC];
    PikminExtractor* extractor;
};

struct PikminModule {
    char pad[0xD8];
    PikminData* data;
};

struct PikminObject {
    char pad0[0x60];
    PikminModule* module;
    char pad1[0x1FE28];
    PikminList list;
};

extern "C" void fn_113_B7F0(Vec2f* dst, const Vec2f* src);

inline PikminExtractor* getExtractor(PikminObject* self) {
    return self->module->data->extractor;
}

extern "C" void fn_113_BB50(PikminObject* self) {
    int count = self->list.count();
    PikminExtractor* extractor = getExtractor(self);
    Vec2f source = extractor->get();
    Vec2f value;
    fn_113_B7F0(&value, &source);

    for (int index = 0; index < count; ++index) {
        Vec2f* result = self->list.at(index);
        result->x = value.x;
        result->y = value.y;
    }
}
