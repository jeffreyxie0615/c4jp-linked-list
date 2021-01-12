#include <assert.h>
#include "student.h"

int compare(struct ll_node *first, struct ll_node *second) {
    double firstGPA = LL_ENTRY(first, struct student, node)->gpa;
    double secondGPA = LL_ENTRY(second, struct student, node)->gpa;
    if (firstGPA < secondGPA) {
        return -1;
    }else if (firstGPA == secondGPA) {
        return 0;
    }else {
        return 1;
    }
}

bool threshold (struct ll_node *curr) {
    if (LL_ENTRY(curr, struct student, node)->gpa < 3.5) {
        return false;
    }
    return true;
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *worst = ll_min(&list->node, compare);
    return LL_ENTRY(worst, struct student, node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *best = ll_max(&list->node, compare);
    return LL_ENTRY(best, struct student, node);
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *filtered = ll_filter(&list->node, threshold);
    if (filtered == NULL) {
        return NULL;
    }
    return LL_ENTRY(filtered, struct student, node);
}
