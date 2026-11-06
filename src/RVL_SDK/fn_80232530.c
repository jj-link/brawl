#pragma force_active on
typedef struct Entry Entry;
struct Entry {
    void (*unused)(Entry *);
    void (*callback)(Entry *);
};

extern Entry *lbl_80529858[];

void fn_80232530(void)
{
    Entry **entry = lbl_80529858;
    int i = 0;
    do {
        Entry *object = *entry;
        if (object != 0) {
            void (*callback)(Entry *) = object->callback;
            if (callback != 0) {
                callback(object);
            }
        }
        ++i;
        ++entry;
    } while (i < 26);
}
