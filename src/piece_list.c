#include "piece_list.h"
#include "types.h"
#include <stdlib.h>

PieceNode initPieceNode(Piece piece);

// PieceList initPieceList()
// {
//     PieceList list = malloc(sizeof(struct piece_list));
//     list->head = NULL;
//     return list;
// }

PieceNode initPieceNode(Piece piece)
{
    PieceNode node = malloc(sizeof(struct piece_node));
    node->piece = piece;
    node->next = NULL;
    return node;
}

PieceNode addPiece(PieceNode list, Piece piece)
{
    PieceNode node = initPieceNode(piece);
    PieceNode curr = list;

    // If adding the first piece
    if (list == NULL)
    {
        return node;
    }

    // Add piece to end of list
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;
    return list;
}

PieceNode removePiece(PieceNode list, Piece piece)
{
    PieceNode curr = list;
    // No pieces on the board
    if (curr == NULL)
    {
        return list;
    }

    // Remove the first piece in list
    if (curr->piece == piece)
    {
        curr = curr->next;
        free(list);
        return curr;
    }

    // Find piece to remove
    while (curr->next != NULL && curr->next->piece != piece)
    {
        curr = curr->next;
    }

    // If piece is found, remove it
    if (curr->next != NULL)
    {
        PieceNode temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }

    return list;
}

void freePieceList(PieceNode list)
{
    PieceNode temp;
    PieceNode curr = list;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}
