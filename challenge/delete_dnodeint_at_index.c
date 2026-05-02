#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    temp = *head;

    /* حذف أول عنصر */
    if (index == 0)
    {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    /* الوصول للعنصر */
    i = 0;
    while (temp != NULL && i < index)
    {
        temp = temp->next;
        i++;
    }

    /* إذا ما وصلنا */
    if (temp == NULL)
        return (-1);

    /* إعادة الربط */
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return (1);
}
