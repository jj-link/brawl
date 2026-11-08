#include <mu/mu_object.h>
#include <string.h>
#pragma force_active on

struct Entry {
    const char* name;
    unsigned char first, last, argument, pad;
};
struct Owner {
    char pad[0x40];
    MuObject* objects[1];
};
extern "C" {
extern char lbl_9_data_F4[];
extern float lbl_9_rodata_94;
}
extern "C" void fn_9_8E8(Owner* self, Entry* entries, int count, nw4r::g3d::ResFile* resourceFile) {
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
            strcat(animationName, lbl_9_data_F4);
            object->changeAnimN(animationName);
            if (object->m_modelAnim)
                object->m_modelAnim->setUpdateRate(lbl_9_rodata_94);
            ++j;
        }
        ++i;
        ++entry;
    }
}
