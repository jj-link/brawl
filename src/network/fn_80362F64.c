#include <string.h>
#define _current_locale lbl_804942B8
#include <ctype.h>
#pragma force_active on

typedef struct {
    char *name;
    int nameLength;
    char *value;
    int valueLength;
    int index;
    int parent;
} XmlItem;

typedef struct {
    void *nodes;
    void *attributes;
} XmlParser;

extern char lbl_8059F5B0[5];

extern int fn_8035A590(void *);
extern void fn_8035A5C8(void *, void *);
extern void fn_8035AA08(void *, void *, int);
extern int fn_80363840(XmlParser *, char *, int, int *, XmlItem *);
extern int fn_80363A6C(XmlParser *, char *, int, int *, char **);
extern int fn_80363BDC(char *, int *);

static inline int skipSpace(const char *text, int length, int *position)
{
    while (*position < length) {
        if (strchr(lbl_8059F5B0, text[*position]) == 0)
            return 1;
        ++*position;
    }
    return 0;
}

static inline int IS_NAME_CHAR(int c)
{
    return (c < 0 || c >= 256) ? 0 :
        (*(unsigned short **)(_current_locale.cmap->UNK_0x0 + 8))[c] & 9;
}

int fn_80362F64(XmlParser *parser, char *text, int length,
                int *position, int parent)
{
    int current;
    XmlItem node;
    XmlItem attribute;
    int start = 0;
    int active = 1;
    int ok;
    int nameLength;
    char *value;
    int markerCode;
    char marker;

    skipSpace(text, length, position);
    if (*position >= length)
        return 1;

    memset(&node, 0, sizeof(node));
    if (text[*position] != '<')
        return 0;
    ++*position;
    if (*position >= length)
        return 0;

    if (!skipSpace(text, length, position))
        return 0;

    if (text[*position] == '!' || text[*position] == '?' ||
        text[*position] == '%' || text[*position] == '/') {
        active = 0;
        ++*position;
        start = *position - 2;
    } else {
        start = *position - 1;
    }

    if (!fn_80363840(parser, text, length, position, &node))
        return 0;

    if (!skipSpace(text, length, position))
        return 0;

    if (active) {
        node.index = fn_8035A590(parser->nodes);
        node.parent = parent;
        fn_8035A5C8(parser->nodes, &node);
    }

    while (*position < length && IS_NAME_CHAR(text[*position])) {
        memset(&attribute, 0, sizeof(attribute));
        if (!fn_80363840(parser, text, length, position, &attribute))
            return 0;

        if (!skipSpace(text, length, position))
            return 0;
        if (text[*position] != '=')
            return 0;
        ++*position;

        if (!fn_80363A6C(parser, text, length, position,
                         &attribute.value))
            return 0;

        if (!skipSpace(text, length, position))
            return 0;

        if (active) {
            attribute.index = fn_8035A590(parser->attributes);
            attribute.parent = node.index;
            fn_8035A5C8(parser->attributes, &attribute);
        }
    }

    if (!skipSpace(text, length, position))
        return 0;

    marker = text[start + 1];
    markerCode = marker;
    if (!IS_NAME_CHAR(markerCode)) {
        int delimiter = text[*position];

        if (delimiter == marker)
            goto finish_empty;
    }
    if (text[*position] == '/') {
    finish_empty:
        ++*position;
        if (!skipSpace(text, length, position))
            return 0;
        if (text[*position] != '>')
            return 0;
        ++*position;
        return 1;
    }

    if (text[*position] != '>')
        return 0;
    ++*position;

    if (!skipSpace(text, length, position))
        return 0;

    if (text[*position] != '<') {
        value = 0;
        if (!skipSpace(text, length, position)) {
            ok = 0;
            goto value_done;
        }

        {
            int next = (unsigned char)text[*position];

            if (next != '<') {
                value = text + *position;
                node.value = value;
            }
        }
        while (*position < length) {
            if (text[*position] == '<') {
                if (!fn_80363BDC(value, &node.valueLength)) {
                    ok = 0;
                    goto value_done;
                }
                ok = 1;
                goto value_done;
            }
            ++*position;
            ++node.valueLength;
        }
        ok = 0;
    value_done:
        if (!ok)
            return 0;

        if (active)
            fn_8035AA08(parser->nodes, &node, node.index);

        if (!skipSpace(text, length, position))
            return 0;
    }

    while (*position < length) {
        current = *position;
        if (text[*position] != '<')
            return 0;
        ++*position;

        if (!skipSpace(text, length, position))
            return 0;

        if (text[*position] == '/') {
            ++*position;
            if (!skipSpace(text, length, position))
                return 0;

            nameLength = node.nameLength;
            if (*position + nameLength >= length)
                return 0;
            if (strncmp(node.name, text + *position, nameLength) != 0)
                return 0;
            *position += nameLength;

            if (!skipSpace(text, length, position))
                return 0;
            if (text[*position] != '>')
                return 0;
            ++*position;
            return 1;
        }

        if (node.value != 0)
            return 0;

        *position = current;
        if (!fn_80362F64(parser, text, length, position, node.index))
            return 0;

        skipSpace(text, length, position);
    }
    return 0;
}
