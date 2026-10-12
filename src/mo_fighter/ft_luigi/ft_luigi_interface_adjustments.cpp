class soModuleAccesser;
class soArticle;

extern "C" void* fn_99_41E0(void*, int);
extern "C" bool fn_99_9964(void*, soModuleAccesser*, soArticle*);
extern "C" void* fn_99_31CC(void*, int);
extern "C" void* fn_99_18A4(void*, int);

// Adjustment entries forward the deletion word unchanged. The destinations
// interpret its signed low half when deciding whether to free the object.
extern "C" void* fn_99_BA70(void* object, int deleting) {
    return fn_99_41E0(static_cast<unsigned char*>(object) - 4, deleting);
}

extern "C" bool fn_99_BA78(void* object, soModuleAccesser* accesser,
                          soArticle* article) {
    return fn_99_9964(static_cast<unsigned char*>(object) - 4, accesser, article);
}

extern "C" void* fn_99_BA80(void* object, int deleting) {
    return fn_99_31CC(static_cast<unsigned char*>(object) - 4, deleting);
}

extern "C" void* fn_99_BA88(void* object, int deleting) {
    return fn_99_18A4(static_cast<unsigned char*>(object) - 0x40, deleting);
}
