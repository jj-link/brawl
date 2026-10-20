#pragma force_active on
class WorkArray {
public:
    virtual ~WorkArray();
    virtual int size() const;
    virtual int& at(int index);
};

struct Object {
    char padding[0x297c];
    WorkArray array;
};

extern "C" int fn_27_28C800(Object* object) {
    return object->array.at(8);
}
