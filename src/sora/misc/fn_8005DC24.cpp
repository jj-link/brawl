#pragma force_active on
struct Entry { unsigned char pad0, active, pad2[2], priority, pad5[27]; };
struct Group { signed char pad, ids[16]; };
struct Object { Group groups[9]; char pad[3]; Entry entries[1]; };
extern "C" void fn_8005DCF8(Object*, Entry*);
extern "C" void fn_8005DC24(Object* obj, int group) {
    Group* g = &obj->groups[group];
    int max = -1;
    int best = -1;
    for (int i = 0; i < 16; i++) {
        Entry* entry;
        signed char* p = &g->ids[i];
        int id = *p;
        if (id != -1) {
            entry = &obj->entries[id];
            if (entry->active) {
                int priority = entry->priority;
                if (priority >= max) {
                    max = priority;
                    best = id;
                }
            } else {
                *p = -1;
            }
        }
    }
    if (best >= 0) fn_8005DCF8(obj, &obj->entries[best]);
}