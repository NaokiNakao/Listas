/* Estructura de datos de listas enlazadas */

#include <stdio.h>
#include <stdlib.h>

typedef struct Element // prototipo de lista
{
    int data;
    struct Element *next;
}Node;

// prototipos de funci�n

void push(Node** head_ref, int new_data);
void insertAfter(Node* prev_node, int new_data);
void append(Node** head_ref, int new_data);
void deleteKey(Node** head_ref, int key);
void deleteNode(Node** head_ref, int position);
int listLength(Node* head);
int searchKey(Node* head, int x);
void printList(Node* n);

int main()
{
    Node* list = NULL;

    append(&list, 6);
    push(&list, 7);
    push(&list, 1);
    append(&list, 4);
    insertAfter(list->next, 8);

    printList(list);

    //int a = 10;
    //printf("%d", searchKey(list, a));

    //printf("\nCantidad de nodos: %d", listLength(list));

    /*deleteNode(&list, 3);
    printf("\n\n");
    printList(list);*/

    /*deleteKey(&list, 6);
    printf("\n\n");
    printList(list);*/

    return 0;
}

/*
    Funci�n    : push
    Argumentos : Node** head_ref, int new_data
    Objetivo   : insertar un elemento al inicio de una lista
    Retorno    : ---
*/
void push(Node** head_ref, int new_data)
{
    Node* new_node; // crea un nuevo elemento
    new_node = (Node*)malloc(sizeof(Node)); // inicializa espacio de memoria en el nuevo elemento
    new_node->data = new_data; // asigna valor al elemento
    new_node->next = (*head_ref); // el nuevo nodo apunta al que previamente era cabeza (ahora es el primero)
    (*head_ref) = new_node; // la referencia de cabeza cambia al nuevo nodo

    return;
}

/*
    Funci�n    : insertAfter
    Argumentos : Node* prev_node, int new_data
    Objetivo   : insertar un elemento posterior a otro en una lista
    Retorno    : ---
*/
void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL) // compruena si el nodo es nulo
    {
        printf("\nEl nodo previo no puede ser nulo\n");
        return;
    }

    Node* new_node; // crea un nuevo nodo
    new_node = (Node*)malloc(sizeof(Node)); // inicia mememoria en el nuevo nodo
    new_node->data = new_data; // asigna un valor al nuevo nodo
    new_node->next = prev_node->next; // el nuevo nodo apunta al nodo que apuntaba el previo
    prev_node->next = new_node; // el nodo previo apunta al nuevo nodo

    return;
}

/*
    Funci�n    : append
    Argumentos : Node** head_ref, int new_data
    Objetivo   : insertar un elemento al final de una lista
    Retorno    : ---
*/
void append(Node** head_ref, int new_data)
{
    Node* new_node;
    Node* last;

    new_node = (Node*)malloc(sizeof(Node));
    last = (*head_ref);

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) // se inicializa en caso de que sea una lista vacia
    {
        (*head_ref) = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next; // iterando en cada nodo hasta llegar al �ltimo

    last->next = new_node; // el �ltimo nodo ahora apunta al nuevo elemento

    return;
}

/*
    Funci�n    : deleteKey
    Argumentos : Node** head_ref, int key
    Objetivo   : eliminar un dato en la lista
    Retorno    : ---
*/
void deleteKey(Node** head_ref, int key)
{
    Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) // comprueba si el nodo a eliminar es el primero
    {
        *head_ref = temp->next; // la cabeza ahora apunta al siguiente nodo
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) // se busca el elemento y se mantiene rastro del previo
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // el nodo no est� contenido

    prev->next = temp->next; // el nodo anterior ahora apunta al nodo que apuntaba el elemento quitado

    free(temp);

    return;
}

/*
    Funci�n    : deleteNode
    Argumentos : Node** head_ref, int position
    Objetivo   : eliminar elemento en una posici�n espec�fica
    Retorno    : ---
*/
void deleteNode(Node** head_ref, int position)
{
    if (*head_ref == NULL) return; // lista vac�a

    Node* temp = *head_ref; // almacenando nodo de referencia

    if (position == 0) // nodo a eliminar es el nodo de referencia (primer elemento en la lista)
    {
        *head_ref = temp->next; // cabeza apunta al segundo nodo en la lista
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position-1; i++) // busca el nodo anterior al nodo a eliminar
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return; // la posici�n es mayor a la cantidad de elementos en la lista

    Node* next = temp->next->next; // el nodo anterior apunta al nodo al cual apuntaba el nodo a eliminar
    free(temp->next);
    temp->next = next;

    return;
}

/*
    Funci�n    : listLength
    Argumentos : Node* head
    Objetivo   : encontrar la cantidad de elementos en una lista
    Retorno    : total
*/
int listLength(Node* head)
{
    int total = 0;

    Node* current = head;

    while (current != NULL)
    {
        current = current->next;
        total++;
    }

    return total;
}

/*
    Funci�n    : searchKey
    Argumentos : Node* head, int x
    Objetivo   : buscar un elemento en la lista
    Retorno    : (1) si el elmento se encuentra en la lista, (0) en caso contrario
*/
int searchKey(Node* head, int x)
{
   Node* current = head;

   while (current != NULL)
   {
      if (current->data == x) return 1;
      current = current->next;
   }

   return 0;
}

/*
    Funci�n    : printList
    Argumentos : Node* n
    Objetivo   : imprimir los elementos de una lista
    Retorno    : ---
*/
void printList(Node* n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }

    return;
}



















