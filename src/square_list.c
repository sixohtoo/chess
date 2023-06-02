#include "types.h"
#include "square_list.h"
#include <stdlib.h>

SquareNode initSquareNode(Square square);

SquareList initSquareList()
{
    SquareList list = malloc(sizeof(struct square_list));
    list->head = NULL;
    return list;
}

SquareNode initSquareNode(Square square)
{
    SquareNode node = malloc(sizeof(struct square_node));
    node->square = square;
    node->next = NULL;
    return node;
}

SquareList addSquare(SquareList list, Square square)
{
    SquareNode node = initSquareNode(square);
    SquareNode curr = list->head;

    // If adding the first square
    if (list->head == NULL)
    {
        list->head = node;
        return list;
    }

    // Add square to end of list
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = node;
    return list;
}

SquareList removeSquare(SquareList list, Square square)
{
    SquareNode curr = list->head;

    // No squaress on the board
    if (curr == NULL)
    {
        return list;
    }

    // Remove the first squares in list
    if (curr->square == square)
    {
        list->head = list->head->next;
        free(curr);
        return list;
    }

    // Find square to remove
    while (curr->next != NULL && curr->next->square != square)
    {
        curr = curr->next;
    }

    if (curr->next != NULL)
    {
        SquareNode temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }

    return list;
}

void freeSquareList(SquareList list)
{
    SquareNode temp;
    SquareNode curr = list->head;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(temp);
    free(list);
}