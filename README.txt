# Arbol-de-Intervalos
Segundo trabajo práctico realizado para la materia Estructuras de Datos y Algoritmos, segundo año LCC.


gcc -c ./dlist.c 
gcc -o ejecutable dlist.c main.c

gcc -Wall -Werror itree.c

para balancear un arbol, hay que modificar el valor mas profundo que este
desbalanceado

factor de balance = altura derecha - altura izq


void
insertar (AVLTree ** t, int x)
{
if (es_vacio (*t))
*t = hacer (x, vacio (), vacio ()); /* altura actualizada
automáticamente */
else
{
if (x < raiz (*t))
insertar (&(*t)->izq, x);
else
insertar (&(*t)->der, x);
balancear (t);
actualizar_altura (*t);
}
}



/*/  Este es iterativo y sin terminar, vamos a ver si lo puedo hacer recursivo
iTree itree_insertar(iTree raiz, intervalo dato){
    intervalo* nuevoIntervalo = malloc(sizeof(intervalo));
    nuevoIntervalo->inicio = dato.inicio;
    nuevoIntervalo->final = dato.final;
    // se podra poner como nuevoIntervalo = dato ? Probar cuando el resto ande

    iTree nuevoNodo = itree_crear();
    nuevoNodo->intervalo = nuevoIntervalo;

    while(raiz != NULL){
        if(raiz->maximo < nuevoNodo->intervalo->final)
            raiz->maximo = nuevoNodo->intervalo->final;
        if((nuevoNodo->intervalo->inicio) < (raiz->intervalo->inicio)){
            raiz = raiz->izq;
        }
        else{
            raiz = raiz->der;
        }
    }
    raiz = nuevoNodo;
    //balancear
    //actualizar altura
    return raiz;
}/*/



void
actualizar_altura (AVLTree * t)
{
if(!es_vacio(t))
t->altura = max (altura ((t)->izq), altura ((t)->der)) + 1;
}