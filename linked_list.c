#include <assert.h>
#include "linked_list.h"

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    node->next = NULL;
    node->prev = NULL;

}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next != NULL;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->prev != NULL;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->prev;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    // TODO: Implement your solution here.
    int size = 1;
    struct ll_node *curr=head;
    while (ll_has_next(curr)) {
        curr = ll_next(curr);
        size++;
    }
    return size;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    while (ll_has_prev(list)) {
        list = ll_prev(list);
    }
    return list;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    while (ll_has_next(list)) {
        list = ll_next(list);
    }
    return list;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    size_t currInd = 0;
    while (node != NULL && currInd < index) {
        node = ll_next(node);
        currInd++;
    }
    return node;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
    if (existing->prev != NULL) {
        existing->prev->next = new;
    }
    new->prev = existing->prev;
    existing->prev = new;
    new->next = existing;
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
    new->next = existing->next;
    new->prev = existing;
    if (existing->next != NULL) {
        existing->next->prev = new;
    }
    existing->next = new;

}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *head = ll_head(list);
    ll_init(new);
    head->prev = new;
    new->next = head;
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *tail = ll_tail(list);
    ll_init(new);
    tail->next = new;
    new->prev = tail;
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}

struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    struct ll_node *min = list;
    while (list != NULL) {
        if (comparator(list, min) < 0) {
            min = list;
        }
        list = ll_next(list);
    }
    return min;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    struct ll_node *max = list;
    while (list != NULL) {
        if (comparator(list, max) > 0) {
            max = list;
        }
        list = ll_next(list);
    }
    return max;
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate) {
    assert(list != NULL);
    assert(predicate != NULL);
    // TODO: Implement your solution here.
    struct ll_node *temp_head = list;
    bool past = false;
    while (list != NULL) {
        if (!predicate(list)) {
            struct ll_node *temp = ll_next(list);
            if (!past) {
                temp_head = temp;
            }
            ll_remove(list);
            list = temp;
        }else{
            list = ll_next(list);
            past = true;
        }
    }
    return temp_head;
}
