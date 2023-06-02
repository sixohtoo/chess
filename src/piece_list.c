#include "piece_list.h"
#include "types.h"
#include <stdlib.h>

PieceNode initPieceNode(Piece piece);

PieceList initPieceList()
{
    PieceList list = malloc(sizeof(struct piece_list));
    list->head = NULL;
    return list;
}

PieceNode initPieceNode(Piece piece)
{
    PieceNode node = malloc(sizeof(struct piece_node));
    node->piece = piece;
    node->next = NULL;
    return node;
}

PieceList addPiece(PieceList list, Piece piece)
{
    PieceNode node = initPieceNode(piece);
    PieceNode curr = list->head;

    // If adding the first piece
    if (list->head == NULL)
    {
        list->head = node;
        return list;
    }

    // Add piece to end of list
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;
    return list;
}

PieceList removePiece(PieceList list, Piece piece)
{
    PieceNode curr = list->head;
    // No pieces on the board
    if (curr == NULL)
    {
        return list;
    }

    // Remove the first piece in list
    if (curr->piece == piece)
    {
        list->head = list->head->next;
        free(curr);
        return list;
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

void freePieceList(PieceList list)
{
    PieceNode temp;
    PieceNode curr = list->head;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(temp);
    free(list);
}
