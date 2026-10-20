#pragma force_active on
struct Object;

struct Container {
    virtual void slot08();
    virtual Object* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" Object* fn_96_1F8B8(Object* dst, const Object* src);

extern "C" void fn_96_1E934(Container* self, int start,
                            const Object* source, unsigned int count) {
    int limit = static_cast<int>(count);

    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }

    for (count = 0; static_cast<int>(count) < limit; ++count) {
        fn_96_1F8B8(self->at(start + static_cast<int>(count)), source);
    }
}
