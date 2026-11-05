#pragma force_active on
struct Data { unsigned int unused; unsigned int value; };
struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual Data** fn_27_7AC28(int);
    virtual int fn_27_7AB50();
};
struct Container {
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual Data** fn_27_7AC28(int);
    virtual int fn_27_7AB50();
};
struct Object { char pad[8]; Container array; };
struct Vec { char data[12]; };
extern "C" unsigned int fn_27_116DD4(const Data*, int, Vec*, unsigned int);
extern "C" int fn_27_1192A8(Object* self, int arg1, unsigned int* output, Vec* arg3, unsigned int arg4) {
    Vec* current;
    int count = 0;
    int size = self->array.fn_27_7AB50();
    current = arg3;
    for (int i = 0; i < size; i++) {
        unsigned int result;
        if (arg3)
            result = fn_27_116DD4(*self->array.fn_27_7AC28(i), arg1, current, arg4);
        else
            result = fn_27_116DD4(*self->array.fn_27_7AC28(i), arg1, 0, arg4);
        if (result == 1) {
            Data* data = *self->array.fn_27_7AC28(i);
            current++;
            count++;
            *output++ = data->value;
        }
    }
    return count;
}