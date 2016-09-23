/******************************************************************************/
/* Important CSCI 402 usage information:                                      */
/*                                                                            */
/* This fils is part of CSCI 402 warmup programming assignments at USC.       */
/* Please understand that you are NOT permitted to distribute or publically   */
/*         display a copy of this file (or ANY PART of it) for any reason.    */
/* If anyone (including your prospective employer) asks you to post the code, */
/*         you must inform them that you do NOT have permissions to do so.    */
/* You are also NOT permitted to remove or alter this comment block.          */
/* If this comment block is removed or altered in a submitted file, 20 points */
/*         will be deducted.                                                  */
/******************************************************************************/

/*
 * Author:   Varunika Gupta
 *
 * @(#)$Id: listtest.c,v 1.1 2015/08/21 03:52:20 william Exp $
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#include "cs402.h"

#include "my402list.h"

int My402ListLength(My402List* list) {
    return list->num_members;
}

int My402ListEmpty(My402List* list) {
    if (list->next == NULL)
        return 1
    else
        return 0;
}

int My402ListAppend(My402List* list, void* obj) {

    /*    if ((list->anchor).next == NULL) {
            My402list *new = malloc(sizeof (My402list));
            (list->anchor).next = new;
            new->next = list->anchor;
            new->prev = list->anchor; */

    My402ListElem* newN = malloc(sizeof (My402listelem));
    if (list->anchor == NULL) {
        newN->obj = obj1;
        newN->prev = list->anchor;
        newN->next = list->anchor;
        (list->anchor).next = newN;
        (list->anchor).prev = newN;
        list->num_members++;
    } else {
        My402ListElem *temp = My402ListLast(list);
        newN->next = list->anchor;
        newN->prev = temp;
        temp->next = newN;
        (list->anchor).prev = newN;
        return 1;
    }
}

int My402ListPrepend(My402List *list, void *obj) {
    My402ListElem *newN = malloc(sizeof (My402listelem));
    if (list->anchor == NULL) {
        newN->obj = obj1;
        newN->prev = list->anchor;
        newN->next = list->anchor;
        (list->anchor).next = newN;
        (list->anchor).prev = newN;
    } else {
        My402ListElem *temp = My402ListFirst(list);
        newN->next = temp;
        newN->prev = list->anchor;
        temp->prev = newN;
        (list->anchor).next = newN;
        return 1;
    }
}

void My402ListUnlink(My402List *list, My402ListElem *e1) {
}

void My402ListUnlinkAll(My402List *list) {
}

int My402ListInsertAfter(My402List *list, void *pos, My402ListElem *e1) {
    return 0;
}

int My402ListInsertBefore(My402List* list, void* pos, My402ListElem * e1) {
    return 0;
}

My402ListElem* My402ListFirst(My402List *list) {
    if (list->anchor == NULL)
        return NULL;
    else
        return (list->anchor).next;
}

My402ListElem* My402ListLast(My402List *list) {
    if (list->anchor == NULL)
        return NULL;
    else
        return (list->anchor).prev;
}

My402ListElem* My402ListNext(My402List *list, My402ListElem *elem) {
    if ((list->anchor).prev==elem)
        return NULL;
    else
        return elem->next;
}

My402ListElem* My402ListPrev(My402List *list, My402ListElem *elem) {
    if ((list->anchor).next==elem)
        return NULL;
    else
        return elem->prev;
}

My402ListElem* My402ListFind(My402List *list, void *pos) {
    return NULL;
}

int My402ListInit(My402List * list) {
    (list->anchor).next = NULL;
    (list->anchor).prev = NULL;
    (list->anchor).obj = NULL;
    list->num_members = 0;

}
