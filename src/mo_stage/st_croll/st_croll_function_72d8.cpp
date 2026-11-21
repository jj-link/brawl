#pragma force_active on
#pragma fp_contract off

extern "C" {
extern char lbl_90_data_0[];
extern int lbl_90_data_2A64[];
extern const float lbl_90_rodata_0, lbl_90_rodata_24, lbl_90_rodata_30;
extern const float lbl_90_rodata_94, lbl_90_rodata_C4, lbl_90_rodata_124;

void fn_90_77D8(void*);
void fn_90_7878(void*);
void fn_90_8230(void*);
void fn_90_77FC(void*, int);
int fn_90_7950(unsigned int);
int fn_90_7970(int, int**);
int fn_90_79F0(int, int, const int*);
int fn_90_726C(void*, int, int);
int fn_90_6C18(void*, char*, int, int);
int fn_8018D3F0(void*, char*);
int fn_8018D310(void*, char*);
void fn_90_12E8(int*, const int*);
int fn_90_7258(int*);
int fn_90_12F4(int*);
void fn_90_7A34(int*, int);
void fn_90_8300(int*, int*);
void fn_90_7A3C(void*, int, int, int, int, int*, int*);
void fn_90_7C44(void*, void*, int, int, unsigned int);
void fn_90_7E5C(void*, int, int, void*, void*, float);
}

struct State {
    unsigned int a, b;
    float c, d, e, f;
};

struct Category {
    int columns;
    float x, y, spacing, scale1, scale2;
};

struct Names {
    int count;
    int* entries;
};

struct Entry {
    char data[0x44];
};

struct Text {
    char data[0x54];
};

struct Item {
    char data[0xf4];
};

struct Object {
    char pad[0x1d8];
    char manager[0x10c];
    float top, bottom, right;
    float section[5];
    float end;
    char pad3[0xc];
    int count;
    char pad4[8];
    unsigned int ids[1];
};

extern "C" void fn_90_72D8(Object* obj, Entry* entries, Text* texts, Item* items)
{
        Text* text;
    Item* item;
    char* base = lbl_90_data_0;
    State state;
    int list[8];
    char buffer[64];
    int* group;
    int h, alt, raw, raw2;

    fn_90_77D8(&state);
    fn_90_7878(&state);

    int* dst;
    int count = obj->count;
    int used = 0;
    int i = 0;
    for (; i < count; ++i) {
        int id = fn_90_7950(obj->ids[i]);
        group = 0;
        int n = fn_90_7970(id, &group);
        if (fn_90_79F0(id, used, list))
            list[used++] = id;
        if (n > 1 && group) {
            dst = list + used;
            for (int j = 0; j < n; ++j) {
                int id2 = group[j];
                if (id2 != id && fn_90_79F0(id2, used, list)) {
                    *dst++ = id2;
                    ++used;
                }
            }
        }
    }

    float y = lbl_90_rodata_0;
    float start = y;
    obj->top = y;
    obj->right = lbl_90_rodata_24 + y;

    int total = 0;
    int category = 0;
    Category* categories = (Category*)(base + 0x2690);
    Names* names = (Names*)(base + 0x2600);
    int* headers = (int*)(base + 0x50);

    for (; category < 5; ++category) {
        obj->section[category] = y;
        y -= lbl_90_rodata_C4;
        if (category == 0) {
            start = y;
            y -= lbl_90_rodata_24 + lbl_90_rodata_124 * (float)used;
        }

        int max = lbl_90_data_2A64[category];
        int shown = 0;
        int columns = categories[category].columns;
        float spacing = categories[category].spacing;
        text = texts + total;
        item = items + total;

        for (int index = 0; index < max; ++index) {
            if (fn_90_726C(obj, category, index)) {
                fn_90_6C18(obj, buffer, category, index);
                raw = fn_8018D3F0(obj->manager, buffer);
                fn_90_12E8(&h, &raw);
                if (fn_90_7258(&h)) {
                    fn_90_7A34(&alt, 0);
                    if (fn_90_12F4(&h)) {
                        raw2 = fn_8018D310(obj->manager, buffer);
                        fn_90_8300(&alt, &raw2);
                    }

                    fn_90_7A3C(entries, category, index, shown,
                               category <= 2, &h, &alt);
                    fn_90_7C44(text, &state, names[category].entries[index],
                               category, -1);

                    float position = y;
                    int rowIndex = shown;
                    if (category == 0) {
                        int k = 0;
                        int before = 0;
                        for (; k < used; ++k) {
                            if (index == list[k])
                                break;
                            if (index > list[k])
                                ++before;
                        }
                        if (k < used) {
                            rowIndex = -1;
                            position = start - lbl_90_rodata_124 * (float)k;
                        } else {
                            rowIndex = shown - before;
                        }
                    }

                    if (columns - 1 == rowIndex % columns || index == max - 1)
                        y -= spacing;

                    fn_90_7E5C(item, category, rowIndex, entries, text, position);
                    ++shown;
                    ++entries;
                    ++text;
                    ++item;
                    ++total;
                }
            }
        }

        if (shown > 0) {
            float position = obj->section[category] - lbl_90_rodata_94;
            Text* text = texts + total;
            fn_90_7C44(text, &state, headers[category], category, 0xD00000FF);
            fn_90_7E5C(items + total, category, -2, 0, text, position);
            ++total;
        } else {
            y = obj->section[category] - lbl_90_rodata_30;
        }
    }

    obj->bottom = y;
    obj->end = y;
    fn_90_8230(&state);
    fn_90_77FC(&state, -1);
}
