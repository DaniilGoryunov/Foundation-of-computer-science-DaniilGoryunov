//Тип элемента списка: Беззнаковое целое. Вид списка: Кольцевой однонаправленный. Нестандартное действие: удалить элементы списка со значениями, находящимися в заданном диапазоне.
#include "headers/list.h"
#include "headers/iterator.h"
#include <stdio.h>

// delete elements in range from start to end (start <= n < end)
void delete_in_range(list* l, uint start, uint end) {
    iter it = iter_begin(l);
    bool is_first_deleted = false;
    do {
        if (!is_list_empty(l) && start <= iter_get_val(&it) && iter_get_val(&it) < end) {
            delete_el(&it);
            if (iter_eq(it, iter_begin(l))) {
                is_first_deleted = true;
            }
        } else {
            iter_inc(&it);
            is_first_deleted = false;
        }
    } while (!iter_eq(it, iter_begin(l)) || is_first_deleted);
}

int main() {
    list l = new_list();
    int n;
    printf("Enter number of elements in the list:\n");
    scanf("%d", &n);
    printf("Fill the list:\n");
    uint el;
    iter it = iter_begin(&l);
    for (int i = 0; i < n; i++) {
        scanf("%u", &el);
        add_el(&it, el);
        iter_inc(&it);
    }
    it = iter_begin(&l);
    printf("List:\n");
    print_list(&l);
    printf("Enter range (start, end):\n");
    uint start, end;
    scanf("%u", &start);
    scanf("%u", &end);
    delete_in_range(&l, start, end);
    printf("List:\n");
    print_list(&l);
    destroy_list(&l);

    return 0;
}