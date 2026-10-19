#include <stddef.h>
#pragma force_active on

typedef struct FamicomListNode
{
    struct FamicomListNode *next;
} FamicomListNode;

typedef struct FamicomList
{
    unsigned int count;
    FamicomListNode *head;
} FamicomList;

extern "C" void *fn_68_4008(void *unused, const FamicomList *fl, unsigned int n)
{
    unsigned int i;
    FamicomListNode *p;

    if (fl == NULL)
        return NULL;

    p = fl->head;
    for (i = 0; i != fl->count; i++)
    {
        if (i == n)
            return p;
        p = p->next;
    }

    return NULL;
}
