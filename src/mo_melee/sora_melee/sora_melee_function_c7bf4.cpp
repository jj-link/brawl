#pragma force_active on
struct Data {
    int a;
    int b;
    short c;
    short d;
};

struct Entry {
    Data data;
    int pad[2];
};

struct Object {
    int header[3];
    Entry entries[1];
};

extern "C" int fn_27_C8388(Object*, int, int);

extern "C" void fn_27_C7BF4(Object* object, const Data* data) {
    int index = fn_27_C8388(object, -1, -1);
    if (index >= 0) {
        object->entries[index].data = *data;
    }
}
