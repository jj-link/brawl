#include <cstring>
#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
};

extern "C" {
extern char lbl_8059E5F8[4];
extern const float lbl_805A27F8;
}

extern "C" void fn_80108258(
    MuObject** objects, Entry* entries, int count, nw4r::g3d::ResFile* resFile)
{
    char buf[64];
    int n;
    int i;
    int j;
    Entry* entry = entries;
    MuObject* obj;

    for (i = 0; i < count; i++, entry++) {
        n = 1;
        if (entry->begin < entry->end)
            n = entry->end - entry->begin + 1;

        for (j = 0; j < n; j++) {
            obj = MuObject::create(
                resFile, entry->name, entry->kind, 0, Heaps::InfoInstance);
            const char* name = entry->name;
            objects[entry->begin + j] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_8059E5F8);
            obj->changeAnimN(buf);
            if (obj->m_modelAnim)
                obj->m_modelAnim->setUpdateRate(lbl_805A27F8);
        }
    }
}
