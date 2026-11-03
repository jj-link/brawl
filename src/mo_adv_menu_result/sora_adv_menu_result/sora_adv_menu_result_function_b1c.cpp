#include <mu/mu_object.h>
#include <string.h>
#pragma force_active on

struct Entry {
    const char* name;
    unsigned char first, last, argument, pad;
};
struct Owner {
    char pad[0x138];
    MuObject* objects[1];
};
extern "C" {
extern char lbl_34_data_5C[];
extern float lbl_34_rodata_38;
}
extern "C" void fn_34_B1C(Owner* self, Entry* entries, int count, nw4r::g3d::ResFile* resourceFile) {
    int num;
    int i = 0;
    int j;
    Entry* entry = entries;
    MuObject* object;
    const char* name;
    char animationName[0x40];
    while (i < count) {
        num = 1;
        if (entry->first < entry->last)
            num = entry->last - entry->first;
        j = 0;
        while (j < num) {
            object = MuObject::create(resourceFile, entry->name, entry->argument, 0, (HeapType)42);
            name = entry->name;
            self->objects[entry->first + j] = object;
            strcpy(animationName, name);
            strcat(animationName, lbl_34_data_5C);
            object->changeAnimN(animationName);
            if (object->m_modelAnim)
                object->m_modelAnim->setUpdateRate(lbl_34_rodata_38);
            ++j;
        }
        ++i;
        ++entry;
    }
}