#include <iostream>
#include "stack.h"

static void showTowers(Stack* from, Stack* to, Stack* aux) {
    std::cout << "Tower 1: ";
    from->display();
    std::cout << "\nTower 2: ";
    to->display();
    std::cout << "\nTower 3: ";
    aux->display();
    std::cout <<"\n*************************************************************************\n";
}

void help(int n, Stack* from, Stack* to, Stack* aux) {
    if (n > 0) {
        help(n-1, from, aux, to);
        showTowers(from, to, aux);
        aux->push(from->pop());
        help(n-1, to, from, aux);
        showTowers(from, to, aux);
    }
}

void toh(int n) {
    auto *from = new Stack(), *to = new Stack(), *aux = new Stack();
    for (int i = n; i > 0; i--) from->push(new Disc(i));

    std::cout << "\nInitial stacks, each from top() to bottom:\n\n*************************************************************************\n";
    showTowers(from, to, aux);
    std::cout << "\nThe state of each stack_ will be printed after each move.\nThe last output is the final states of the stacks.\nThe corrected output is printed multiple times due to the recursive nature of the algorithm.\n\n*************************************************************************\n";
    help(n, from, to, aux);
    delete from;
    delete to;
    delete aux;
}

int main() {
    int n;
    std::cout<<"Enter the number of disks:";
    std::cin>>n;
    toh(n);
    return 0;
}
