#include "types.h"
#include "square_list.h"
#include <stdlib.h>

SquareNode initSquareNode(Square square);

// SquareList initSquareList()
// {
//     SquareList list = malloc(sizeof(struct square_list));
//     list->head = NULL;
//     return list;
// }

SquareNode initSquareNode(Square square)
{
    SquareNode node = malloc(sizeof(struct square_node));
    node->square = square;
    node->next = NULL;
    return node;
}

SquareNode addSquare(SquareNode list, Square square)
{
    SquareNode node = initSquareNode(square);
    SquareNode curr = list;

    // If adding the first square
    if (list == NULL)
    {
        // list->head = node;
        return node;
    }

    // Add square to end of list
    while (curr->next != NULL)
    {
        if (curr->square == square)
        {
            return list;
        }
        curr = curr->next;
    }

    curr->next = node;
    return list;
    // return list;
}

SquareNode removeSquare(SquareNode list, Square square)
{
    SquareNode curr = list;

    // No squaress on the board
    if (curr == NULL)
    {
        return list;
    }

    // Remove the first squares in list
    if (curr->square == square)
    {
        curr = curr->next;
        free(list);
        return curr;
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

SquareNode clearSquareList(SquareNode list)
{
    SquareNode temp;
    SquareNode curr = list;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    return NULL;
}

void freeSquareList(SquareNode list)
{
    clearSquareList(list);
}

int containsSquareList(SquareNode list, struct coord c)
{
    SquareNode curr = list;
    while (curr != NULL)
    {
        if (curr->square->row == c.x && curr->square->col == c.y)
        {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

SquareNode combineSquareList(SquareNode a, SquareNode b)
{
    if (a == NULL)
        return b;
    SquareNode curr = a;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = b;
    return a;
}