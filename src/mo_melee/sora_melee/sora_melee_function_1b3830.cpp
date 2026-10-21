#pragma force_active on
struct Pair {
    unsigned int words[2];
};

struct Entry {
    Pair pair;
    float value;
    unsigned int flags;
};

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual Entry* at(int index);
};

extern "C" void fn_27_1B3830(Object* self, int sourceIndex, int destinationIndex) {
    Entry* source = self->at(sourceIndex);
    Entry* destination = self->at(destinationIndex);
    destination->pair = source->pair;
    destination->value = source->value;
    destination->flags = source->flags;
    reinterpret_cast<unsigned char*>(destination)[0xD] =
        reinterpret_cast<unsigned char*>(source)[0xD];
}
